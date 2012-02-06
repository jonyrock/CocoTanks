#include "Tanks.h"


using namespace cocos2d;

#define DEBUG

CCScene* Tanks::scene() {

    CCScene* scene = CCScene::node();
    Tanks* layer = Tanks::node();
    scene->addChild(layer);
    
    return scene;
        
}

bool Tanks::init() {

    if(!CCLayer::init()) {
        return false;
    }
    
    CCMenuItemImage* pCloseItem =
        CCMenuItemImage::itemFromNormalImage("CloseNormal.png", "CloseSelected.png", this,
                menu_selector(Tanks::menuCloseCallback));
                
    pCloseItem->setPosition(CCPointMake((float)(CCDirector::sharedDirector()->getWinSize().width - 20),
                                        (float)20));
                                        
    CCMenu* pMenu = CCMenu::menuWithItems(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, order());
    
    CCLabelTTF* pLabel = CCLabelTTF::labelWithString("Tanks", "Arial", 24);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    pLabel->setPosition(ccp(size.width / 2, size.height - 50));
    this->addChild(pLabel, order());
    
//    CCSprite* pSprite = CCSprite::spriteWithFile("HelloWorld.png");
//    pSprite->setPosition(ccp(size.width/2, size.height/2));
//    this->addChild(pSprite, 0);

    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    this->player = CCSprite::spriteWithFile("tank.png", CCRectMake(0, 0, 73, 71));
    
    
    // instead of "player->getContentSize().width/2"
    this->player->setPosition(CCPointMake(winSize.width / 2,
                                          player->getContentSize().height / 2));
                                          
    this->addChild(player, order());
    
    this->schedule(schedule_selector(Tanks::gameLogic), 0.03);
    
    this->setIsTouchEnabled(true);
    
    CCLOG("Yoyoyo");
    
    return true;
    
}

void Tanks::gameLogic(cocos2d::ccTime dt) {

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
