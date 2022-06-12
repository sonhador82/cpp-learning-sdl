#include "Enemy.h"

void Enemy::update()
{
    m_position.setX(m_position.getX() + 1);
    m_position.setY(m_position.getY() + 1);
}
