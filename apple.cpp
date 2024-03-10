#include "apple.h"
#include "serpent.h"

namespace serpent
{
    Apple::Apple()
    {
        this->pos.x = std::rand();
        this->pos.y = std::rand();
    }

    void Apple::reposition(std::uint16_t max_x, std::uint16_t max_y)
    {
        this->pos.x = MOD(std::rand(), max_x);
        this->pos.y = MOD(std::rand(), max_y);
    }

    void Apple::reposition()
    {
        this->pos.x = std::rand();
        this->pos.y = std::rand();
    }

    void Apple::__reposition(serpent::Snake &s, std::uint16_t max_x, std::uint16_t max_y)
    {
        this->reposition(max_x, max_y);

__reposition:
        for (auto b : s.body) {
            if (this->pos == b.pos) {
                this->reposition(max_x, max_y);
                goto __reposition;
            }
        }
    }
}
