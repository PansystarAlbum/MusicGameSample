#include <Windows.h>

#include "DxLib.h"

#include "Defines.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetOutApplicationLogValidFlag(FALSE);

	SetMainWindowText("C++");

	ChangeWindowMode(1);

	SetGraphMode(1920, 1080, 32);
	SetWindowSize(960, 540);
	SetFontSize(72);
	SetAlwaysRunFlag(TRUE);

	
	DxLib_Init();

	bool isExit = false;

	while (!isExit) {
		if (ProcessMessage() != 0) {
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