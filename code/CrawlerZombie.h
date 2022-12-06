#include "Zombie.h"

class CrawlerZombie : public Zombie
{
public:
    CrawlerZombie(int, int, std::string);

private:
    const int CRAWLER_HEALTH = 150;
    const int CRAWLER_SPEED = 15;
    const int CRAWLER_DAMAGE = 30;
};