#include "DebugDemo.h"

#include <QDebug>

DebugDemo::DebugDemo(/* args */)
{
}

DebugDemo::~DebugDemo()
{
}

void DebugDemo::output() {
    qDebug();
    qInfo();
    qWarning();
    qCritical();
    // qFatal("fatal");
}