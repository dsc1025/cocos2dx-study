#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "knight.hpp"
#include "GameMap.h"

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(GameScene);

	TexturePacker::Knight *knightCache = new TexturePacker::Knight();
	cocos2d::Sprite *knight = new cocos2d::Sprite();
	cocos2d::Animate *knightAnimation = new cocos2d::Animate();
	cocos2d::Action *jump = new cocos2d::Action();

	TiledMap::Map *map = nullptr;

private:
	cocos2d::EventListenerKeyboard *listenerKeyboard = cocos2d::EventListenerKeyboard::create();
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	
};

#endif // ___GAME_SCENE_H__