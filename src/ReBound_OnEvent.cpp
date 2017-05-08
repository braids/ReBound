#include "ReBound.h"

void ReBound::OnEvent(SDL_Event* Event) {
	// Handle general events
	switch (Event->type) {
		case SDL_QUIT:
			Running = false;
			break;
		case SDL_KEYDOWN:
			if (Event->key.keysym.sym == SDLK_SPACE && Playing == false) {
				Playing = true;
				GameBallPauseTimer = 1000;
				BluePaddle->Reset();
				RedPaddle->Reset();
				GameBall->Reset();
				ScoreClear();
			}	
			if (Event->key.keysym.sym == SDLK_ESCAPE && Playing == false)
				Running = false;
			if (Event->key.keysym.sym == SDLK_ESCAPE && Playing == true)
				Playing = false;
			if (Event->key.keysym.sym == SDLK_r && Playing == true) {
				GameBallPauseTimer = 1000;
				BluePaddle->Reset();
				RedPaddle->Reset();
				ScoreClear();
				GameBall->Reset();
			}
			break;
		default:
			break;
	}

	// Game object event handling
	BluePaddle->HandleEvent(Event);
	RedPaddle->HandleEvent(Event);
}
