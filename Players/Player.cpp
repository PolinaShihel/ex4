#include "../utilities.h"
#include <algorithm>
using std::string;
using std::min;
using std::max;

Player::Player(string playerName) :
    m_name(playerName), m_level(INITIAL_LEVEL), m_force(INITIAL_FORCE),
    m_hp(INITIAL_MAX_HP), m_coins(INITIAL_COINS)
{
}

void Player::levelUp()
{
    m_level += m_level < MAXIMUM_LEVEL;
}

void Player::buff(int force)
{
    m_force += max(force, 0);
}

void Player::heal(int points)
{
    m_hp = min(max(m_hp + points, m_hp), INITIAL_MAX_HP);
}

void Player::damage(int points)
{
    m_hp = max(min((m_hp) - points, (m_hp)), MIN_HP);
}

void Player::knockOut()
{
    m_hp = MIN_HP;
}

void Player::addCoins(int addedCoins)
{
    m_coins += max(addedCoins, 0);
}

bool Player::pay(int payment)
{
    if (payment <= 0) {
        return true;
    }
    if (m_coins - payment < 0) {
        return false;
    }
    m_coins -= payment;
    return true;
}

int Player::getAttackStrength() const
{
    return m_force + m_level;
}

std::ostream& operator<<(std::ostream& os, const Player& current)
{
    printPlayerDetails(os, current.m_name, current.getPlayerJob(),
                                       current.m_level, current.m_force, current.m_hp, current.m_coins);
    return os;
}

void Player::decreaseForce(int forceLost) {

    m_force = max(m_force - forceLost,  MIN_FORCE);
}