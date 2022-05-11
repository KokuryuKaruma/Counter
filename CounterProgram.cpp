#include "DxLib.h"
#include "CounterProgram.h"
#include "ProgramMode.h"

static int Color_Black;
static int HatsuAtari_Count = 0;
static int Keizoku_Count = 0;

static int n = 0;
static int m = 0;
static int l = 0;

int Counter_Init(void)
{
	/*フォントのデータを取得*/
	Color_Black = GetColor(0, 0, 0);
	SetFontSize(60);
	SetFontThickness(8);

	return modeseq_Increase;
}

int Counter_Disp(void)
{

	if (CheckHitKey(KEY_INPUT_1) == 1)
	{
		if (m == 0) {
			HatsuAtari_Count++; // 押されている
			m++;
		}
	}
	if (CheckHitKey(KEY_INPUT_2) == 1)
	{
		if (m == 0) {
			Keizoku_Count++; // 押されている
			m++;
		}
	}

	if (CheckHitKey(KEY_INPUT_3) == 1) {
		m = 0;
	}

	if (CheckHitKey(KEY_INPUT_4) == 1) {
		Keizoku_Count = 0;
	}

	DrawFormatString(65, 150,Color_Black ,"%d", HatsuAtari_Count);

	DrawFormatString(65, 365,Color_Black ,"%d", Keizoku_Count);

	if (n == 1) {
		return modeseq_Increase;
	}
	else {
		return modeseq_Thuru;
	}
}

int Counter_Finish(void)
{
	return modeseq_Increase;
}