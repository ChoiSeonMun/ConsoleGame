#include "App.h"
#include "Common.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"
#include "Random.h"
#include "Text.h"

bool App_Init()
{
	if (false == Renderer_Init())
	{
		return false;
	}

	Random_Init();

	return true;
}

void processInput()
{
	Input_Update();
}

Text text[128];
void update()
{
	TextCopy(text, L"우리반의 존잘은 안재현이다.");
	for (int32 i = 9; text[i].Char.UnicodeChar != L'\0'; ++i)
	{
		text[i].Attributes = BACK_COLOR_RED | TEXT_COLOR_WHITE | TEXT_COLOR_STRONG;
	}
}

void render()
{
	Renderer_DrawText(text, TextLen(text), 10, 10);
	Renderer_Flip();
}

void cleanup(void)
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