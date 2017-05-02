#include "ReBound.h"

void ReBound::OnEvent(SDL_Event* Event) {
	// Handle general events
	switch (Event->type) {
		case SDL_QUIT:
			Running = false;
			break;
		case SDL_KEYDOWN:
			if (Event->key.keysym.sym == SDLK_ESCAPE)
				Running = false;
			break;
		default:
			break;
	}

	// Game object event handling
	BluePaddle->HandleEvent(Event);
	RedPaddle->HandleEvent(Event);
}