#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "knight.hpp"

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);

	TexturePacker::Knight *knightCache = new TexturePacker::Knight;
	cocos2d::Sprite *knight;
	cocos2d::Animate *knightAnimation;

private:
	cocos2d::EventListenerKeyboard *listenerKeyboard = cocos2d::EventListenerKeyboard::create();
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
};

#endif // ___GAME_SCENE_H__