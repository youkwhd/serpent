#include "direction.h"

namespace serpent
{
    serpent::direction::Direction direction::to_opposite(Direction dir)
    {
        switch (dir) {
        case DIRECTION_RIGHT:
            return DIRECTION_LEFT;
        case DIRECTION_LEFT:
            return DIRECTION_RIGHT;
        case DIRECTION_UP:
            return DIRECTION_DOWN;
        case DIRECTION_DOWN:
            return DIRECTION_UP;
        }
    }
}
