#include "GameWindow.h"
#include "resource.h"
#include <windowsx.h>

namespace Sudoku
{
	GameWindow::GameWindow(int complexity)
		:BaseDialogWindow(IDD_DIALOG_MAIN), _gameField(complexity)
	{
		_selectedIndex = { -1, -1 };
		_hbrBorder = CreateSolidBrush(RGB(13, 71, 161));
	}


	GameWindow::~GameWindow()
	{
		DeleteObject(_hbrBorder);
	}

	INT_PTR GameWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			HANDLE_MSG(hwnd, WM_CLOSE, Cls_OnClose);
			HANDLE_MSG(hwnd, WM_COMMAND, Cls_OnCommand);
			HANDLE_MSG(hwnd, WM_INITDIALOG, Cls_OnInitDialog);
			HANDLE_MSG(hwnd, WM_PARENTNOTIFY, Cls_OnParentNotify);
			HANDLE_MSG(hwnd, WM_CTLCOLORBTN, Cls_OnCtlColor);
			HANDLE_MSG(hwnd, WM_MOVE, Cls_OnMove);
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
			if (id == ID_EXIT)
			{
				if (MessageBox(hWindow(), TEXT("Вы уверены?"), TEXT("Предупреждение"), MB_YESNO | MB_ICONWARNING) == IDYES)
				{
					Close();
				}
			}
			else if (id == ID_NEW_GAME)
			{
				if (MessageBox(hWindow(), TEXT("Вы уверены?"), TEXT("Предупреждение"), MB_YESNO | MB_ICONWARNING) == IDYES)
				{
					Reset();
				}
			}
			else
			{
				POINT newSelectedIndex = FindButton(hwndCtl);
				if (!_gameField.IsDeleted(newSelectedIndex.x, newSelectedIndex.y))
				{
					return;
				}
				_selectedIndex = newSelectedIndex;
				_numberSelectWindow.Create(hWindow());
				POINT p;
				GetCursorPos(&p);
				_numberSelectWindow.SetPos(p.x, p.y);
			}
		}
	}

	BOOL GameWindow::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
	{
		int buttonSize = 45;
		HWND h;
		LPTCH lptchText = new TCHAR[12];
		SetSize(470, 600);

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				//(3 * int(j / 3)) offset between blocks of 3X3
				int xPos = (buttonSize * j + (3 * j) + 7) + (4 * int(j / 3));
				int yPos = (buttonSize * i + (3 * i)) + (4 * int(i / 3));
				tString tsButtonText;
				if (!_gameField.IsDeleted(j, i))
				{
					tsButtonText = to_tstring(_gameField.Get(j, i));
				}

				_harButton[i][j] = CreateWindow(
					L"BUTTON",  // Predefined class; Unicode assumed 
					tsButtonText.c_str(),      // Button text 
					WS_TABSTOP | WS_VISIBLE | WS_CHILD,  // Styles 
					xPos,         // x position 
					yPos,         // y position 
					buttonSize,        // Button width
					buttonSize,        // Button height
					hWindow(),     // Parent window
					NULL,       // No menu.
					(HINSTANCE)GetWindowLong(hWindow(), GWL_HINSTANCE),
					NULL);      // Pointer not needed.
				//InvalidateRect(_harButton[i][j], NULL, TRUE);
			}
		}
		//InvalidateRgn()
		SetFocus(hWindow());
		return FALSE;
	}

	HBRUSH GameWindow::Cls_OnCtlColor(HWND hwnd, HDC hdc, HWND hwndChild, int type)
	{
		POINT buttonPosition = FindButton(hwndChild);
		if (buttonPosition.x != -1 && _gameField.IsDeleted(buttonPosition.x, buttonPosition.y))
		{
			return HBRUSH(_hbrBorder);
		}
			return HBRUSH(GetStockObject(BLACK_BRUSH));
	}

	POINT GameWindow::FindButton(HWND hWindow)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (_harButton[i][j] == hWindow)
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

	VOID GameWindow::Cls_OnMove(HWND hwnd, int x, int y)
	{
		_numberSelectWindow.Close();
	}

	void GameWindow::NumberSelected()
	{
		if (_selectedIndex.x >= 0)
		{
			_gameField.Set(_selectedIndex.x,_selectedIndex.y, _numberSelectWindow.SelectedNumber());

			SetWindowText(
				_harButton[_selectedIndex.y][_selectedIndex.x],
				to_tstring(_numberSelectWindow.SelectedNumber()).c_str()
			);
			if (_gameField.IsSolved())
			{
				MessageBox(hWindow(), _T("Игра пройдена"), TEXT("Судоку"), MB_OK | MB_ICONINFORMATION);
				Close();
			}
			_selectedIndex = { -1, -1 };
		}
		
	}

	void GameWindow::Reset()
	{
		_numberSelectWindow.Close();
		_gameField.Reset();
		Initialize();
	}

	void GameWindow::Initialize()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				tString tsButtonText;
				if (!_gameField.IsDeleted(j, i))
				{
					tsButtonText = to_tstring(_gameField.Get(j, i));
				}
				SetWindowText(_harButton[i][j], tsButtonText.c_str());
			}
		}
	}
}