#include "settings.h"
#include "road.h"
#include "player.h"
#include "obstacle.h"
#include "ctime"
#include "textObj.h"

using namespace sf;

int main()
{
	srand(time(nullptr));
	// Îáúåêò, êîòîðûé, ñîáñòâåííî, ÿâëÿåòñÿ ãëàâíûì îêíîì ïðèëîæåíèÿ
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE,
		Style::Titlebar | Style::Close
	);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2, 0 });
	window.setFramerateLimit(FPS);

	RoadLayer grass1, grass2;
	RoadLayer road1, road2;
	roadLayerInit(grass1, Vector2f{ 0.f,0.f }, "grass.jpg", 0.f);
	roadLayerInit(grass2, Vector2f{ 0.f,-WINDOW_HEIGHT }, "grass.jpg", 0.f);
	roadLayerInit(road1, Vector2f{ ROAD_OFFSET,0.f }, "road.jpg", ROAD_OFFSET);
	roadLayerInit(road2, Vector2f{ ROAD_OFFSET,-WINDOW_HEIGHT }, "road.jpg", ROAD_OFFSET);
	Player player;
	playerInit(player, PLAYER_START_POS, "car1.png");
	Obstacle obs1;
	Obstacle obs2;
	Obstacle obs3;
	obstacleInit(obs1, "box.png");
	obstacleInit(obs2, "box.png");
	obstacleInit(obs3, "box.png");
	int HP = 3;
	int score = 0;
	TextObj scoreText;
	textInit(scoreText, score);



	while (window.isOpen())
	{


		// Îáðàáàòûâàåì î÷åðåäü ñîáûòèé â öèêëå
		Event event;
		while (window.pollEvent(event))
		{
			// Ïîëüçîâàòåëü íàæàë íà «êðåñòèê» è õî÷åò çàêðûòü îêíî?
			if (event.type == Event::Closed)
				// òîãäà çàêðûâàåì åãî
				window.close();
		}
		//Update
		roadLayerUpdate(grass1);
		roadLayerUpdate(grass2);
		roadLayerUpdate(road1);
		roadLayerUpdate(road2);
		playerUpdate(player);
		obstacleUpdate(obs1);
		obstacleUpdate(obs2);
		obstacleUpdate(obs3);	
		//проверка столкновения игрока и препятствий
		FloatRect playerHitBox = player.sprite.getGlobalBounds();
		FloatRect obs1HitBox = obs1.sprite.getGlobalBounds();
		FloatRect obs2HitBox = obs2.sprite.getGlobalBounds();
		FloatRect obs3HitBox = obs3.sprite.getGlobalBounds();
		if (playerHitBox.intersects(obs1HitBox)) {
			window.close();
		}
		if (playerHitBox.intersects(obs2HitBox)) {
			window.close();
		}
		if (playerHitBox.intersects(obs3HitBox)) {
			window.close();
		}
		textUpdate(scoreText, score);
		/*if (player.sprite.getPosition().y + PLAYER_HEIGHT < obs1.sprite.getPosition().y + OBS_HEIGHT) {
			score += 1;
			break;
		}*/

		/*if (playerHitBox.intersects(obs1HitBox)) {
			HP--;
		}
		if (playerHitBox.intersects(obs2HitBox)) {
			HP--;
		}
		if (playerHitBox.intersects(obs3HitBox)) {
			HP--;
		}
		if (HP <= 0) window.close();*/

		// Îòðèñîâêà îêíà
		window.clear();
		roadLayeDraw(window, grass1);
		roadLayeDraw(window, grass2);
		roadLayeDraw(window, road1);
		roadLayeDraw(window, road2);
		playerDraw(window, player);
		obstacleDraw(window, obs1);
		obstacleDraw(window, obs2);
		obstacleDraw(window, obs3);
		textDraw(window, scoreText);
		window.display();
	}
	return 0;
}