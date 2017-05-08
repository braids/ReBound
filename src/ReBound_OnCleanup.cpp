#include "ReBound.h"

void ReBound::OnCleanup() {
	Graphics::Release();
	mGraphics = NULL;

	Assets::Release();
	mAssets = NULL;
}
