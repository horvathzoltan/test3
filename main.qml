import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Window {
    id: wnd1
    visible: true
    width: 800
    height: 480
    title: qsTr("Hello World")
    color: "#e0e0e0"


    Button {
        id: button
        x: 544
        width: 300
        height: 60
        text: qsTr("GetNew")
        spacing: 5
        wheelEnabled: false
        anchors.top: parent.top
        anchors.topMargin: 30
        anchors.right: parent.right
        anchors.rightMargin: 35

        onClicked: { enabled=false; var a = _test1.doWork("pitty"); text1.text=a; enabled=true; }
    }

    Text {
        id: text1
        objectName: text1name
        x: 179
        y: 360
        width: 432
        height: 52
        text: qsTr("Text")
        font.pixelSize: 20
    }

    GridLayout {
        id: gridLayout
        x: 465
        y: 104
        width: 300
        height: 322
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 54
        anchors.right: parent.right
        anchors.rightMargin: 35
        columnSpacing: 4
        rowSpacing: 4
        rows: 4
        columns: 3

        Repeater{
            model: [1,2,3,4,5,6,7,8,9,0]
            Button {
                text: modelData
                Layout.fillHeight: true
                Layout.fillWidth: true

                Layout.columnSpan: (modelData==0)?3:1
            }
        }

    }

    TextEdit {
        id: textEdit
        x: 237
        y: 222
        width: 236
        height: 95
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }

    TextEdit {
        id: textEdit1
        x: 237
        y: 85
        width: 222
        height: 95
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }


}

































