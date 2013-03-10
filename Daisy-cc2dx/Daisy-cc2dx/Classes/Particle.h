//
//  Particle.h
//  Daisy-cc2dx
//
//  Created by Fakhir Shaheen on 07/03/2013.
//
//

#ifndef __Daisy_cc2dx__Particle__
#define __Daisy_cc2dx__Particle__

#include "cocos2d.h"

cocos2d::CCSpriteBatchNode * batch = NULL;

class Particle {
    
public:

    Particle(cocos2d::CCNode * parent){
        if(batch == NULL){
            CCLOG("Initializing sprite batch");
            cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("daisy-texture.plist");
            batch = cocos2d::CCSpriteBatchNode::create("daisy-texture.png");
            parent->addChild(batch);
        }
        sprite = cocos2d::CCSprite::createWithSpriteFrameName("daisy.png");
    }

    float vx;
    float vy;
    cocos2d::CCSprite * sprite;

};

#endif /* defined(__Daisy_cc2dx__Particle__) */
