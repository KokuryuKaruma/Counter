/*
モード制御
*/

#include "stdafx.h"
#include "DxLib.h"
#include "ProgramMode.h" /*モード設定*/
#include "CounterProgram.h"


static int modeNum = 0; /*現在のモード番号*/
int modeInit()
{
	modeNum = mode_CounterInit;
	return 0;
}

//static int inGame = false;
int modeCtrl(int foo)
{
	int ret = FALSE;

	switch (modeNum) {
	case mode_CounterInit:
	{
		ret = Counter_Init();
	} break;
	case mode_CounterDisp:
	{
		ret = Counter_Disp();
	} break;
	case mode_CounterFinish:
	{
		ret = Counter_Finish();
	} break;

	default:
	{
		modeNum = mode_CounterInit;
	} break;
	}

#if DEBUG
	DrawFormatString(0, 0, GetColor(255, 255, 255), (const TCHAR*)"MODE: %d", modeNum);
#endif

	if (ret > modeseq_Thuru)
	{
		modeNum = modeNum + ret;
		ret = 0;
	}
	else if (ret < modeseq_Thuru)
	{
		return ret;
	}

	return ret;
}
