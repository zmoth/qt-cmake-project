#pragma once

#include <QObject>

#include "Export.h"

namespace knock {

/// @brief 计数
class KNOCK_EXPORT Knock : public QObject
{
    Q_OBJECT

  public:
    explicit Knock(int num = 0);

    /// @brief 获取计数
    /// @return int
    [[nodiscard]] int get_num() const;

  public Q_SLOTS:
    /// @brief 设置计数值
    /// @param[in] num
    void set_num(int num);
    /// @brief +1 +1 +1 +1
    void knock();

  Q_SIGNALS:
    /// @brief 计数值改变
    void num_changed(int num);

  private:
    int _num{0};
};

}  // namespace knock
