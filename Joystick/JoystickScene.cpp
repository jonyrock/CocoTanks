#include "JoystickScene.h"


JoystickScene::~JoystickScene() {
    if(layer) {
        layer->release();
        layer = NULL;
    }
}

bool JoystickScene::init() {
    
    if(!CCScene::init()){
        return false;
    }
    
    
    this->layer = JoystickLayer::node();
    this->layer->retain();
    this->addChild(layer);
    
    return true;
    
}
