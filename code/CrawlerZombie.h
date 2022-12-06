#include "Zombie.h"

class CrawlerZombie : public Zombie
{
public:
    CrawlerZombie(int, int, std::string);

private:
    const int CRAWLER_HEALTH = 200;
    const int CRAWLER_SPEED = 20;
    const int CRAWLER_DAMAGE = 30;
};