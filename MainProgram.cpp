// miniWinGame1.cpp : アプリケーションのエントリ ポイントを定義します。
//


/*
* Project -> Property -> 全般 -> 文字セット -> マルチバイト文字セットを使用する
*
*
*
*
*
*
*/
#include "stdafx.h"
#include "DxLib.h"
#include "MainProgram.h"
#include "ProgramMode.h" /*モード設定*/
#include "ProgramInput.h" /*入力ペリフェラル*/

#define MAX_LOADSTRING 100

// グローバル変数:
HINSTANCE hInst;                                // 現在のインターフェイス
WCHAR szTitle[MAX_LOADSTRING];                  // タイトル バーのテキスト
WCHAR szWindowClass[MAX_LOADSTRING];            // メイン ウィンドウ クラス名

// このコード モジュールに含まれる関数の宣言を転送します:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


int count = 0;
int mouseX = 0;//マウス座標
int mouseY = 0;//マウス座標

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);


	// TODO: ここにコードを挿入してください。
	SetGraphMode(ScreenWidth, ScreenHeight, 32);//画面サイズ指定
	SetOutApplicationLogValidFlag(FALSE);//Log.txtを生成しないように設定
	SetBackgroundColor(255, 255, 255);//背景色を白に設定
	ChangeWindowMode(TRUE);//非全画面にセット

	SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);
	if (DxLib_Init() == 1) { return -1; }//初期化に失敗時にエラーを吐かせて終了


	// グローバル文字列を初期化する
	//LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	//LoadStringW(hInstance, IDC_MINIWINGAME1, szWindowClass, MAX_LOADSTRING);
	//MyRegisterClass(hInstance);

	modeInit();
	// メイン ループ:
	int ext;
	while (ProcessMessage() == 0) {
		ClearDrawScreen();//裏画面消す
		SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に
		inputPeripheralUpdate();
		//
		//ここに毎フレーム呼ぶ処理を書く
		//

		ext = modeCtrl(0);

		ScreenFlip();//裏画面を表画面にコピー    
		if (ext) { break; }
	}

	DxLib_End();
	return (int)FALSE;
}



//
//  関数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: メイン ウィンドウのメッセージを処理します。
//
//  WM_COMMAND  - アプリケーション メニューの処理
//  WM_PAINT    - メイン ウィンドウを描画する
//  WM_DESTROY  - 中止メッセージを表示して戻る
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_COMMAND:
	{
	}
	break;
	case WM_PAINT:
	{
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

