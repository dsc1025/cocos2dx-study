#include "GameMap.h"

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
		TMap = experimental::TMXTiledMap::create(filePath);
		TMap->setPosition(Vec2(0, 0));
		//Vector<Node *> arratSprite = TMap->getChildren();

		Layer = TMap->getLayer("layer2");
		mapTileSize = Layer->getMapTileSize();
		layerSize = Layer->getLayerSize();

		//CCLOG("x:%f, y:%f", sprite->getAnchorPoint().x, sprite->getAnchorPoint().y);

		listenerMouse->onMouseMove = CC_CALLBACK_1(Map::onMouseMove, this);
		TMap->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerMouse, TMap);


	};
	void Map::onMouseMove(EventMouse* event)
	{
		static Vec2 pointA;
		Vec2 pointB = Map::tileCoordForPosition(event->getLocationInView());
		if (Layer->getTileAt(pointB) != nullptr && pointA != pointB) {

			Layer->getTileAt(pointB)->setColor(Color3B(255, 0, 0));

			if (Layer->getTileAt(pointA) != nullptr && pointA != pointB) {
				Layer->getTileAt(pointA)->setColor(Color3B(255, 255, 255));
			}
			pointA = pointB;
		}
		
	};


	// OpenGL坐标转成格子坐标
	Vec2 Map::tileCoordForPosition(const Vec2& position)
	{
		int x = position.x / mapTileSize.width;
		int y = (layerSize.height * mapTileSize.height - position.y) / mapTileSize.height;
		return Vec2(x, y);
	}
	// tile坐标转成瓦片格子中心的OpenGL坐标
	Vec2 Map::positionForTileCoord(const Vec2& tileCoord)
	{
		int x = tileCoord.x * mapTileSize.width + mapTileSize.width / 2;
		int y = (layerSize.height - tileCoord.y) * mapTileSize.height - mapTileSize.height / 2;
		return Vec2(x, y);
	}


	Vec2 Map::getPositionForStaggeredAt(const Vec2& position) {
		return Vec2((position.x * mapTileSize.width) + ((int)position.y & 1) * mapTileSize.width / 2, (layerSize.height - position.y - 1) * (mapTileSize.height / 2));
	}

	// OpenGL坐标转成格子坐标
	Vec2 Map::staggeredCoordForPosition(cocos2d::Vec2 position)
	{
		int y = layerSize.height - 2 - ((2 * (int)position.y) / (int)mapTileSize.height);
		float x = position.x / mapTileSize.width - (y % 2) / 2.0f;
		return Vec2((int)x, (int)y);
	}
	// tile坐标转成瓦片格子中心的OpenGL坐标
	Vec2 Map::positionForStaggeredCoord(const cocos2d::Vec2& StaggeredCoord)
	{
		int x = StaggeredCoord.x*mapTileSize.width + ((int)StaggeredCoord.y % 2)*mapTileSize.width / 2;
		int y = (layerSize.height - (StaggeredCoord.y + 1))*mapTileSize.height / 2 - mapTileSize.height / 2;
		return Vec2(x, y);
	}
}