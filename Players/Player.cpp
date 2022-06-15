#include "utilities.h"

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
    this->m_level += this->m_level < MAXIMUM_LEVEL;
}

void Player::buff(int force)
{
    this->m_force += fmax(force, 0);
}

void Player::heal(int points)
{
    this->m_hp = fmin(fmax(this->m_hp + points, this->m_hp), MIN_HP);
}

void Player::damage(int points)
{
    this->m_hp = fmax(fmin((this->m_hp) - points, (this->m_hp)), MIN_HP);
}

bool Player::isKnockedOut() const
{
    return m_hp == MIN_HP;
}

void Player::addCoins(int addedCoins)
{
    m_coins += fmax(addedCoins, 0);
}

bool Player::pay(int payment)
{
    if (payment <= 0) {
        return true;
    }
    if (this->m_coins - payment < 0) {
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

void Player::loseForce(int forceLost)
{
    m_force -= forceLost;
}