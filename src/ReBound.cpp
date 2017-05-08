#include "ReBound.h"

ReBound::ReBound() {
	// Set window and renderer to null
	mGraphics = NULL;
	mAssets = NULL;
	// Set game running/playing flags
	Running = true;
	Playing = false;
	// Set timer values
	currTick = 0;
	lastTick = 0;
	GameBallPauseTimer = 1000;
}

void ReBound::ScoreClear() {
	RedPaddle->Score = 0;
	BluePaddle->Score = 0;
	snprintf(ScoreText,
		sizeof(char) * SCORE_TEXT_BUFFER,
		"%s%d-%d%s",
		BluePaddle->Score < 10 ? " " : "", // If score is less than 10, add a spacer
		BluePaddle->Score,
		RedPaddle->Score,
		RedPaddle->Score < 10 ? " " : "");
	ScoreTexture = mGraphics->LoadText(ScoreFont, ScoreText, 255, 255, 255, 0);
}

void ReBound::ScoreUpdate(Paddle* paddle) {
	paddle->Score += 1;
	snprintf(ScoreText,
		sizeof(char) * SCORE_TEXT_BUFFER,
		"%s%d-%d%s",
		BluePaddle->Score < 10 ? " " : "", // If score is less than 10, add a spacer
		BluePaddle->Score,
		RedPaddle->Score,
		RedPaddle->Score < 10 ? " " : "");
	ScoreTexture = mGraphics->LoadText(ScoreFont, ScoreText, 255, 255, 255, 0);
}

int ReBound::OnExecute() {
	// Initialize everything
	if (OnInit() == false) {
		return -1;
	}
	
	SDL_Event Event;

	// Main loop
	while (Running) {
		// Check events
		while (SDL_PollEvent(&Event)) {
			OnEvent(&Event);
		}
		// Perform actions and updates
		OnLoop();
		// Render scene
		OnRender();
	}

	// De-initialize SDL and SDL_TTF
	OnCleanup();

	return 0;
}

int main(int argc, char* argv[]) {
	ReBound rb;

	return rb.OnExecute();
}
