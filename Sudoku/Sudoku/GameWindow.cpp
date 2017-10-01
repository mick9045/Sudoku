#include "GameWindow.h"
#include "resource.h"
#include <windowsx.h>

namespace Sudoku
{
	GameWindow::GameWindow()
		:BaseDialogWindow(IDD_DIALOG_MAIN)
	{
	}


	GameWindow::~GameWindow()
	{
	}

	INT_PTR GameWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			HANDLE_MSG(hwnd, WM_CLOSE, Cls_OnClose);
			HANDLE_MSG(hwnd, WM_COMMAND, Cls_OnCommand);
			HANDLE_MSG(hwnd, WM_INITDIALOG, Cls_OnInitDialog);
		default:
			break;
		}
		return FALSE;
	}

	void GameWindow::Cls_OnClose(HWND hwnd)
	{
		Close();
	}
	VOID GameWindow::Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify)
	{
		if (codeNotify == BN_CLICKED)
		{
			switch (id)
			{
			default:
				break;
			}
		}
	}
	BOOL GameWindow::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
	{
		int buttonSize = 45;
		HWND h;
		LPTCH lptchText = new TCHAR[12];
		

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int xPos = buttonSize * j + 5 * int(j / 3);
				int yPos = buttonSize * i + 5 * int(i / 3);
				
				_hButton[i][j] = CreateWindow(
					L"BUTTON",  // Predefined class; Unicode assumed 
					to_tstring(_gameField.Get(j, i)).c_str(),      // Button text 
					WS_TABSTOP | WS_VISIBLE | WS_CHILD,  // Styles 
					xPos,         // x position 
					yPos,         // y position 
					buttonSize,        // Button width
					buttonSize,        // Button height
					hWindow(),     // Parent window
					NULL,       // No menu.
					(HINSTANCE)GetWindowLong(hWindow(), GWL_HINSTANCE),
					NULL);      // Pointer not needed.
			}
		}
		SetFocus(hWindow());
		return FALSE;
	}
}