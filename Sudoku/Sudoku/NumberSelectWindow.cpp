#include "NumberSelectWindow.h"
#include "resource.h"
#include <windowsx.h>


namespace Sudoku
{
	NumberSelectWindow::NumberSelectWindow()
		: BaseDialogWindow(IDD_DIALOG_SELECT_NUMBER)
	{
		_selectedNumber = -1;
	}


	NumberSelectWindow::~NumberSelectWindow()
	{
	}

	int NumberSelectWindow::SelectedNumber()
	{
		return _selectedNumber;
	}

	INT_PTR NumberSelectWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			HANDLE_MSG(hwnd, WM_PARENTNOTIFY, Cls_OnParentNotify);
			HANDLE_MSG(hwnd, WM_COMMAND, Cls_OnCommand);

		}
		return FALSE;
	}

	void NumberSelectWindow::Cls_OnParentNotify(HWND hwnd, UINT msg, HWND hwndChild, int idChild)
	{
	}

	VOID NumberSelectWindow::Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify)
	{
		if (codeNotify == STN_CLICKED)
		{
			switch (id)
			{
			case IDC_BUTTON1:
				_selectedNumber = 1;
				break;
			case IDC_BUTTON2:
				_selectedNumber = 2;
				break;
			case IDC_BUTTON3:
				_selectedNumber = 3;
				break;
			case IDC_BUTTON4:
				_selectedNumber = 4;
				break;
			case IDC_BUTTON5:
				_selectedNumber = 5;
				break;
			case IDC_BUTTON6:
				_selectedNumber = 6;
				break;
			case IDC_BUTTON7:
				_selectedNumber = 7;
				break;
			case IDC_BUTTON8:
				_selectedNumber = 8;
				break;
			case IDC_BUTTON9:
				_selectedNumber = 9;
				break;
				break;
			default:
				break;
			}
		}
		if (_selectedNumber != -1)
		{
			PostMessage(GetParent(hWindow()), WM_NUMBER_SELECTED, _selectedNumber, NULL);
			Close();
		}
	}
	
}
