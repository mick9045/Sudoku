#pragma once
#include "BaseDialogWindow.h"


namespace Sudoku
{
	class InstructionsWindow :
		public BaseDialogWindow
	{
	public:
		InstructionsWindow();
		~InstructionsWindow();

	protected:

		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
		void Cls_OnClose(HWND hwnd);
		VOID Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify);

	};
}