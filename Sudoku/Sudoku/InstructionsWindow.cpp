#include "InstructionsWindow.h"
#include "resource.h"
#include <Windowsx.h>

namespace Sudoku
{

	InstructionsWindow::InstructionsWindow()
		:BaseDialogWindow(IDD_DIALOG_INSTRUCTIONS)
	{
	}


	InstructionsWindow::~InstructionsWindow()
	{
	}

	INT_PTR InstructionsWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			HANDLE_MSG(hwnd, WM_CLOSE, Cls_OnClose);
			HANDLE_MSG(hwnd, WM_COMMAND, Cls_OnCommand);
		}
		return FALSE;
	}

	void InstructionsWindow::Cls_OnClose(HWND hwnd)
	{
		Close();
	}

	VOID InstructionsWindow::Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify)
	{
		if (codeNotify == BN_CLICKED)
		{
			switch (id)
			{
			case IDOK:
				Close();
				break;
			default:
				break;
			}
		}
	}
}