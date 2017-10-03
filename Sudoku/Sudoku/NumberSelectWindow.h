#pragma once
#include "BaseDialogWindow.h"

namespace Sudoku
{
	class NumberSelectWindow
		: public BaseDialogWindow
	{
	public:
		NumberSelectWindow();
		~NumberSelectWindow();

		int SelectedNumber();
		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	protected:
		int _selectedNumber;
	private:
		void Cls_OnParentNotify(HWND hwnd, UINT msg, HWND hwndChild, int idChild);
		VOID Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify);
	};
}

