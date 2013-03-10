//
//  DaisyTest.cpp
//  Daisy-cc2dx
//
//  Created by Fakhir Shaheen on 07/03/2013.
//
//

#include "DaisyTest.h"
#include "Particle.h"

using namespace cocos2d;
using namespace std;

DaisyTest::DaisyTest(){

}

DaisyTest::~DaisyTest(){

}

CCScene* DaisyTest::scene(){
    CCScene * scene = CCScene::create();
    CCLayer * layer = DaisyTest::create();
    scene->addChild(layer);
    return scene;
}

bool DaisyTest::init(){
    
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    this->schedule( schedule_selector(DaisyTest::update) ); 
    
    screenWidth = 960;
    screenHeight = 640;
    pScale = (screenHeight * .125)/((new Particle(this))->sprite->getContentSize().height);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    createParticles();

    return true;
}

void DaisyTest::createParticles(){
    for(int i = 0; i < numParticles; i++){
        Particle * p = new Particle(this);
        initParticle(p);
        this->addChild(p->sprite);
        particles.push_back(p);
    }
}

float min(float a, float b){
    return (a < b)?a:b;
}

void DaisyTest::initParticle(Particle * particle){

    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    float a = PI/2.0f * (float)random()/RAND_MAX - PI*0.75f;
    float v = (float)random()/RAND_MAX * speed;
    particle->vx = cosf(a)*v;
    particle->vy = -min(-10 - 10 * (float)random()/RAND_MAX, sin(a)*v);
    particle->sprite->setPosition(ccp(size.width/2.0f, 0));
    
    //float scale = (pScale * .5) + ((float)random()/RAND_MAX * pScale * .5);
    //particle->sprite->setScaleX(scale);
    //particle->sprite->setScaleY(scale);
    //particle->sprite->setOpacity(GLubyte((.20 + ((float)random()/RAND_MAX * .80))*255.0));
    
}

void DaisyTest::update(float dt){
   
    for(int i = 0, l = particles.size(); i < l; i++){
        Particle * particle = particles[i];
        
        //float rotation = particle->sprite->getRotation();
        //rotation += 1.0f;
        //particle->sprite->setRotation(rotation);
        
        int x = particle->sprite->getPosition().x;
        int y = particle->sprite->getPosition().y;
        x += particle->vx;
        y += particle->vy;
        particle->sprite->setPosition(ccp(x,y));
        
        particle->vy -= 0.35;
        particle->vx *= 0.99;
        
        if(particle->sprite->getPosition().y < 0){
            initParticle(particle);
        }
    }
    
}