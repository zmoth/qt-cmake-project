#pragma once

#include "Export.hpp"

#include <QDebug>

class PROJECT_DLL_PUBLIC DebugDemo
{
  public:
    DebugDemo(/* args */);

    virtual ~DebugDemo() { qDebug(); }

    void output();
};
