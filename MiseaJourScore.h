#ifndef MISEAJOURSCORE_H
#define MISEAJOURSCORE_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QByteArray>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>

class MiseaJourScore: public QObject
{
    Q_OBJECT

public:
    MiseaJourScore();
   ~MiseaJourScore();



    Q_INVOKABLE QString afficherScore(int level);
    Q_INVOKABLE void enregistrerScore(QString lescore, int level);


     QFile fichier1;
     QFile fichier2;

private:

    bool ouverture1;
    bool ouverture2;
};

#endif // MISEAJOURSCORE_H
