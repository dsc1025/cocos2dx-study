// ---------------------------------------
// Sprite definitions for knight
// Generated with TexturePacker 4.3.1
//
// https://www.codeandweb.com/texturepacker
// ---------------------------------------

#include "knight.hpp"

USING_NS_CC;

namespace TexturePacker
{

	void Knight::addSpriteFramesToCache()
	{
		SpriteFrameCache *cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("knight.plist");
	};

	void Knight::removeSpriteFramesFromCache()
	{
		SpriteFrameCache *cache = SpriteFrameCache::getInstance();
		cache->removeSpriteFramesFromFile("knight.plist");
	};


	// ---------------------
	// sprite name constants
	// ---------------------
	const std::string Knight::cha_kni_f_0000 = "cha_kni_f_0000.png";
	const std::string Knight::cha_kni_f_0001 = "cha_kni_f_0001.png";
	const std::string Knight::cha_kni_f_0002 = "cha_kni_f_0002.png";
	const std::string Knight::cha_kni_f_0003 = "cha_kni_f_0003.png";
	const std::string Knight::cha_kni_f_0004 = "cha_kni_f_0004.png";
	const std::string Knight::cha_kni_f_0005 = "cha_kni_f_0005.png";

	// ---------------------------------------------------------
	// convenience functions returing pointers to Sprite objects
	// ---------------------------------------------------------
	Sprite* Knight::createCha_kni_f_0000Sprite()
	{
		return Sprite::createWithSpriteFrameName(cha_kni_f_0000);
	}

	Sprite* Knight::createCha_kni_f_0001Sprite()
	{
		return Sprite::createWithSpriteFrameName(cha_kni_f_0001);
	}

	Sprite* Knight::createCha_kni_f_0002Sprite()
	{
		return Sprite::createWithSpriteFrameName(cha_kni_f_0002);
	}

	Sprite* Knight::createCha_kni_f_0003Sprite()
	{
		return Sprite::createWithSpriteFrameName(cha_kni_f_0003);
	}

	Sprite* Knight::createCha_kni_f_0004Sprite()
	{
		return Sprite::createWithSpriteFrameName(cha_kni_f_0004);
	}

	Sprite* Knight::createCha_kni_f_0005Sprite()
	{
		return Sprite::createWithSpriteFrameName(cha_kni_f_0005);
	}


	// ------------------------------------------------
	// convenience functions returning animation frames
	// ------------------------------------------------

	Vector<SpriteFrame*> Knight::getCha_kni_fAnimationFrames()
	{
		SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
		Vector<SpriteFrame*> frames;
		frames.reserve(6);
		frames.pushBack(frameCache->getSpriteFrameByName(cha_kni_f_0000));
		frames.pushBack(frameCache->getSpriteFrameByName(cha_kni_f_0001));
		frames.pushBack(frameCache->getSpriteFrameByName(cha_kni_f_0002));
		frames.pushBack(frameCache->getSpriteFrameByName(cha_kni_f_0003));
		frames.pushBack(frameCache->getSpriteFrameByName(cha_kni_f_0004));
		frames.pushBack(frameCache->getSpriteFrameByName(cha_kni_f_0005));
		return frames;
	}


	// ----------
	// animations
	// ----------

	Animate *Knight::createCha_kni_fAnimateAction(float delay, unsigned int loops)
	{
		return Animate::create(Animation::createWithSpriteFrames(getCha_kni_fAnimationFrames(), delay, loops));
	}

}; // namespace

