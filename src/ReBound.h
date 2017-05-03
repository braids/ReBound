#ifndef _CAPP_H_
#define _CAPP_H_

#define GAME_AREA_W 854
#define GAME_AREA_H 480

#define DESKTOP_AREA_W 854
#define DESKTOP_AREA_H 480

#define SCORE_TEXT_BUFFER 10
#define SDL_MAIN_HANDLED

#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "ReBound_GameObject.h"

class ReBound {
private:
	// Running Flag
	bool            Running;

	// Window
	SDL_Window*		Window;
	SDL_Renderer*   Renderer;

	// Background image
	SDL_Texture*	BG;

	// Game Objects
	Paddle*			BluePaddle;
	Paddle*			RedPaddle;
	Ball*			GameBall;

	// Timer Vars
	Uint32			currTick;
	Uint32			lastTick;
	Uint32			GameBallPauseTimer;

	// Score Text
	TTF_Font*		font;
	SDL_Color		textColor;
	SDL_Surface*	textSurface;
	SDL_Texture*	text;
	SDL_Rect*		textRenderQuad;
	char			scoreOutput[SCORE_TEXT_BUFFER];

public:
	ReBound();

	int OnExecute();

	bool OnInit();

	void OnEvent(SDL_Event* Event);

	void OnLoop();

	void OnRender();

	void RenderGameObjects();

	void OnCleanup();

	SDL_Texture* LoadTexture(const char* file) { return IMG_LoadTexture(this->Renderer, file); }

	static float DScaleXRatio() { return ((float) DESKTOP_AREA_W) / ((float) GAME_AREA_W); }

	static float DScaleYRatio() { return ((float) DESKTOP_AREA_H) / ((float) GAME_AREA_H); }

	void ScoreUpdate();
};

#endif
