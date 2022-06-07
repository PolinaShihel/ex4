
#ifndef EX2_Player_H
#define EX2_Player_H

#include <stdbool.h>
#include "utilities.h"

static const int INITIAL_LEVEL = 1;
static const int DEFAULT_INITIAL_FORCE = 5;
static const int DEFAULT_MAX_HP = 100;
static const int INITIAL_COINS = 0;
static const int MAXIMUM_LEVEL = 10;
static const int MIN_HP = 0;

using std::string;
class Player {
public:
    /*
     * C'tor of Player class
     *
     * @param playerName - The player's name.
     * @param initialForce - The initial force of the player.
     * @param maxHP - The maximum value of health points for said player.
     * @return
     *      A new instance of Player.
    */
    Player(const string playerName, int maxHP = DEFAULT_MAX_HP, int initialForce = DEFAULT_INITIAL_FORCE);

    /*
     * Copy C'tor od Player class
     *
     * @param Player& - reference to an existing Player object.
     * @return
     *      A new instance of Player.
     */
    Player(const Player& player) = default;

    /*
     * D'tor of Player class.
     */
    ~Player() = default;

    /*
     * Assignment operator od Player class.
     *
     * @param reference to a Player object.
     *@return
     *      reference to a Player object.
     *
     */
    Player& operator=(const Player& other) = default;

    /*
     * Prints info of player:
     *
     * @return
     *      void
    */
    void printInfo() const;
    /*
    * Levels up the player by one level, if at maximum level (10) does nothing.
    *
    * @return
    *       void.
    */
    void levelUp();

    /*
     * Increases player's force by given amount.
     *
     * @param points - the value that the force is to be increased by.
     * @return
     *      void.
     */
    int getLevel() const;

    void buff(int force);

    /*
     * Increases the player's health points by a given value.
     *
     * @param points - the value that the health points are to be increased by.
     * @return
     *      void.
     */
    void heal(int points);

    /*
     * Decreases the player's health points by a given amount.
     *
     * @param points - the value by which the HP is decreased by.
     * @return
     *      void.
     */
    void damage(int points);

    /*
     * Checks to see is the player has run out of health points.
     *
     * @return
     *      Whether the player has reached zero health points
     */
    bool isKnockedOut() const;

    /*
     * Increases number of coins a player has by a given amount.
     *
     * @param addedCoins - The number of coins to be added to the player
     * @return
     *      void.
     */
    void addCoins(int addedCoins);

    /*
     * Decreases the number of coins a player has by a given amount.
     *
     * @param payment - the number of coins to be taken from the player as payment
     * @return
     *      Whether the payment was done successfully
     */
    bool pay(int payment);

    /*
     * Returns player's attack strength, determined by the sum of his force & level
     */
    int getAttackStrength() const;

private:
    string m_name;
    int m_level;
    int m_force;
    int m_maxHp;
    int m_hp;
    int m_coins;
};


#endif //EX2_Player_H
