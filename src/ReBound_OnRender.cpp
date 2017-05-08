#include "ReBound.h"

void ReBound::OnRender() {
	mGraphics->ClearBackBuffer();

	if (Playing) {
		mGraphics->DrawTexture(BG);
		mGraphics->DrawTexture(ScoreTexture, Graphics::CenterTextureRectX(ScoreTexture, 30));
		RenderGameObjects();
	}
	else {
		mGraphics->DrawTexture(Logo, Graphics::CenterTextureRectX(Logo, 10));
		mGraphics->DrawTexture(StartTexture, Graphics::CenterTextureRectX(StartTexture, 350));
	}

	mGraphics->Render();
}

void ReBound::RenderGameObjects() {
	mGraphics->DrawTexture(GameBall->GetTexture(), GameBall->GetDrawArea());
	mGraphics->DrawTexture(BluePaddle->GetTexture(), BluePaddle->GetDrawArea());
	mGraphics->DrawTexture(RedPaddle->GetTexture(), RedPaddle->GetDrawArea());
}
