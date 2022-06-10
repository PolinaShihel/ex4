
#ifndef EX2_Player_H
#define EX2_Player_H

#include "utilities.h"

static const int INITIAL_LEVEL = 1;
static const int INITIAL_FORCE = 5;
static const int INITIAL_MAX_HP = 100;
static const int INITIAL_COINS = 10;
static const int MAXIMUM_LEVEL = 10;
static const int MIN_HP = 0;
static const int MAX_LENGTH = 15;
static const char ILLEGAL_SPACE = ' ';
static const char *jobs[] = {"Rogue", "Wizard", "Fighter"};
static const int ROGUE = 0;
static const int WIZARD = 1;
static const int FIGHTER = 2;

using std::string;
class Player {
public:
    /*
     * C'tor of Player class
     *
     * @param playerName - The player's name.
     * @return
     *      A new instance of Player.
    */
    Player(string playerName);

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
    virtual ~Player() {};

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
     * @param jobId - The ID associated with the job of the current player
     * @return
     *      void
    */
    void printInfo(int jobId) const;

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
    void buff(int force);

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


    /*
     * Checks to see if the name provided is according to the set rules - aka shorter than
     * 15 characters and doesn't have any spaces
     *
     * @param name - name that is to be checked
     * @return
     *      bool - whether the name is valid or not
     */
    bool checkName(const string& name);


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

    /*
     * Returns the player name
     *
     * @return -
     *      Reference to name
     */
    string getName() const
    {
        return m_name;
    }

    /*
    * An abstract type of Copy C'tor to be overloaded by inheriting classes
    * Allows to create the specific type of current player dynamically
     */
    virtual Player* clone() const = 0;

protected:
    friend std::ostream& operator<<(std::ostream& os, const Player& current);
    virtual string getPlayerJob() const = 0;

private:
    string m_name;
    int m_level;
    int m_force;
    int m_hp;
    int m_coins;
};




#endif //EX2_Player_H
