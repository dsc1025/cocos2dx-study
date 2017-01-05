#ifndef __GAMEMAP_H__
#define __GAMEMAP_H__

#include "cocos2d.h"

namespace TiledMap
{
	class Map
	{
	public:
		Map(std::string url);
		~Map();
		cocos2d::experimental::TMXTiledMap *TMap = nullptr;
		cocos2d::experimental::TMXLayer* Layer = nullptr;
		cocos2d::Size layerSize;
		cocos2d::Size mapTileSize;
		cocos2d::Sprite *sprite = nullptr;

		cocos2d::Vec2 getPositionForStaggeredAt(const cocos2d::Vec2& position);

		cocos2d::Vec2 staggeredCoordForPosition(cocos2d::Vec2 position);
		cocos2d::Vec2 positionForStaggeredCoord(const cocos2d::Vec2& StaggeredCoord);

		cocos2d::Vec2 tileCoordForPosition(const cocos2d::Vec2& position);
		cocos2d::Vec2 positionForTileCoord(const cocos2d::Vec2& tileCoord);

	private:
		void initMap();
		std::string filePath = "";

		cocos2d::EventListenerMouse *listenerMouse = cocos2d::EventListenerMouse::create();
		virtual void onMouseMove(cocos2d::EventMouse* event);

	};
};
#endif //__GAMEMAP_H__