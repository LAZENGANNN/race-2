#include "SFML/Graphics.hpp"
#include "settings.h"

struct RoadLayer {
	sf::Texture texture;
	sf::Sprite sprite;
	float offsetX;
};

void roadLayerInit(RoadLayer& layer, sf::Vector2f pos, std::string fileName, float offset) {
	layer.texture.loadFromFile(fileName);
	layer.sprite.setTexture(layer.texture);
	layer.sprite.setPosition(pos);
	layer.offsetX = offset;
}

void roadLayerUpdate(RoadLayer& layer) {
	layer.sprite.move(0.f, ROAD_LAYER_SPEED);
	if (layer.sprite.getPosition().y >= WINDOW_HEIGHT) {
		layer.sprite.setPosition(layer.offsetX, -WINDOW_HEIGHT);
	}
}

void roadLayeDraw(sf::RenderWindow& window, const RoadLayer& layer) {
	window.draw(layer.sprite);
}
