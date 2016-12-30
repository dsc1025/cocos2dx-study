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
		cocos2d::TMXTiledMap *TMap = nullptr;


		cocos2d::Vec2 staggeredCoordForPosition(cocos2d::Vec2 position);
		cocos2d::Vec2 positionForStaggeredCoord(const cocos2d::Vec2& StaggeredCoord);

	private:
		void initMap();
		std::string filePath = "";

		cocos2d::EventListenerMouse *listenerMouse = cocos2d::EventListenerMouse::create();
		virtual void onMouseMove(cocos2d::EventMouse* event);
	};
};
#endif //__GAMEMAP_H__