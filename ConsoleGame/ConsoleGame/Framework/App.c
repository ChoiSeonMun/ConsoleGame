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
	sprintf_s(str, sizeof(str), "���� �Է� ����");

	if (Input_GetKey(VK_UP))
	{
		sprintf_s(str, sizeof(str), "���� ȭ��ǥ ����");
	}
	
	if (Input_GetKey(VK_DOWN))
	{
		sprintf_s(str, sizeof(str), "�Ʒ��� ȭ��ǥ ����");
	}

	if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_RIGHT))
	{
		sprintf_s(str, sizeof(str), "����, ������ ȭ��ǥ ���� ����");
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

	// Game Loop : ������ ���۽�Ű�� ����. ������(Frame)�̶�� �Ѵ�.
	while (true)
	{
		// �ð��� ������Ʈ ���� ������ ���� ���� ����
		if (Timer_Update())
		{
			processInput();		// �Է� ó��
			update();			// ���� ������Ʈ
			render();			// ���� ���
		}
	}

	return 0;
}