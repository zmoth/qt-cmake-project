#include "DebugDemo.hpp"

namespace Demo
{

DebugDemo::DebugDemo(/* args */) {}

void DebugDemo::output()
{
    qDebug();
    qInfo();
    qWarning();
    qCritical();
    // qFatal("fatal");
}

}  // namespace Demo
