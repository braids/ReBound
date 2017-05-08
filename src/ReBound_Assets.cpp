#include "ReBound_Assets.h"

Assets* Assets::sInstance = NULL;

Assets* Assets::Instance() {
	if (sInstance == NULL)
		sInstance = new Assets();

	return sInstance;
}

void Assets::Release() {
	delete sInstance;
	sInstance = NULL;
}

Assets::Assets() {

}

Assets::~Assets() {
	for (auto tex : mTextures) {
		if (tex.second != NULL)
			SDL_DestroyTexture(tex.second);
	}

	mTextures.clear();

	mFonts.clear();
}

SDL_Texture* Assets::GetTexture(std::string name) {
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("res/img/" + name);

	if (mTextures[fullPath] == NULL)
		mTextures[fullPath] = Graphics::Instance()->LoadTexture(fullPath);

	return mTextures[fullPath];
}

TTF_Font* Assets::GetFont(std::string name, int size) {
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("res/ttf/" + name);
	std::string fullPathSize = fullPath;
	fullPathSize.append(std::to_string(size));

	if (mFonts[fullPathSize] == NULL)
		mFonts[fullPathSize] = Graphics::Instance()->LoadFont(fullPath, size);

	return mFonts[fullPathSize];
}
