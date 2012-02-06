#ifndef TANKS_H
#define TANKS_H

#include "cocos2d.h"


class Tanks : public cocos2d::CCLayer {

public:
    
    static cocos2d::CCScene* scene();
    
    virtual bool init();    
    virtual void menuCloseCallback(cocos2d::CCObject* pSender);
        
    LAYER_NODE_FUNC(Tanks);
        
    Tanks():max_order(0){}

protected:

    int max_order;
    cocos2d::CCSprite* player;
    cocos2d::CCSprite* playerEnemy;
    
    void gameLogic(cocos2d::ccTime dt);
    int order();
    
    // events handlers

    void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
    
};

#endif // TANKS_H
