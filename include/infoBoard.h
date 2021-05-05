#ifndef INFOBOARD_H
#define INFOBOARD_H

#include "spriteRule.h"
#include "player.h"

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

using sf::Font;
using sf::Text;

using std::vector;
using std::string;
using std::ostringstream;
using std::setfill;
using std::setw;
using std::stoi;

const string fontFile = "data/uni0553-webfont.ttf";
const string scoreFile = "data/highScore.txt";

class Info
{
public:
    Info(Player* player);
    ~Info();

    virtual void update();
    void loadHighScore();
    void saveHighScore();
    string buildScoreBoard();
    string buildLivesLevel();
    void buildliveIcons();
    void addToScore(int s);
    void sethighScore(int s);
    void setLevel(int l);
    vector<Text*> drawText();
    vector<Sprite*> drawLives();

protected:

private:
    unsigned int score;
    unsigned int highScore;
    unsigned int level;
    Font font;
    Text* scoreBoard;
    Text* controls;
    Text* lives_level;
    vector<Sprite*> liveIcons;
    Player* player;
};

#endif