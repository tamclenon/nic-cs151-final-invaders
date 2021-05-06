/**
 * @file infoBoard.cpp
 * @author Shaun Martin
 * @brief Information board definition file
 * @date 2021-05-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "infoBoard.h"
#include "game.h"

/**
 * @brief Construct a new Info:: Info object
 * 
 * @param play A pointer to a Player object
 */
Info::Info(Player* play)
{
    player = play;
    score = 0;
    highScore = 0;
    level = 0;
    loadHighScore();
    font.loadFromFile(fontFile);
    paused = new Text;
    paused->setFont(font);
    paused->setString("Paused\nPress space to play");
    paused->setPosition({((Game::windowSize.x / 2) - (paused->getGlobalBounds().width / 2)), ((Game::windowSize.y / 2) - (paused->getGlobalBounds().height / 2))});
    scoreBoard = new Text;
    scoreBoard->setFont(font);
    scoreBoard->setString(buildScoreBoard());
    scoreBoard->setPosition({((Game::windowSize.x * PLAYPERCENT) + 20), (10.0f)});
    controls = new Text;
    controls->setFont(font);
    controls->setString("Controls:\nA to move left\nD to move right\nSpace to shoot\nP to pause\nR to restart\nEsc to quit");
    controls->setPosition({((Game::windowSize.x * PLAYPERCENT) + 20), (Game::windowSize.y * .3f)});
    lives_level = new Text;
    lives_level->setFont(font);
    lives_level->setString(buildLivesLevel());
    lives_level->setPosition({((Game::windowSize.x * PLAYPERCENT) + 20), (Game::windowSize.y * .8f)});
    buildliveIcons();
}
/**
 * @brief Destroy the Info:: Info object
 * 
 */
Info::~Info()
{

}

/**
 * @brief updates the scoreboard, level, and number of player lives
 * 
 */
void Info::update()
{
    scoreBoard->setString(buildScoreBoard());
    lives_level->setString(buildLivesLevel());
    while (liveIcons.size() > player->getHealth())
    {
        delete liveIcons[liveIcons.size() - 1];
        liveIcons.pop_back();
    }
    if (score > highScore)
        highScore = score;
}

/**
 * @brief Loads high score
 * 
 */
void Info::loadHighScore()
{
    string str;
    ifstream scores(scoreFile);
    if (getline(scores, str))
        highScore = stoi(str);
    scores.close();
}
/**
 * @brief Saves current high score
 * 
 */
void Info::saveHighScore()
{
    ofstream scores(scoreFile);
    scores << highScore;
    scores.close();
}
/**
 * @brief Initializes score board
 * 
 * @return string scoreboard
 */
string Info::buildScoreBoard()
{
    ostringstream str;
    str << "Score: " << setfill('0') << setw(5) << score << "\nHigh Score: " << setfill('0') << setw(5) << highScore;
    return str.str();
}
/**
 * @brief Initializes player lives on scoreboard
 * 
 * @return string Player lives
 */
string Info::buildLivesLevel()
{
    ostringstream str;
    str << "Lives: " << player->getHealth() << "\tLevel: " << level;
    return str.str();
}
/**
 * @brief Initializes player lives sprites
 * 
 */
void Info::buildliveIcons()
{
    for (int i = 0; i < player->getHealth(); ++i)
    {
        Sprite* life = new Sprite(PLAYER);
        liveIcons.push_back(life);
        life->setPosition({(lives_level->getPosition().x + (50 * i)), (lives_level->getPosition().y + lives_level->getGlobalBounds().height + 20)});
    }
}
/**
 * @brief Set the score on the scoreboard
 * 
 * @param s The score to set the score to
 */
void Info::setScore(int s)
{
    score = s;
}
/**
 * @brief Adds to the current score
 * 
 * @param s The amount to add to the score
 */
void Info::addToScore(int s)
{  
    score += s;
}
/**
 * @brief Sets high score
 * 
 * @param s Current high score
 */
void Info::sethighScore(int s)
{
    highScore = s;
}
/**
 * @brief Sets the current level of the game
 * 
 * @param l The level to be set to
 */
void Info::setLevel(int l)
{
    level = l;
}
/**
 * @brief Increments the level number
 * 
 */
void Info::incLevel()
{
    ++level;
}
/**
 * @brief Get the current level of the game
 * 
 * @return int The current level of the game
 */
int Info::getLevel()
{
    return level;
}
/**
 * @brief Draw the score, life number, and level number
 * 
 * @return vector<Text*> The vector of text to draw
 */
vector<Text*> Info::drawText()
{
    vector<Text*> temp = {scoreBoard, controls, lives_level};
    return temp;
}
/**
 * @brief Draw the player life sprites
 * 
 * @return vector<Sprite*> The vector of sprite pointers to draw
 */
vector<Sprite*> Info::drawLives()
{
    return liveIcons;
}
/**
 * @brief Draws the puase screen
 * 
 * @return Text* The text to be displayed
 */
Text* Info::drawPaused()
{
    return paused;
}