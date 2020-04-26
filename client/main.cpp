#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "chatworker.h"
#include "chatmodel.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    boost::asio::io_context io_context;

    tcp::resolver resolver(io_context);
    boost::asio::ip::tcp::endpoint epoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234);
    auto endpoints = resolver.resolve(epoint);

    ChatModel *model = new ChatModel();
    ChatWorker *worker = new ChatWorker();

    engine.rootContext()->setContextProperty("clientmodel", model);
    engine.rootContext()->setContextProperty("clientworker", worker);

    worker->startWorker(io_context, endpoints);
    std::thread t([&io_context](){ io_context.run(); });
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
    worker->stopWorker();
    t.join();
}
