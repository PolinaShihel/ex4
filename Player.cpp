#include <iostream>
#include "utilities.h"
#include "Player.h"

static int max(int x, int y)
{
    int maxValue = x > y ? x : y;
    return maxValue;
}

static int min(int x, int y)
{
    int minValue = x < y ? x : y;
    return minValue;
}

Player::Player(string playerName, int maxHp, int initialForce) :
    m_name(playerName), m_level(INITIAL_LEVEL), m_force(initialForce), m_maxHp(maxHp),
    m_hp(maxHp), m_coins(INITIAL_COINS)
{
    if (maxHp <= MIN_HP) {
        m_maxHp = m_hp = DEFAULT_MAX_HP;
    }
    if (initialForce <= 0) {
        m_force = DEFAULT_INITIAL_FORCE;
    }
}

void Player::printInfo() const
{
    printPlayerInfo(this->m_name.c_str(), this->m_level, this->m_force, this->m_hp, this->m_coins);
}

void Player::levelUp()
{
    this->m_level += this->m_level < MAXIMUM_LEVEL;
}

int Player::getLevel() const
{
    return this->m_level;
}

void Player::buff(int force)
{
    this->m_force += max(force, 0);
}

void Player::heal(int points)
{
    this->m_hp = min(max(this->m_hp + points, this->m_hp), this->m_maxHp);
}

void Player::damage(int points)
{
    this->m_hp = max(min((this->m_hp) - points, (this->m_hp)), MIN_HP);
}

bool Player::isKnockedOut() const
{
    return m_hp == MIN_HP;
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