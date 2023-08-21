#include "count.hpp"

Count::Count(int num) : _num(num) {}

int Count::getNum() const
{
    return _num;
}

void Count::setNum(int num)
{
    _num = num;
    Q_EMIT numChanged(_num);
}

void Count::numCount()
{
    _num++;
    Q_EMIT numChanged(_num);
}