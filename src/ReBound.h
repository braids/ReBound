#ifndef _REBOUND_H_
#define _REBOUND_H_

# ifndef _MSC_VER
# define SDL_MAIN_HANDLED
# endif

#define SCORE_TEXT_BUFFER 10

#include "ReBound_Graphics.h"
#include "ReBound_GameObject.h"
#include "ReBound_Assets.h"

class ReBound {
private:
	// Running Flag
	bool            Running;
	bool			Playing;

	// Graphics
	Graphics*		mGraphics;

	// Assets
	Assets*			mAssets;
	
	// Logo
	SDL_Texture*	Logo;

	// Start Text
	TTF_Font*		StartFont;
	SDL_Texture*	StartTexture;
	const char*		StartText = "-START-";

	// Background image
	SDL_Texture*	BG;

	// Game Objects
	Paddle*			BluePaddle;
	Paddle*			RedPaddle;
	Ball*			GameBall;

	// Timer Vars
	Uint32			currTick;
	Uint32			lastTick;
	int				GameBallPauseTimer;

	// Score Text
	TTF_Font*		ScoreFont;
	SDL_Texture*	ScoreTexture;
	char			ScoreText[SCORE_TEXT_BUFFER];

public:
	ReBound();

	int OnExecute();

	bool OnInit();

	void OnEvent(SDL_Event* Event);

	void OnLoop();

	void OnRender();

	void RenderGameObjects();

	void OnCleanup();

	void ScoreClear();

	void ScoreUpdate(Paddle* paddle);
};

#endif
