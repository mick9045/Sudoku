#pragma once
#include "BaseDialogWindow.h"
#include "resource.h"


namespace Sudoku
{
	class ComplexitySelectWindow
		:public BaseDialogWindow
	{
	public:
		ComplexitySelectWindow();
		~ComplexitySelectWindow();

	protected:
		VOID Cls_OnClose(HWND hwnd);
		VOID Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify);
		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	};
}

