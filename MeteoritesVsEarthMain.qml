import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Window 2.0

import MiseaJour.Score 1.0

import "page"
import "composants"
import "js/logique.js" as Logique


//Fichier main principale
ApplicationWindow {
    property var tGame

    id: main
    visible: true
    title: qsTr("MeteoritesVsEarth")
    //    contentOrientation: Qt.PortraitOrienation
    //color: "#A05A2C"
    property int orientation: Screen.orientation
    Screen.orientationUpdateMask: Qt.PortraitOrientation

    MyStackView {
        id: stack
    }

    ListModel {
        id: modelMeteorite1 // Meteorites avec 1 ierre
    }
    ListModel {
        id: modelMeteorite2 //Meteorites avec 2 pierre
    }
    ListModel {
        id: modelMeteorite3 //Meteorites avec 3 pierres
    }

    ListModel {
        id: eau // ajout d'eau
    }
    ListModel {
        id: etoile //ajout etoile
    }
    ListModel {
        id: diamant //ajout diamant
    }

    ScoreJour {
        id: miseajourscore
    }


    //Main's functions
    function popPage() {
        stack.pop()
    }
    function launchPage(tView) {
        return stack.push('qrc:/page/' + tView + '.qml')
    }

    function initApplication() {
        this.tGame = Logique

        //this.tGame.start(320,550);
        this.tGame.start(Screen.width, Screen.height)

        var sl1 = miseajourscore.afficherScore(1)
        var sl2 = miseajourscore.afficherScore(2)

        main.tGame.lireMeilleursScores(sl1, sl2)
    }
    Component.onCompleted: initApplication()
}
