
#include "Tanks.h"
#include "Joystick/JoystickScene.h"

using namespace cocos2d;

CCScene* Tanks::scene() {

    CCScene* scene = CCScene::node();
    Tanks* layer = Tanks::node();
    scene->addChild(layer);
    
    return scene;
    
}

bool Tanks::init() {

    // nesessary call base initialization
    if(!CCLayer::init()) {
        return false;
    }
    
    // end nesessary call base initialization
    
    this->setIsTouchEnabled(true); // define that we want to use ccTouchesEnded()
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize(); // set window size
    
    // locate menu with one close button
    CCMenuItemImage* pCloseItem =
        CCMenuItemImage::itemFromNormalImage("CloseNormal.png", "CloseSelected.png", this,
                menu_selector(Tanks::menuCloseCallback));
                
    pCloseItem->setPosition(CCPoint(winSize.width - 20, 20));
    
    CCMenu* pMenu = CCMenu::menuWithItems(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, order());
    // end locate menu with one close buttton
    
    // locate player unit
    this->player = CCSprite::spriteWithFile("tankSmall.jpg", CCRectMake(0, 0, 37, 31));
    this->player->setPosition(CCPoint(winSize.width / 2, player->getContentSize().height / 2));
    this->addChild(player, order());
    // end locate player unit

    // locate playerEnemy unit and launch moving
    this->playerEnemy = CCSprite::spriteWithFile("tankSmall.jpg", CCRectMake(0, 0, 37, 31));
    this->playerEnemy->setPosition(CCPoint(winSize.width - 40, winSize.height / 2));
    this->playerEnemy->setRotation(-90.0);
    this->addChild(playerEnemy, order());
    
    CCFiniteTimeAction* actionMove = CCMoveTo::actionWithDuration(10.0,
                                     CCPoint(1.0, winSize.height / 1.5));
    this->playerEnemy->runAction(actionMove);
    // end locate playerEnemy unit
    
    // begin call gameLogic in loop.
    // ADDED REPLACEMENT TO JOYSTICK
    this->schedule(schedule_selector(Tanks::gameLogic), 0.03);
    
    
    // return must be true or will be black window.
    return true;
    
    
    
}

void Tanks::gameLogic(cocos2d::ccTime dt) {
    
    // replace scene only for debug
    JoystickScene* joystickScene = JoystickScene::node();
    CCDirector::sharedDirector()->replaceScene(joystickScene);
    // end replace
    
    CCPoint p = this->player->getPosition();
    p.y += 1;
    this->player->setPosition(p);
    
}

int Tanks::order() {

    return this->max_order++;
    
}

void Tanks::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent) {

    CCTouch* touch = (CCTouch*)(pTouches->anyObject());
    CCPoint location = touch->locationInView(touch->view());
    location = CCDirector::sharedDirector()->convertToGL(location);
    
    this->player->setPosition(location);
    
}

void Tanks::menuCloseCallback(CCObject* pSender) {

    CCDirector::sharedDirector()->end();
    
}







// EOF
