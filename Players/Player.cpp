#include <iostream>
#include "utilities.h"
#include "Players/Player.h"

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

Player::Player(string& playerName) :
    m_name(playerName), m_level(INITIAL_LEVEL), m_force(INITIAL_FORCE),
    m_hp(INITIAL_MAX_HP), m_coins(INITIAL_COINS)
{
    while(!checkName(playerName))
    {
        printInvalidName();
        printInsertPlayerMessage();
        std::getline(std::cin, playerName);
    }
    m_name = playerName;
}


bool Player::checkName(const string& name)
{
    return (name.length() > MAX_LENGTH)||(std::count(name.begin(), name.end(), ILLEGAL_SPACE));
}
void Player::levelUp()
{
    this->m_level += this->m_level < MAXIMUM_LEVEL;
}

void Player::buff(int force)
{
    this->m_force += max(force, 0);
}

void Player::heal(int points)
{
    this->m_hp = min(max(this->m_hp + points, this->m_hp), MIN_HP);
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

void Player::printInfo(int jobId) const
{
    printPlayerDetails(std::cout, m_name, jobs[jobId], m_level, m_force, m_hp, m_coins);
}