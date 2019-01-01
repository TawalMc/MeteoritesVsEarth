#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "MiseaJourScore.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<MiseaJourScore>("MiseaJour.Score",1,0,"ScoreJour");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/MeteoritesVsEarthMain.qml")));

    return app.exec();
}
