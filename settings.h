#pragma once
#include "SFML/Graphics.hpp"

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 1000;
const std::string WINDOW_TITLE = "SFML Race P33022";
const float FPS = 60.f;

const float ROAD_LAYER_SPEED = 7.f;
const float ROAD_OFFSET = 100.f;
const float LEFT_ROAD_SIDE = 100.f;
const float RIGHT_ROAD_SIDE = 400.f;
const float  ROAD_LANE_WIDTH = 75.f;

const float PLAYER_WIDTH = 90.f;
const float PLAYER_HEIGHT = 188.f;
const std::string PLAYER_FILE_NAME = "car1.png";
const sf::Vector2f PLAYER_START_POS{ (WINDOW_WIDTH - 80.f) / 2.f,WINDOW_HEIGHT- PLAYER_HEIGHT - 10};
const float PLAYER_SPEEDX = 7.f;

const float OBS_HEIGHT = 85.f;

const int CHAR_SIZE = 48;
const float TEXT_OFFSET = 60.f;
const sf::Vector2f TEXT_START_POS{ WINDOW_WIDTH - TEXT_OFFSET, 0.f };
