import QtQuick 2.9
//import QtQuick.Controls 2.3
import QtQuick.Templates 2.1 as T

T.Button {
    id: control

    font.family: "arial"
    font.bold: true
    font.pixelSize: 20

    leftPadding: 4
    rightPadding: 4

    background: Rectangle {
        id: buttonBackground
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        border.color: "black"
        border.width: 1
        radius: 4

        states: [
            State {
                name: "normal"
                when: !control.down
                PropertyChanges {
                    target: buttonBackground
                    color: "#28a745"
                    //border.color: "black"
                }
            },
            State {
                name: "down"
                when: control.down
                PropertyChanges {
                    target: buttonBackground
                    //border.color: Qt.darker(border.color)
                    //border.color: "black"
                    color: Qt.darker("#28a745")
                }
            }
        ]
    }

    contentItem: Text {
        id: textItem
        text: control.text

        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: "white"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight

        states: [
            State {
                name: "normal"
                when: !control.down
            },
            State {
                name: "down"
                when: control.down
                PropertyChanges {
                    target: textItem
                    //color: Qt.darker(color, 15)
                }
            }
        ]
    }
}

























/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
