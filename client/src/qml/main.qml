import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    ScrollView {
        height: parent.height - 50
        width: parent.width

        ListView {
            id: listview1
            width: parent.width
            model: clientmodel
            delegate: ItemDelegate {
                text: message_
                width: parent.width
            }
        }
    }

    Row {
        y: listview1.height + 5
        height: 40
        width: parent.width

        TextField {
            id: textfield1
            text: "Введите текст"
            width: parent.width / 2
        }

        Button {
            text: "Send"
            anchors.right: parent.right

            onClicked: {
                clientworker.sendToServer(textfield1.text.toString());
            }
        }
    }

    ListModel {
        id: test_model

        ListElement { messager: "Message1"; }
        ListElement { messager: "Message2"; }
        ListElement { messager: "Message3"; }
        ListElement { messager: "Message4"; }
        ListElement { messager: "Message5"; }
        ListElement { messager: "Message6"; }
    }
}
