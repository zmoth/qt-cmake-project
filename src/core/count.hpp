#pragma once

#include <QObject>

class Count : public QObject
{
    Q_OBJECT

  public:
    Count(int num = 0);

    int getNum() const;

  public Q_SLOTS:
    void setNum(int num);
    void numCount();

  Q_SIGNALS:
    void numChanged(int num);

  private:
    int _num = 0;

  private:
    Q_DISABLE_COPY(Count)
};