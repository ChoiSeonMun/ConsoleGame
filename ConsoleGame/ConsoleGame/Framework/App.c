#include "App.h"
#include "Common.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"

bool App_Init()
{
	if (false == Renderer_Init())
	{
		return false;
	}

	return true;
}

void processInput()
{
	Input_Update();
}

char str[128];
void update()
{
	sprintf_s(str, sizeof(str), "현재 입력 없음");

	if (Input_GetKey(VK_UP))
	{
		sprintf_s(str, sizeof(str), "위쪽 화살표 눌림");
	}
	
	if (Input_GetKey(VK_DOWN))
	{
		sprintf_s(str, sizeof(str), "아래쪽 화살표 눌림");
	}

	if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_RIGHT))
	{
		sprintf_s(str, sizeof(str), "왼쪽, 오른쪽 화살표 동시 눌림");
	}
}

void render()
{
	Renderer_DrawText(str, strlen(str));
	Renderer_Flip();
}

void cleanup()
{
	Renderer_Cleanup();
}

int32 App_Run()
{
	atexit(cleanup);

	Timer_Init(60);

	// Game Loop : 게임을 동작시키는 루프. 프레임(Frame)이라고 한다.
	while (true)
	{
		// 시간이 업데이트 됐을 때에만 게임 루프 실행
		if (Timer_Update())
		{
			processInput();		// 입력 처리
			update();			// 게임 업데이트
			render();			// 게임 출력
		}
	}

	return 0;
}