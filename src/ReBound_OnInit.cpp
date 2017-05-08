#include "ReBound.h"
#include "ReBound_AssetDefines.h"
bool ReBound::OnInit() {
	printf("Init\n");
	
	// Initialize graphics
	mGraphics = Graphics::Instance();

	// Initialize assets
	mAssets = Assets::Instance();

	// Load Logo
	Logo = Assets::Instance()->GetTexture(IMAGE_LOGO);

	// Load BG
	BG = Assets::Instance()->GetTexture(IMAGE_BACKGROUND);

	// Create game objects
	BluePaddle = new Paddle(1, Assets::Instance()->GetTexture(IMAGE_BLUEPADDLE));
	RedPaddle = new Paddle(2, Assets::Instance()->GetTexture(IMAGE_REDPADDLE));
	GameBall = new Ball(Assets::Instance()->GetTexture(IMAGE_BALL));

	// Init menu text
	StartFont = Assets::Instance()->GetFont(FONT_PONGFONT, 80);
	StartTexture = mGraphics->LoadText(StartFont, StartText, 255, 255, 255, 0);

	// Initialize score
	ScoreFont = Assets::Instance()->GetFont(FONT_PONGFONT, 40);
	ScoreClear();
	
	return true;
}
