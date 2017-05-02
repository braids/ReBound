#include "ReBound_GameObject.h"

// General Ctor. Should never be used ever.
Paddle::Paddle() {
	Name = NULL;
	Player = 0;
	Score = 0;
	Texture = NULL;
	DrawArea = NULL;
	MoveUp = false;
	MoveDown = false;
	posX = 0;
	posY = 0;
	velX = 0;
	velY = 0;
}

// Paddle Ctor. Specify a player number and texture to use to initialize that player.
Paddle::Paddle(int player, SDL_Texture* texture) {
	if (player == 1) {
		Name = "Blue Paddle";
		Player = 1;
		posX = 20;	// Left side of arena
	}
	if (player == 2) {
		Name = "Red Paddle";
		Player = 2;
		posX = 814;	// Right side of arena
	}
	Score = 0;
	Texture = texture;
	DrawArea = new SDL_Rect();
	posY = 200;	// Center
	velX = 0;
	velY = .7;	// Magic velocity number
	MoveUp = false;
	MoveDown = false;
}

void Paddle::HandleEvent(SDL_Event* e) {
	switch (e->type) {
		case SDL_KEYDOWN:
			// Blue paddle
			if (Player == 1) {
				// Q: Move paddle up
				if (e->key.keysym.sym == SDLK_q)
					MoveUp = true;
				// A: Move paddle down
				if (e->key.keysym.sym == SDLK_a)
					MoveDown = true;
			}
			// Red Paddle
			if (Player == 2) {
				// P: Move paddle up
				if (e->key.keysym.sym == SDLK_p)
					MoveUp = true;
				// L: Move paddle down
				if (e->key.keysym.sym == SDLK_l)
					MoveDown = true;
			}
			break;
		case SDL_KEYUP:
			// Blue Paddle
			if (Player == 1) {
				// ^Q: Stop moving paddle up
				if (e->key.keysym.sym == SDLK_q)
					MoveUp = false;
				// ^A: Stop moving paddle down
				if (e->key.keysym.sym == SDLK_a)
					MoveDown = false;
			}
			// Red Paddle
			if (Player == 2) {
				// ^P: Stop moving paddle up
				if (e->key.keysym.sym == SDLK_p)
					MoveUp = false;
				// ^L: Stop moving paddle down
				if (e->key.keysym.sym == SDLK_l)
					MoveDown = false;
			}
			break;
		default:
			break;
	}
}

void Paddle::MoveUpdate(float timeStep) {
	// Moving up, lower Y by velocity adjusted for cycle time
	if (MoveUp)
		posY += -velY * timeStep;
	// Moving down, raise Y by velocity adjusted for cycle time
	if (MoveDown)
		posY += velY * timeStep;
	// Stop paddle if too high
	if (posY < 5)
		posY = 5;
	// Stop paddle if too low
	if (posY > 395)
		posY = 395;
}

