#include "infoBoard.h"
#include "game.h"

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
Info::~Info()
{

}

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

void Info::loadHighScore()
{
    string str;
    ifstream scores(scoreFile);
    if (getline(scores, str))
        highScore = stoi(str);
    scores.close();
}
void Info::saveHighScore()
{
    ofstream scores(scoreFile);
    scores << highScore;
    scores.close();
}
string Info::buildScoreBoard()
{
    ostringstream str;
    str << "Score: " << setfill('0') << setw(5) << score << "\nHigh Score: " << setfill('0') << setw(5) << highScore;
    return str.str();
}
string Info::buildLivesLevel()
{
    ostringstream str;
    str << "Lives: " << player->getHealth() << "\tLevel: " << level;
    return str.str();
}
void Info::buildliveIcons()
{
    for (int i = 0; i < player->getHealth(); ++i)
    {
        Sprite* life = new Sprite(PLAYER);
        liveIcons.push_back(life);
        life->setPosition({(lives_level->getPosition().x + (50 * i)), (lives_level->getPosition().y + lives_level->getGlobalBounds().height + 20)});
    }
}
void Info::setScore(int s)
{
    score = s;
}
void Info::addToScore(int s)
{  
    score += s;
}
void Info::sethighScore(int s)
{
    highScore = s;
}
void Info::setLevel(int l)
{
    level = l;
}
void Info::incLevel()
{
    ++level;
}
int Info::getLevel()
{
    return level;
}
vector<Text*> Info::drawText()
{
    vector<Text*> temp = {scoreBoard, controls, lives_level};
    return temp;
}
vector<Sprite*> Info::drawLives()
{
    return liveIcons;
}
Text* Info::drawPaused()
{
    return paused;
}