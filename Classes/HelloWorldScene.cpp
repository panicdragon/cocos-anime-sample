#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //auto rootNode = CSLoader::createNode("MainScene.csb");

    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //auto winSize = Director:: getInstance()-> getWinSize();
    
    
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto cat = Sprite::create("cat.png");
    auto move = MoveBy::create(2, Point(50,50));
    //auto scale = ScaleBy::create(2, 2);
    
    auto rotate = RotateBy::create(2, 90);
    
    //cat->setRotation(-45);
    
    auto spawn = Spawn::create(move, rotate, nullptr);
    
    //auto flip = FlipY::create(true);
    
    cat->setPosition(Point(visibleSize.width/2, visibleSize.height/2));

    //cat->setPosition(Point(0, 0));
    
    //cat->setAnchorPoint(Point(1,1));
    
    //addChild(rootNode);
    //this->addChild(bg, 0);
    this->addChild(cat, 0);
    
    cat->runAction(spawn);
    
    return true;
}
