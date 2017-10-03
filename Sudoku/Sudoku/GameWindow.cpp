#include "GameWindow.h"
#include "resource.h"
#include <windowsx.h>

namespace Sudoku
{
	GameWindow::GameWindow()
		:BaseDialogWindow(IDD_DIALOG_MAIN)
	{
		_selectedIndex = { -1, -1 };
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
			HANDLE_MSG(hwnd, WM_PARENTNOTIFY, Cls_OnParentNotify);
		case WM_NUMBER_SELECTED:
			NumberSelected();
			break;

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
			_selectedIndex = FindButton(hwndCtl);
			if (!_gameField.IsGuessed(_selectedIndex.x, _selectedIndex.y))
			{
				return;
			}
			_numberSelectWindow.Create(hWindow());
			POINT p;
			GetCursorPos(&p);
			_numberSelectWindow.SetPos(p.x, p.y);
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

	POINT GameWindow::FindButton(HWND hWindow)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (_hButton[i][j] == hWindow)
				{
					return{ j, i };
				}
			}
		}
		return{ -1, -1 };
	}

	void GameWindow::Cls_OnParentNotify(HWND hwnd, UINT msg, HWND hwndChild, int idChild)
	{
	}

	void GameWindow::NumberSelected()
	{
		if (_selectedIndex.x >= 0)
		{
			_gameField.Set(_selectedIndex.x,_selectedIndex.y, _numberSelectWindow.SelectedNumber());

			SetWindowText(
				_hButton[_selectedIndex.y][_selectedIndex.x],
				to_tstring(_numberSelectWindow.SelectedNumber()).c_str()
			);
			_selectedIndex = { -1, -1 };
		}
		
	}
}