#include <QApplication>
#include <libssh/libssh.h>
#include "Ui.h"

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    // Create UI and show
    Ui* ui = new Ui();    // make constructors pass the ssh session, OR just initialize session in GPIO fctns

    ui->show();

    return app.exec();
}