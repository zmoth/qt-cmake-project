#include "DebugDemo.h"

DebugDemo::DebugDemo(/* args */) {}

void DebugDemo::output()
{
    qDebug();
    qInfo();
    qWarning();
    qCritical();
    // qFatal("fatal");
}