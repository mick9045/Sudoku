#include "MenuWindow.h" 
#include <Windowsx.h>
#include "resource.h"
#include "GameWindow.h"

namespace Sudoku
{
	MenuWindow::MenuWindow()
		:BaseDialogWindow(IDD_DIALOG_MENU)
	{
	}


	MenuWindow::~MenuWindow()
	{
	}

	void MenuWindow::Cls_OnClose(HWND hwnd)
	{
		Close();
	}

	INT_PTR MenuWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			HANDLE_MSG(hwnd, WM_CLOSE, Cls_OnClose);
			HANDLE_MSG(hwnd, WM_DESTROY, Cls_OnDestroy);
			HANDLE_MSG(hwnd, WM_COMMAND, Cls_OnCommand);
			HANDLE_MSG(hwnd, WM_INITDIALOG, Cls_OnInitDialog);
			//HANDLE_MSG(hwnd, WM_)

		}

		return FALSE;
	}

	VOID MenuWindow::Cls_OnDestroy(HWND hwnd)
	{
		PostQuitMessage(NULL);
	}

	VOID MenuWindow::Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify)
	{
		switch (id)
		{
		case IDC_BUTTON_EXIT:
			_nResult = IDCANCEL;
			Close();
			break;
		case IDC_BUTTON_NEWGAME:
		{
			auto gameWindow = new GameWindow();
			ShowWindow(hWindow(), SW_HIDE);
			gameWindow->CreateModal();
			ShowWindow(hWindow(), SW_SHOW);
			delete gameWindow;
			_nResult == IDOK;
		}

			break;
		default:
			break;
		}
	}

	BOOL MenuWindow::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
	{
		return false;
	}
}
