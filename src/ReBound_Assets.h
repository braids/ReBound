#ifndef _REBOUND_ASSETS_H_
#define _REBOUND_ASSETS_H_

#include <map>
#include "ReBound_Graphics.h"

typedef std::map<std::string, SDL_Texture*> TextureList;
typedef std::map<std::string, TTF_Font*> FontList;

class Assets {
private:
	static Assets* sInstance;
	TextureList	mTextures;
	FontList	mFonts;
	Assets();
	~Assets();
public:
	static Assets* Instance();
	static void Release();
	SDL_Texture* GetTexture(std::string name);
	TTF_Font* GetFont(std::string name, int size);
};

#endif
