#include "ReBound.h"

void ReBound::OnRender() {
	// Clear render buffer
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
	SDL_RenderClear(Renderer);
	
	// Draw BG
	SDL_RenderCopy(Renderer, BG, NULL, NULL);
	// Draw score on BG
	SDL_RenderCopy(Renderer, text, NULL, textRenderQuad);	
	// Draw game objects
	RenderGameObjects();

	// Scale screen to desktop resolution
	SDL_RenderSetScale(Renderer, DScaleXRatio(), DScaleYRatio());

	// Draw render buffer to screen
	SDL_RenderPresent(Renderer);
}

void ReBound::RenderGameObjects() {
	SDL_RenderCopy(Renderer, GameBall->GetTexture(), NULL, GameBall->GetDrawArea());
	SDL_RenderCopy(Renderer, BluePaddle->GetTexture(), NULL, BluePaddle->GetDrawArea());
	SDL_RenderCopy(Renderer, RedPaddle->GetTexture(), NULL, RedPaddle->GetDrawArea());
}
