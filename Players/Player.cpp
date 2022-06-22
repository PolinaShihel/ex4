#include "../utilities.h"

using std::ostream;
using std::string;
using std::fmin;
using std::fmax;

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
    m_force += fmax(force, 0);
}

void Player::heal(int points)
{
    m_hp = fmin(fmax(m_hp + points, m_hp), INITIAL_MAX_HP);
}

void Player::damage(int points)
{
    m_hp = fmax(fmin((m_hp) - points, (m_hp)), MIN_HP);
}

void Player::knockOut()
{
    m_hp = MIN_HP;
}

void Player::addCoins(int addedCoins)
{
    m_coins += fmax(addedCoins, 0);
}

bool Player::pay(int payment)
{
    if (payment <= 0)
    {
        return true;
    }
    if (m_coins - payment < 0)
    {
        return false;
    }
    m_coins -= payment;
    return true;
}

int Player::getAttackStrength() const
{
    return m_force + m_level;
}

ostream& operator<<(ostream& stream, const Player& current)
{
    printPlayerDetails(stream, current.m_name, current.getPlayerJob(),
                                       current.m_level, current.m_force, current.m_hp, current.m_coins);
    return stream;
}

void Player::decreaseForce(int forceLost)
{
    m_force = fmax(m_force - forceLost,  MIN_FORCE);
}