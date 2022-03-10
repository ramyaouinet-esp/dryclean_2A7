#include "finances.h"
#include <QMessageBox>
#include <QDebug>

finances::finances()
{
   QDate date1(1995,2,2);

   ID_FINANCES="";
   MONTANT_FINANCE=0;
   PROVENANCE="";
   TYPE_TRANSACTION=0;
   DATE_FINANCES=date1;
   MATRICULE_FISC="";
   ID_COMMANDE=0;

}

finances::finances(QDate DATE_FINANCES,int TYPE_TRANSACTION,QString PROVENANCE,int MONTANT_FINANCE,QString ID_FINANCES,QString MATRICULE_FISC,int ID_COMMANDE)
{
    this->ID_FINANCES=ID_FINANCES;
    this->MONTANT_FINANCE=MONTANT_FINANCE;
    this->PROVENANCE=PROVENANCE;
    this->TYPE_TRANSACTION=TYPE_TRANSACTION;
    this->DATE_FINANCES=DATE_FINANCES;
    this->TYPE_TRANSACTION=TYPE_TRANSACTION;
    this->DATE_FINANCES=DATE_FINANCES;
    this->MATRICULE_FISC=MATRICULE_FISC;
    this->ID_COMMANDE=ID_COMMANDE;
}
QString finances::getPROVENANCE()
{ return PROVENANCE;}
QDate finances::getDATE_FINANCES()
{return DATE_FINANCES;}
int finances::getTYPE_TRANSACTION()
{ return TYPE_TRANSACTION;}
int finances::getMONTANT_FINANCE()
{return MONTANT_FINANCE;}
QString finances::getID_FINANCES()
{return ID_FINANCES;}
int finances::getID_COMMANDE()
{return ID_COMMANDE;}
QString finances::getMATRICULE_FISC()
{return MATRICULE_FISC;}

void finances::setPROVENANCE(QString PROVENANCE)
{this->PROVENANCE=PROVENANCE;}
void finances::setDATE_FINANCES(QDate DATE_FINANCES)
{this->DATE_FINANCES=DATE_FINANCES;}
void finances::setTYPE_TRANSACTION (int TYPE_TRANSACTION)
{this->TYPE_TRANSACTION=TYPE_TRANSACTION;}
void finances::setMONTANT_FINANCE (int MONTANT_FINANCE)
{this->MONTANT_FINANCE=MONTANT_FINANCE;}
void finances::setID_FINANCES (QString ID_FINANCES)
{this->ID_FINANCES=ID_FINANCES;}
void finances::setID_COMMANDE(int ID_COMMANDE)
{this->ID_COMMANDE=ID_COMMANDE;}
void finances::setMATRICULE_FISC(QString MATRICULE_FISC)
{this->MATRICULE_FISC=MATRICULE_FISC;}

bool finances::ajouter()
{
    QSqlQuery query;
                query.prepare("INSERT INTO finances (ID_FINANCES,DATE_FINANCES,MONTANT_FINANCE,TYPE_TRANSACTION,PROVENANCE,ID_COMMANDE,MATRICULE_FISC) "
                              "VALUES (:ID_FINANCES,:DATE_FINANCES,:MONTANT_FINANCE,:TYPE_TRANSACTION,:PROVENANCE,:ID_COMMANDE,:MATRICULE_FISC)");
                query.bindValue(":ID_FINANCES", ID_FINANCES);
                query.bindValue(":DATE_FINANCES", DATE_FINANCES);
                query.bindValue(":MONTANT_FINANCE",MONTANT_FINANCE);
                query.bindValue(":TYPE_TRANSACTION",TYPE_TRANSACTION);
                query.bindValue(":PROVENANCE",PROVENANCE);
                query.bindValue(":ID_COMMANDE",ID_COMMANDE);
                query.bindValue(":MATRICULE_FISC",MATRICULE_FISC);
                return query.exec();

}
QSqlQueryModel* finances::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM  finances where TYPE_TRANSACTION=0");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCES"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FINANCES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT_FINANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_TRANSACTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PROVENANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MATRICULE_FISC"));


    return model;
}
QSqlQueryModel* finances::afficher2()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM  finances where TYPE_TRANSACTION=1");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCES"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FINANCES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT_FINANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_TRANSACTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PROVENANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MATRICULE_FISC"));


    return model;
}
bool finances::supprimer(QString ID_FINANCES){
    QSqlQuery query;
    finances C;

    query.prepare("Delete from finances where ID_FINANCES=:ID_FINANCES");
    query.bindValue(":ID_FINANCES", ID_FINANCES);

    return query.exec();
}

