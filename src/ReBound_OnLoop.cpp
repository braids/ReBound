#include <string>
#include "ReBound.h"

void ReBound::OnLoop() {
	// Update timeStep by # of ticks from last cycle
	lastTick = currTick;
	currTick = SDL_GetTicks();
	float timeStep = currTick - lastTick;

	// Update paddle movement
	BluePaddle->MoveUpdate(timeStep);
	RedPaddle->MoveUpdate(timeStep);
	
	// Ball pause timer. When above 0, will keep ball from moving.
	if (GameBall->BallPause == true)
		GameBallPauseTimer -= timeStep;
	if (GameBallPauseTimer <= 0)
		GameBall->BallPause = false;

	// If ball is not paused
	if (GameBall->BallPause == false) {
		// Reset ball pause timer
		GameBallPauseTimer = 1000;
		
		// Move ball
		GameBall->MoveUpdate(timeStep);
		
		// If ball lands in Blue Paddle goal
		if (GameBall->GetDrawArea()->x < 0) {
			// Update Red Paddle score
			RedPaddle->Score += 1;
			ScoreUpdate();
			textSurface = TTF_RenderText_Solid(font, scoreOutput, textColor);
			text = SDL_CreateTextureFromSurface(Renderer, textSurface);
			SDL_FreeSurface(textSurface);
			
			// Reset ball to center
			GameBall->Reset();
		}
		
		// If ball lands in Red Paddle goal
		if (GameBall->GetDrawArea()->x >= 834) {
			// Update Red Paddle score
			BluePaddle->Score += 1;
			ScoreUpdate();
			textSurface = TTF_RenderText_Solid(font, scoreOutput, textColor);
			text = SDL_CreateTextureFromSurface(Renderer, textSurface);
			SDL_FreeSurface(textSurface);
			
			// Reset ball to center
			GameBall->Reset();
		}

		// Check for ball colliding with paddles.
		GameBall->PaddleCollide(BluePaddle);
		GameBall->PaddleCollide(RedPaddle);
	}
}
