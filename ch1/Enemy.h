#ifndef __Enemy__
#define __Enemy

#include "LoadParams.h"

class Enemy
{
private:
    /* data */
public:
    Enemy(const LoadParams* pParams);
    ~Enemy();
    virtual void draw();
    virtual void update();
    virtual void clean();
};

Enemy::~Enemy(){}


#endif // !__Enemy__
