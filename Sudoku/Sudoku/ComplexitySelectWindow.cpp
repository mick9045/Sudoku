#include "ComplexitySelectWindow.h"
#include "GameWindow.h"
#include "resource.h"
#include <windowsx.h>


namespace Sudoku
{
	ComplexitySelectWindow::ComplexitySelectWindow()
		:BaseDialogWindow(IDD_DIALOG_SELECT_COMPLEXITY)
	{
	}


	ComplexitySelectWindow::~ComplexitySelectWindow()
	{
	}

	VOID ComplexitySelectWindow::Cls_OnClose(HWND hwnd)
	{
		Close();
	}

	VOID ComplexitySelectWindow::Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify)
	{
		BaseDialogWindow * gameWindow = NULL;
		switch (id)
		{
		case IDC_BUTTON_EASY:
			gameWindow = new GameWindow(3);
			break;
		case IDC_BUTTON_NORMAL:
			gameWindow = new GameWindow(4);
			break;
		case IDC_BUTTON_DIFFICULT:
			gameWindow = new GameWindow(5);
			break;
		}
		if (gameWindow != NULL)
		{
			ShowWindow(hWindow(), SW_SHOWMINIMIZED);
			gameWindow->CreateModal(hWindow());
			delete gameWindow;
			ShowWindow(hWindow(), SW_SHOW);
			Close();
		}
	}

	INT_PTR ComplexitySelectWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			HANDLE_MSG(hwnd, WM_CLOSE, Cls_OnClose);
			HANDLE_MSG(hwnd, WM_COMMAND, Cls_OnCommand);
		default:
			break;
		}
		return INT_PTR();
	}

}