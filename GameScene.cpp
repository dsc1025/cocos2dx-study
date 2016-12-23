#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;


Scene* GameScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene::init() {
	if (!Layer::init())
	{
		return false;
	}

	//get scene size
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//knight initialize
	this->knightCache->addSpriteFramesToCache();

	knight = this->knightCache->createCha_kni_f_0000Sprite();
	knight->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	knightAnimation = this->knightCache->createCha_kni_fAnimateAction(0.14f);

	knight->runAction(RepeatForever::create(knightAnimation));
	this->addChild(knight);

	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);

	return true;
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode) {
	case EventKeyboard::KeyCode::KEY_SPACE:

		Action *jump = JumpBy::create(.5, Vec2(0, 0), 20, 1);
		knight->runAction(jump);

		break;
	}
}