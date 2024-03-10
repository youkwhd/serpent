#include "apple.h"

namespace serpent
{
    Apple::Apple()
    {
        this->pos.x = std::rand() % (800 / 20);
        this->pos.y = std::rand() % (440 / 20);
    }
}
