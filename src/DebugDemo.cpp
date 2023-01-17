#include "DebugDemo.hpp"

DebugDemo::DebugDemo(/* args */) {}

void DebugDemo::output()
{
    qDebug();
    qInfo();
    qWarning();
    qCritical();
    // qFatal("fatal");
}