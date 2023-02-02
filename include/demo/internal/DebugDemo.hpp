#pragma once

#include <QDebug>

#include "Export.hpp"

namespace Demo
{

class PROJECT_DLL_PUBLIC DebugDemo
{
  public:
    DebugDemo(/* args */);

    virtual ~DebugDemo() { qDebug(); }

    void output();
};

}  // namespace Demo
