#include <Config.h>

#include <QApplication>

#include "MainWindow.h"
int main(int argc, char *argv[])
{
    QApplication::setApplicationVersion(PROJECT_VERSION);

    QApplication const app(argc, argv);

    app.setWindowIcon(QIcon(":/icon.ico"));  // 给app添加图标

    MainWindow w;
    w.show();

    return app.exec();
}
