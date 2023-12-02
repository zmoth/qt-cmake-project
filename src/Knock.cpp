#include "Knock.h"

namespace knock {

Knock::Knock(int num) : _num(num) {}

int Knock::get_num() const
{
    return _num;
}

void Knock::set_num(int num)
{
    _num = num;
    Q_EMIT num_changed(_num);
}

void Knock::num_Knock()
{
    _num++;
    Q_EMIT num_changed(_num);
}

}  // namespace knock
