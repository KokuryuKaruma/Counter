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
	modeseq_Thuru = 0,/* mode�J�ڕύX�Ȃ� */
	modeseq_Exit = -1,/* mode�J�ڏI�� */
	modeseq_Increase = 1,/* mode�J�ڎ��� */
	modeseq_Game = 2,/* mode�J�ڃQ�[����*/
};

// function prototype
int modeInit(void);	// ���[�h����̏�����
int modeCtrl(int foo);// ���[�h����