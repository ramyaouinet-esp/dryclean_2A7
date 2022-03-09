#ifndef COMMANDE_H
#define COMMANDE_H
#include <QMainWindow>
#include <QString>
#include <QDate>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSharedDataPointer>

class Commande
{
public:
    Commande();
     Commande(int ref_cmd,int cin_cl, QString Nom_cl,int qtt_vet,int montant_cmd,QDate Date_cmd,int etat_cmd,QString adr_cl,int nb_pts, int type_vet, int opt_livr, int cin_emp);
     int getRef();
     QString getNomcl();
     QString getAdrcl();
     int getCincl();
     int getQttvet();
     int getMtcmd();
     int getEtatCmd();
     int getNbPt();
     int getTypeVet();
     int getOptLivr();
     int getCinCl();
     QDate getDateCmd();
     void setRef(int);
    void setNomcl(QString);
     void setAdrcl(QString);
     void setCincl(int);
     void setQttvet(int);
     void setMtcmd(int);
     void setEtatCmd(int);
     void setNbPt(int);
     void setTypeVet(int);
     void setOptLivr(int);
     void getDateCmd(QDate);
       void setDateCmd(QDate);
       void setCinCl(int);

     bool ajouter();
     QSqlQueryModel * afficherTrierDescDate();
     QSqlQueryModel * afficherTrierAscDate();
     QSqlQueryModel * afficherTrierAscMontant();
     QSqlQueryModel * afficherTrierDescMontant();
     QSqlQueryModel * afficherTrierDescLivr();
     bool supprimer(int);
     QSqlQueryModel * afficher();
     bool recherche_id(int);
     bool modifier(int);
     bool genererFacture(QString ref,QString cinS,QString qtt,QString Date,QString mt,QString type,QString livr,QString cin_e,QString nom);
bool NomValide(QString chaine);
bool adresseValide(QString adresse);
int entierValide(int entier);
bool DateValide(QDate Date);

private:
         int ref_cmd,cin_cl,qtt_vet,montant_cmd,etat_cmd,nb_pts,type_vet,opt_livr,cin_emp;
             QString Nom_cl,adr_cl;
             QDate Date_cmd;
};

#endif // COMMANDE_H
