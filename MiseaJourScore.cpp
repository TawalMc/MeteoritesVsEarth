#include "MiseaJourScore.h"

MiseaJourScore::MiseaJourScore()
{
    qDebug("Debut");

    fichier1.setFileName("meilleurscores1.txt");
    ouverture1 = fichier1.open(QIODevice::ReadWrite|QIODevice::Text);

    fichier2.setFileName("meilleurscores2.txt");
    ouverture2 = fichier2.open(QIODevice::ReadWrite|QIODevice::Text);

}

MiseaJourScore::~MiseaJourScore(){
    fichier1.close();
    fichier2.close();

    qDebug("fin");
}

QString MiseaJourScore::afficherScore(int level){

    if(level==1){ // score du level
        if(ouverture1==true) {

           QTextStream in(&fichier1);
           in.seek(0);
           QString ligne= in.readAll();
           return ligne;

        }else{
            return "R.A.S";
        }
    }//if(level1)

    else if (level==2){
        if(ouverture2==true){

           QTextStream in(&fichier2);
           in.seek(0);
           QString ligne= in.readAll();
           return ligne;

        }else{
            return "R.A.S";
        }
    }

    else {
        return "R.A.S" ;
    }
}

void MiseaJourScore::enregistrerScore(QString lescore, int level){

    if(level==1){
        if(ouverture1==true){

          QTextStream out(&fichier1);
          out.seek(0);
          out<<lescore;

        }else{
            qDebug() <<"Impossible\n";
        }//else(ouverture)

    }//if(level1)

    if(level==2){
        if(ouverture2==true){

          QTextStream out(&fichier2);
          out.seek(0);
          out<<lescore;

        }else{
            qDebug() <<"Impossible\n";
        }//else(ouverture)

    }//if
}
