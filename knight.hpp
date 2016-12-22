// ---------------------------------------
// Sprite definitions for knight
// Generated with TexturePacker 4.3.1
//
// https://www.codeandweb.com/texturepacker
// 
// $TexturePacker:SmartUpdate:2a76e34e19c25c09c8ef0f32878e4fac:17292439ba2fad40942200dc364c469e:8353e7c5271e78f4e11914fcb9bdd70f$
// ---------------------------------------

#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "cocos2d.h"

namespace TexturePacker
{

	class Knight
	{
	public:
		/**
		 * Add sprite frames contained in theKnight sheet to
		 * the SpriteFrameCache.
		 */
		static void addSpriteFramesToCache();

		/**
		 * Remove sprite frames contained in theKnight sheet from
		 * the SpriteFrameCache.
		 */
		static void removeSpriteFramesFromCache();

		// ---------------------
		// sprite name constants
		// ---------------------
		static const std::string cha_kni_f_0000;
		static const std::string cha_kni_f_0001;
		static const std::string cha_kni_f_0002;
		static const std::string cha_kni_f_0003;
		static const std::string cha_kni_f_0004;
		static const std::string cha_kni_f_0005;

		// --------------
		// Sprite objects
		// --------------
		static cocos2d::Sprite *createCha_kni_f_0000Sprite();
		static cocos2d::Sprite *createCha_kni_f_0001Sprite();
		static cocos2d::Sprite *createCha_kni_f_0002Sprite();
		static cocos2d::Sprite *createCha_kni_f_0003Sprite();
		static cocos2d::Sprite *createCha_kni_f_0004Sprite();
		static cocos2d::Sprite *createCha_kni_f_0005Sprite();

		// ----------------
		// animation frames
		// ----------------
		static cocos2d::Vector<cocos2d::SpriteFrame*> getCha_kni_fAnimationFrames();

		// ---------------
		// animate actions
		// ---------------
		static cocos2d::Animate *createCha_kni_fAnimateAction(float delay, unsigned int loops = 1);

	}; // class

}; // namespace

#endif // __KNIGHT_H__
