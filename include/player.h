#ifndef PLAYER_H
#define PLAYER_H

#include "spriteRule.h"
#include <vector>
using std::vector;

class Player : public Sprite
{

public:
    Player();
    virtual ~Player();

    virtual void update(vector<Sprite*>& vec);
    void fire(vector<Sprite*>& vec);

protected:
    Sprite* bullet;

private:
    bool bulletExists;



};







#endif