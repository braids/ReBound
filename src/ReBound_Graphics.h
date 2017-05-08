#ifndef _REBOUND_GRAPHICS_H_
#define _REBOUND_GRAPHICS_H_

#include <cstdio>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Graphics {
private:
	static Graphics* sInstance;
	static bool sInitialized;

	SDL_Window* mWindow;
	SDL_Surface* mBackBuffer;

	SDL_Renderer* mRenderer;

	Graphics();
	~Graphics();
	bool Init();

	static float DScaleXRatio() { return ((float)SCREEN_WIDTH) / ((float)GAMEAREA_WIDTH); }
	static float DScaleYRatio() { return ((float)SCREEN_HEIGHT) / ((float)GAMEAREA_HEIGHT); }

public:
	static const int GAMEAREA_WIDTH = 854;
	static const int GAMEAREA_HEIGHT = 480;
	static const int SCREEN_WIDTH = 1920;
	static const int SCREEN_HEIGHT = 1080;
	
	static Graphics* Instance();
	static void Release();
	static bool Initialized();

	TTF_Font* LoadFont(std::string filePath, int size);

	SDL_Texture* LoadTexture(std::string filePath);

	SDL_Texture* LoadText(TTF_Font* font, std::string text, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	void ClearBackBuffer();

	static SDL_Rect* CenterTextureRectX(SDL_Texture* texture, int y);

	void DrawTexture(SDL_Texture* texture);

	void DrawTexture(SDL_Texture * texture, SDL_Rect * rect);

	void Render();
};

#endif
