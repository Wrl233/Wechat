#include "MainWidget.h"
#include"LoginDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWidget w;
    // w.show();
    LoginDialog w;
    w.show();
    return a.exec();
}
