#include <iostream>
#include <DxLib.h>


bool SysInit(void)
{
	SetGraphMode(640, 480, 32);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		return false;
	}
	return true;
}


//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int nCmdShow)
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	if (!SysInit())
	{
		return -1;
	}
	while (ProcessMessage() == 0 && (CheckHitKey(KEY_INPUT_ESCAPE)) == 0)
	{
		ClearDrawScreen();
		ScreenFlip();
		//OutputDebugStringA();
	}
	return 0;
	DxLib_End();
}

