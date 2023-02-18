#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

struct Player {
	sf::Texture texture;
	sf::Sprite sprite;
	float speedx;
};

void playerInit(Player& player, sf::Vector2f pos, std::string fileName) {
	player.texture.loadFromFile(fileName);
	player.sprite.setTexture(player.texture);
	player.sprite.setPosition(pos);
	player.speedx = 0.f;
}

void playerUpdate(Player& player) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			player.speedx = -PLAYER_SPEEDX;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			player.speedx = PLAYER_SPEEDX;
		player.sprite.move(player.speedx, 0.f);
		player.speedx = 0.f;

		float playerx = player.sprite.getPosition().x;
		float playery = player.sprite.getPosition().y;
		if (playerx <= LEFT_ROAD_SIDE) player.sprite.setPosition(LEFT_ROAD_SIDE, playery);
		if (playerx >= LEFT_ROAD_SIDE + RIGHT_ROAD_SIDE - PLAYER_WIDTH) 
			player.sprite.setPosition( RIGHT_ROAD_SIDE + 6, playery);
}

void playerDraw(sf::RenderWindow& window, Player& player) {
	window.draw(player.sprite);
}