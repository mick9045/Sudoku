#pragma once
#include "BaseDialogWindow.h"

namespace Sudoku
{
	class MenuWindow
		:public BaseDialogWindow
	{
	public:
		MenuWindow();
		~MenuWindow();
	protected:
		void Cls_OnClose(HWND hwnd);
		VOID Cls_OnDestroy(HWND hwnd);
		VOID Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify);
		BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);


	private:
		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;


	};
}

