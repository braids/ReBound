#ifndef _REBOUND_GAMEOBJECT_H_
#define _REBOUND_GAMEOBJECT_H_

#include "ReBound_Graphics.h"

class GameObject {
protected:
	const char*		Name;

	SDL_Texture*	Texture;

	SDL_Rect*		DrawArea;

	float			posX, posY;

	float			velX, velY;

public:
	GameObject();

	GameObject(const char* name, SDL_Texture* texture, int x, int y);

	const char* GetName();

	SDL_Texture* GetTexture();

	SDL_Rect* GetDrawArea();
};

class Paddle : public GameObject {
public:
	Paddle();

	Paddle(int player, SDL_Texture* texture);

	int				Player;

	int				Score;

	bool			MoveUp;

	bool			MoveDown;

	void HandleEvent(SDL_Event* e);

	void MoveUpdate(float timeStep);
	void Reset();
};

class Ball : public GameObject {
public:
	Ball();

	Ball(SDL_Texture* texture);

	float Speed;

	float Angle();

	bool BallPause;

	float SetAngle(float angle);

	void MoveUpdate(float timeStep);

	void PaddleCollide(Paddle* paddle);

	void Reset();
};

#endif
