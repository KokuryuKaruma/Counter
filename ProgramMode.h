#pragma once

/*
mode config
*/

enum {
	mode_CounterInit = 1,
	mode_CounterDisp,
	mode_CounterFinish,

};


/*
* mode return value
*/
enum {
	modeseq_Thuru = 0,/* mode遷移変更なし */
	modeseq_Exit = -1,/* mode遷移終了 */
	modeseq_Increase = 1,/* mode遷移次へ */
	modeseq_Game = 2,/* mode遷移ゲームへ*/
};

// function prototype
int modeInit(void);	// モード制御の初期化
int modeCtrl(int foo);// モード制御