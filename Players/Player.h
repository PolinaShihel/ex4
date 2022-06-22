#ifndef EX2_Player_H
#define EX2_Player_H
#include <iostream>
#include <set>
#include <cmath>

static const int INITIAL_LEVEL = 1;
static const int INITIAL_FORCE = 5;
static const int MIN_FORCE = 0;
static const int INITIAL_MAX_HP = 100;
static const int INITIAL_COINS = 10;
static const int MAXIMUM_LEVEL = 10;
static const int MIN_HP = 0;
static const int MAX_LENGTH = 15;
static const char ILLEGAL_SPACE = ' ';

class Player {
public:
    /*
     * C'tor of Player class
     *
     * @param playerName - The player's name.
     * @return
     *      A new instance of Player.
    */
    Player(std::string playerName);

    /*
     * Copy C'tor od Player class
     *
     * @param Player& - reference to an existing Player object.
     * @return
     *      A new instance of Player.
     */
    Player(const Player &player) = default;

    /*
     * D'tor of Player class.
     */
    virtual ~Player()
    {
    }

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
    * Levels up the player by one level, if at maximum level (10) does nothing.
    *
    * @return
    *       void.
    */
    void levelUp();

    /*
     * Increases player's force by given amount.
     *
     * @param force - the value that the force is to be increased by.
     * @return
     *      void.
     */
    void buff(int force);

    /*
    * Decreases player's force by given amount.
    *
    * @param forceLost - the value that the force is to be decreased by.
    * @return
    *      void.
    */
    void decreaseForce(int forceLost);

    /*
     * Increases the player's health points by a given value.
     *
     * @param points - the value that the health points are to be increased by.
     * @return
     *      void.
     */
    virtual void heal(int points);

    /*
     * Decreases the player's health points by a given amount.
     *
     * @param points - the value by which the HP is decreased by.
     * @return
     *      void.
     */
    void damage(int points);

    /*
     * Sets player health points to minimal value
     */
    void knockOut();

    /*
     * Increases number of coins a player has by a given amount.
     *
     * @param addedCoins - The number of coins to be added to the player
     * @return
     *      void.
     */
    virtual void addCoins(int addedCoins);

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
    virtual int getAttackStrength() const;

    /*GETTERS OF PLAYER FIELDS*/

    /*
    * Returns the player level
    *
    * @return -
    *      level
    */
    int getLevel() const
    {
        return m_level;
    }

    /*
     * Returns the player force
     *
     * @return -
     *      force
     */
    int getForce() const
    {
        return m_force;
    }

    int getCoins() const
    {
        return m_coins;
    }

    /*
     * Returns the player name
     *
     * @return -
     *      Player's name
     */
    std::string getName() const
    {
        return m_name;
    }

    /*
     * Returns player's health points
     */
    int getHealthPoints() const
    {
        return m_hp;
    }

    /*
    * An abstract type of Copy C'tor to be overloaded by inheriting classes
    * Allows to create the specific type of current player dynamically
     */
    virtual Player* clone() const = 0;

    /*
     * Print operator
     */
    friend std::ostream& operator<<(std::ostream& stream, const Player& current);

    /*
     * Function returns the Job of the current player - function is to be overloaded by inheriting classes
     */
    virtual std::string getPlayerJob() const = 0;

private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_hp;
    int m_coins;
};

#endif //EX2_Player_H