bool finances::recherche_id(QString ID_FINANCES)
{
    QMessageBox msgBox;
    QSqlQuery query;
    query.prepare("SELECT * FROM finances WHERE ID_FINANCES= :ID_FINANCES");
    query.bindValue(":ID_FINANCES", ID_FINANCES);
    if (query.exec() && query.next())
    {
            return true;
    }
    else
    {
        return false;
    }
}
bool finances::modifier(QString ID_FINANCES)
{
    QSqlQuery query;

    if (recherche_id(ID_FINANCES))
    {

          query.prepare("UPDATE finances SET DATE_FINANCES=:DATE_FINANCES, MONTANT_FINANCE=:MONTANT_FINANCE,TYPE_TRANSACTION=:TYPE_TRANSACTION,PROVENANCE=:PROVENANCE,ID_COMMANDE=:ID_COMMANDE,MATRICULE_FISC=:MATRICULE_FISC WHERE ID_FINANCES=:ID_FINANCES");

          query.bindValue(":ID_FINANCES", ID_FINANCES);
          query.bindValue(":DATE_FINANCES", DATE_FINANCES);
          query.bindValue(":MONTANT_FINANCE",MONTANT_FINANCE);
          query.bindValue(":TYPE_TRANSACTION",TYPE_TRANSACTION);
          query.bindValue(":PROVENANCE",PROVENANCE);
          query.bindValue(":ID_COMMANDE",ID_COMMANDE);
          query.bindValue(":MATRICULE_FISC",MATRICULE_FISC);


    }
          return query.exec();
}
QSqlQueryModel* finances::Trie_dateC()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM  finances where TYPE_TRANSACTION=0 order by DATE_FINANCES  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCES"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FINANCES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT_FINANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_TRANSACTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PROVENANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MATRICULE_FISC"));


    return model;
}
QSqlQueryModel* finances::Trie_dateD()
{
    QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM  finances where TYPE_TRANSACTION=0  order by DATE_FINANCES DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCES"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FINANCES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT_FINANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_TRANSACTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PROVENANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MATRICULE_FISC"));


    return model;
}
QSqlQueryModel* finances::Trie_montantC()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM  finances where TYPE_TRANSACTION=0 order by MONTANT_FINANCE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCES"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FINANCES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT_FINANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_TRANSACTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PROVENANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MATRICULE_FISC"));


    return model;
}
QSqlQueryModel* finances::Trie_montantD()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM  finances where TYPE_TRANSACTION=0  order by MONTANT_FINANCE DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCES"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FINANCES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT_FINANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_TRANSACTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PROVENANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MATRICULE_FISC"));


    return model;
}
QSqlQueryModel* finances::Trie_dateC2()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM  finances where TYPE_TRANSACTION=1 order by DATE_FINANCES  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCES"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FINANCES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT_FINANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_TRANSACTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PROVENANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MATRICULE_FISC"));


    return model;
}
QSqlQueryModel* finances::Trie_dateD2()
{
    QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM  finances where TYPE_TRANSACTION=1 order by DATE_FINANCES DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCES"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FINANCES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT_FINANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_TRANSACTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PROVENANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MATRICULE_FISC"));


    return model;
}
QSqlQueryModel* finances::Trie_montantC2()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM  finances where TYPE_TRANSACTION=1 order by MONTANT_FINANCE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCES"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FINANCES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT_FINANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_TRANSACTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PROVENANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MATRICULE_FISC"));


    return model;
}
QSqlQueryModel* finances::Trie_montantD2()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM  finances where TYPE_TRANSACTION=1 order by MONTANT_FINANCE DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FINANCES"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FINANCES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT_FINANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_TRANSACTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PROVENANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MATRICULE_FISC"));


    return model;
}