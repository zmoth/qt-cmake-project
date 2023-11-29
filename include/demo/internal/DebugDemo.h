#pragma once

#include "Export.h"

namespace Demo {

/// @brief 一个打印日志的类
class DLLDEMO_EXPORT DebugDemo
{
  public:
    DebugDemo() = default;
    virtual ~DebugDemo();

    /// @brief 输出各种等级的日志
    void output();
};

}  // namespace Demo
