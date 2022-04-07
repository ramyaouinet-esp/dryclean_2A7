#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "webaxwidget.h"
#include "sqleventmodel.h"
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
//qputenv("QT_OPENGL", "software");

//QApplication::setAttribute(Qt::AA_UseSoftwareOpenGL, true);


    Connection c;

bool test=c.createconnect();
MainWindow w;

if(test)
{w.show();
    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("connection successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("connection failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

w.show();



return a.exec();
}

