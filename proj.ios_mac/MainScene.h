//
//  MainScene.h
//  Tank
//
//  Created by wwj on 14/10/25.
//
//

#ifndef __Tank__MainScene__
#define __Tank__MainScene__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class MainScene : public Layer
{
public:
    static Scene* createScene();
    CREATE_FUNC(MainScene);
    virtual bool init();
    void startGame();
    void help();
    void sountSet();
    void exitGamed();
private:
};

#endif /* defined(__Tank__MainScene__) */
