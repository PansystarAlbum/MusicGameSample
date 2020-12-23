#include <Windows.h>

#include "DxLib.h"

#include "Defines.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	ChangeWindowMode(1);

	SetGraphMode(GAME_DRAW_SCREEN_WIDTH, GAME_DRAW_SCREEN_HEIGHT, 32);
	SetWindowSize(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
	SetFontSize(72);

	SetOutApplicationLogValidFlag(FALSE);
	
	DxLib_Init();

	bool isExit = false;

	while (!isExit) {
		if (ProcessMessage()) {
			break;
		}

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			isExit = true;
		}
			   
		ClearDrawScreen();

		DrawString(0, 0, "Hello, world.", 0xFFFFFF);




		ScreenFlip();
	}


	DxLib_End();

	return 0;
}