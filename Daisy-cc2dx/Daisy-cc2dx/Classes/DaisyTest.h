//
//  DaisyTest.h
//  Daisy-cc2dx
//
//  Created by Fakhir Shaheen on 07/03/2013.
//
//

#ifndef __Daisy_cc2dx__DaisyTest__
#define __Daisy_cc2dx__DaisyTest__

#include "cocos2d.h"
#include <vector>

class Particle;

class DaisyTest : public cocos2d::CCLayer
{
public:
    
    DaisyTest();
    ~DaisyTest();
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(DaisyTest);
    
private:
    void initParticle(Particle * particle);
    void createParticles();
    void update(float dt);

    std::vector<Particle *> particles;
    float pScale;
    int numParticles = 700;
    int speed = 20;
    
    int screenWidth;
    int screenHeight;
    
    const float PI = 3.14159265359f;
    
};


#endif /* defined(__Daisy_cc2dx__DaisyTest__) */
