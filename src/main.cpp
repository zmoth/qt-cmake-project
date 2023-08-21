#include <QApplication>

#include "config.h"
#include "ui/InfoWindow.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName(PROJECT_NAME);
    QCoreApplication::setApplicationVersion(PROJECT_VER);
    QCoreApplication::setOrganizationName(QStringLiteral("MOTH"));
    QCoreApplication::setOrganizationDomain(QStringLiteral("https://zmoth.top/"));

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    const QApplication app(argc, argv);

    qInfo("%s v%s", qUtf8Printable(QApplication::applicationDisplayName()),
          qUtf8Printable(QApplication::applicationVersion()));
    qInfo("Build Date/Time: %s %s", __DATE__, __TIME__);
    qInfo("Qt: %s", qVersion());
    qInfo("OS: %s", qUtf8Printable(QSysInfo::prettyProductName()));
    qInfo("Locale: %s", qUtf8Printable(QLocale::system().name()));
    qInfo("CPU: %s", qUtf8Printable(QSysInfo::currentCpuArchitecture()));
    qInfo("File Path: %s", qUtf8Printable(QApplication::applicationFilePath()));
    qInfo("Arguments: %s", qUtf8Printable(app.arguments().join(' ')));

    QApplication::setWindowIcon(QIcon(":img/icon/icon.ico"));  // 给app添加图标

    InfoWindow w;
    w.show();
    return QApplication::exec();
}