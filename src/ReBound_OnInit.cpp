#include "ReBound.h"

bool ReBound::OnInit() {
	// SDL Initialization
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

	// SDL_TTF Initialization
	if (TTF_Init() < 0) 
		return false;

	// Create window
	if ((Window = SDL_CreateWindow("ReBound", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DESKTOP_AREA_W, DESKTOP_AREA_H, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS)) == NULL)
		return false;

	// Create renderer
	if ((Renderer = SDL_CreateRenderer(Window, -1, 0)) == NULL)
		return false;

	// Load BG texture
	BG = LoadTexture("bg.png");

	// Create game objects
	BluePaddle = new Paddle(1, LoadTexture("bluepaddle.png"));
	RedPaddle = new Paddle(2, LoadTexture("redpaddle.png"));
	GameBall = new Ball(LoadTexture("ball.png"));

	// Initialize score
	ScoreUpdate();
	font = TTF_OpenFont("pongfont.ttf", 40);
	textColor.r = 255;
	textColor.g = 255;
	textColor.b = 255;
	textColor.a = 0;
	textSurface = TTF_RenderText_Solid(font, scoreOutput, textColor);
	text = SDL_CreateTextureFromSurface(Renderer, textSurface);
	textRenderQuad = new SDL_Rect();
	textRenderQuad->x = 427 - (textSurface->w / 2);
	textRenderQuad->y = 30;
	textRenderQuad->w = textSurface->w;
	textRenderQuad->h = textSurface->h;

	return true;
}