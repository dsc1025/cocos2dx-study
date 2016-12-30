#include "gameMap.h"

USING_NS_CC;

namespace TiledMap {
	Map::Map(std::string url)
	{
		filePath = url;
		initMap();
	}

	Map::~Map()
	{
	}
	void Map::initMap() {
		TMap = TMXTiledMap::create(filePath);
		Size mapSize = TMap->getMapSize();
		Size tileSize = TMap->getTileSize();
		

		Vector<Node *> arratSprite = TMap->getChildren();
		TMXLayer* Layer = TMap->getLayer("layer 1");

		CCLOG("%f", Layer->getTileGIDAt(Vec2(0, 14)));

		Sprite *sprite = Layer->getTileAt(Vec2(0, 14));
		sprite->setColor(Color3B(255, 0, 255));


		//CCLOG("x:%f, y:%f", sprite->getAnchorPoint().x, sprite->getAnchorPoint().y);

		listenerMouse->onMouseMove = CC_CALLBACK_1(Map::onMouseMove, this);
		Layer->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerMouse, Layer);

	};
	void Map::onMouseMove(EventMouse* event)
	{
		//Vec2 point = Map::staggeredCoordForPosition(Vec2(event->getLocationInView().x, event->getLocationInView().y));
		CCLOG("x:%2f, y:%2f", event->getLocationInView().x, event->getLocationInView().y);

	};
	// OpenGL坐标转成格子坐标
	Vec2 Map::staggeredCoordForPosition(Vec2 position) {
		Size mapSize = TMap->getMapSize();
		Size tileSize = TMap->getTileSize();
		int y = mapSize.height - 2 - ((2 * (int)position.y) / (int)tileSize.height);
		float x = position.x / tileSize.width - (y % 2) / 2.0f;
		return Vec2(x, y);
	}
	// tile坐标转成瓦片格子中心的OpenGL坐标
	Vec2 Map::positionForStaggeredCoord(const Vec2& StaggeredCoord)
	{
		Size mapSize = TMap->getMapSize();
		Size tileSize = TMap->getTileSize();
		int x = StaggeredCoord.x*tileSize.width + ((int)StaggeredCoord.y % 2)*tileSize.width / 2;
		int y = (mapSize.height - (StaggeredCoord.y + 1))*tileSize.height / 2 - tileSize.height / 2;
		return Vec2(x, y);
	}

}