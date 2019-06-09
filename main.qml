import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4 as QQC1
import MyModel 1.0

Window {
    visible: true
    width: 1024
    height: 768
    title: qsTr("Hello World")

    CustomModel {
        id: myModel
    }

    Timer {
        id: timer
        repeat: true
        interval: 2000
        onTriggered: {
            console.log("trigged")
            myModel.append()
        }

        Component.onCompleted: timer.start()
    }

    Item {
        anchors.fill: parent;

        ListView {
            id: listView
            width: parent.width
            height: parent.height / 2
            anchors.left: parent.left
            anchors.top: parent.top
            model: myModel
            delegate: Row {
                width: parent.width
                height: 30
                spacing: 5

                Text {
                    width: 50;
                    height: parent.height
                    text: age
                    horizontalAlignment: Text.AlignHCenter
                }
                Text {
                    width: 100;
                    height: parent.height
                    text: name
                }
                Text {
                    width: 100;
                    height: parent.height
                    text: address
                }
                Text {
                    width: 50;
                    height: parent.height
                    text: sex
                }
            }
        }

        QQC1.TableView {
            id: tableView
            width: parent.width
            height: parent.height / 2
            anchors.left: parent.left
            anchors.top: listView.bottom
            model: myModel;

            QQC1.TableViewColumn {
                width: 50;
                title: "Age"
                role: "age"
            }
            QQC1.TableViewColumn {
                width: 100;
                title: "Name"
                role: "name"
            }
            QQC1.TableViewColumn {
                width: 100;
                title: "Address"
                role: "address"
            }
            QQC1.TableViewColumn {
                width: 50;
                title: "Sex"
                role: "sex"
            }
        }
    }
}
