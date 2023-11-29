#include "DebugDemo.h"

#include <QDebug>

namespace Demo {

DebugDemo::~DebugDemo()
{
    qDebug();
}

void DebugDemo::output()
{
    qDebug("Debug");
    qInfo("Info");
    qWarning("Warning");
    qCritical("Critical");
    // qFatal("Fatal");
}

}  // namespace Demo
