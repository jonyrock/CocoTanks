#ifndef JOYSTICKSCENE_H
#define JOYSTICKSCENE_H

#include "cocos2d.h"
#include "JoystickLayer.h"

class JoystickScene : public cocos2d::CCScene {

public:
    
    ~JoystickScene();
    
    bool init();
    
    SCENE_NODE_FUNC(JoystickScene);
    
    virtual JoystickLayer* getLayer() const {
        return layer;
    }
    
protected:

    JoystickLayer* layer;
        
};

#endif // JOYSTICKSCENE_H
