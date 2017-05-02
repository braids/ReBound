#include <cmath>
#include "ReBound_GameObject.h"

// Ball generic Ctor. Don't use this, please!
Ball::Ball() {
	BallPause = true;
	Name = NULL;
	Texture = NULL;
	DrawArea = NULL;
	posX = 0;
	posY = 0;
	velX = sin(0);
	velY = cos(0);
	Speed = 0;
}

// Ball Ctor. Creates ball with specified texture.
Ball::Ball(SDL_Texture* texture) {
	BallPause = true;
	Name = "Ball";
	Texture = texture;
	posX = 417;
	posY = 230;
	velX = sin(45 * M_PI / 180);	// Starting magic angle
	velY = cos(45 * M_PI / 180);
	DrawArea = new SDL_Rect();
	Speed = .5;
}

// Get current angle of ball.
float Ball::Angle() {
	return atan2(velX, velY) * 180 / M_PI;
}

// Set angle of ball.
float Ball::SetAngle(float angle) {
	velX = sin(angle * M_PI / 180);
	velY = cos(angle * M_PI / 180);
	return angle;
}

// Update ball movement.
void Ball::MoveUpdate(float timeStep) {
	// Update X/Y coords
	posX += velX * Speed * timeStep;
	posY += velY * Speed * timeStep;

	// If hitting ceiling, bounce down.
	if (posY < 0) {
		posY = 0;
		velY *= -1;
	}
	// If hitting floor, bounce up.
	if (posY >= 460) {
		posY = 460;
		velY *= -1;
	}
}

// Ball actions when colliding with paddle.
void Ball::PaddleCollide(Paddle* paddle) {
	if (SDL_HasIntersection(DrawArea, paddle->GetDrawArea())) {
		Speed += .07; // The acceleration never stops!
		
		// Get collision rectangle.
		SDL_Rect* CollisionBox = new SDL_Rect();
		SDL_IntersectRect(DrawArea, paddle->GetDrawArea(), CollisionBox);
		// Paddle drawbox rect x center.
		float PaddleCenterX = paddle->GetDrawArea()->x + (paddle->GetDrawArea()->h / 2);
		// Collision intersection rect x center.
		float CollisionCenterX = CollisionBox->x + (CollisionBox->h / 2);
		
		// If collision box center x is less than the paddle center x (higher up)
		if (CollisionCenterX < PaddleCenterX - 5) {
			// Set angle to absolute angle and add collision center distance from paddle center (minus deadzone)
			SetAngle(abs(Angle()) + (PaddleCenterX - CollisionCenterX - 5));
			// If angle is too high or went negative from addition, set to max angle.
			if (Angle() > 150 || Angle() < 0)
				SetAngle(150);
		}
		// If collision box center x is more than the paddle center x (lower down)
		else if (CollisionCenterX > PaddleCenterX + 5) {
			// Set angle to absolute angle and subtract collision center distance from paddle center (minus deadzone)
			SetAngle(abs(Angle()) - (CollisionCenterX - PaddleCenterX - 5));
			// If current angle is too low, set to min angle.
			if (Angle() < 30)
				SetAngle(30);
		}
		else {
			// If the deadzone is hit (10-width diameter at center of paddle) send ball forward.
			SetAngle(90);
		}

		// Set ball position to front of left paddle.
		if (paddle->Player == 1) 
			posX = paddle->GetDrawArea()->x + paddle->GetDrawArea()->w;
		// Set ball position to front of right paddle (and reverse angle).
		if (paddle->Player == 2) {
			SetAngle(-Angle());
			posX = paddle->GetDrawArea()->x - DrawArea->w;
		}
	}
}

void Ball::Reset() {
	posX = 417;
	posY = 230;
	BallPause = true;
	Speed = .5;
}