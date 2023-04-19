#include <QApplication>
#include "Ui.h"

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    Ui* ui = new Ui();

    ui->show();

    return app.exec();
}