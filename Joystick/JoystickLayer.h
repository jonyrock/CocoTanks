#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "cocos2d.h"

class JoystickLayer : public cocos2d::CCLayerColor {

public:

    JoystickLayer():label(NULL) {};
    virtual ~JoystickLayer();
    bool init();
    
    LAYER_NODE_FUNC(JoystickLayer);
    
    virtual cocos2d::CCLabelTTF* getLabel(void) const {
        return label;
    }
    
protected:

    cocos2d::CCLabelTTF* label;
    
};


/**
class JoystickScene : public cocos2d::CCScene {

public:
    
    JoystickScene():layer(NULL){};
    ~JoystickScene();    
    bool init();
    SCENE_NODE_FUNC(JoystickScene);
    
    virtual JoystickLayer* getLayer(void) const {
        return layer;
    }
    
protected:

    JoystickLayer* layer;
    
};*/


#endif // JOYSTICK_H
