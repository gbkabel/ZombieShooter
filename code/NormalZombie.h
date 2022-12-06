#include "Zombie.h"

class NormalZombie : public Zombie
{
public:
    NormalZombie(int, int, std::string);

private:
    const int NORMAL_HEALTH = 100;
    const int NORMAL_SPEED = 25;
    const int NORMAL_DAMAGE = 10;
};