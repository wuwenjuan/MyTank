//
//  MainScene.cpp
//  Tank
//
//  Created by wwj on 14/10/25.
//
//

#include "MainScene.h"
#include "GameScene.h"

Scene* MainScene::createScene()
{
    Scene* scene = Scene::create();
    Layer* layer = MainScene::create();
    scene->addChild(layer);
    return scene;
}

bool MainScene::init()
{
    if(!Layer::init())
        return false;
    auto winsize = Director::getInstance()->getWinSize();
    
    auto backgroud = Sprite::create("gameBackground.png");
    backgroud->setPosition(winsize.width/2,winsize.height/2);
    backgroud->setScale(winsize.width/backgroud->getTextureRect().size.width, winsize.height/backgroud->getTextureRect().size.height);
    addChild(backgroud);
    
    auto title = Sprite::create("title.png");
    title->setPosition(winsize.width/3,winsize.height/6*5);
    addChild(title);
    
    auto deco = Sprite::create("decoration.png");
    deco->setPosition(winsize.width/3,winsize.height/5*2);
    addChild(deco);
    
    auto newgame = MenuItemImage::create("start_game.png", "start_game_select.png", CC_CALLBACK_0(MainScene::startGame, this));
    auto helpgame = MenuItemImage::create("help.png", "help_select.png", CC_CALLBACK_0(MainScene::help, this));
    auto soundset = MenuItemImage::create("soundset.png", "soundset_select.png", CC_CALLBACK_0(MainScene::sountSet, this));
    auto exitgame = MenuItemImage::create("exit_game.png", "exit_game_select.png", CC_CALLBACK_0(MainScene::exitGamed, this));
    
    auto menu = Menu::create(newgame,helpgame,soundset,exitgame,NULL);
    menu->setPosition(0,0);
    menu->setEnabled(false);
    addChild(menu);
    
    Node* child = NULL;
    float menuxPos = winsize.width/4*3;
    Vector<Node*> array = menu->getChildren();
    int count = array.size();
    for (int n=0; n<count; ++n) {
        child = array.at(n);
        child->setPosition(menuxPos,winsize.height+40);
        auto moveto = MoveTo::create(0.2, Vec2(menuxPos,-40));
        auto moveto2 = MoveTo::create(0.25*(count-n), Vec2(menuxPos,80*(count-n)));
        auto move_ease_in2 = EaseElasticOut::create(moveto2);
        auto dely = DelayTime::create(1.5+0.2*(count-n-1));
        
        auto seq = Sequence::create(dely,moveto,move_ease_in2, NULL);
        child->runAction(seq);
    }
    menu->setEnabled(true);
    return true;
}

void MainScene::startGame()
{
    Scene* newScene = GameScene::createScene();
    auto fade = TransitionFade::create(0.8, newScene,Color3B::WHITE);
    Director::getInstance()->replaceScene(fade);
}

void MainScene::help()
{
    
}

void MainScene::sountSet()
{
    
}

void MainScene::exitGamed()
{
    Director::getInstance()->end();
}