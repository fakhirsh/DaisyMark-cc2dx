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

class Particle {
    
public:

    Particle(){
        sprite = cocos2d::CCSprite::create("daisy.png");
    }
    
    float vx;
    float vy;
    cocos2d::CCSprite * sprite;

};

#endif /* defined(__Daisy_cc2dx__Particle__) */
