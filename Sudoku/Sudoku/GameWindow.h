#pragma once
#include "BaseDialogWindow.h"
#include "GameField.h"
#include "NumberSelectWindow.h"

namespace Sudoku
{
	class GameWindow :
		public BaseDialogWindow
	{
	public:
		GameWindow();
		~GameWindow();

		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	protected:
		void Cls_OnClose(HWND hwnd);
		VOID Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify);
		BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
		POINT FindButton(HWND hWindow);
		void Cls_OnParentNotify(HWND hwnd, UINT msg, HWND hwndChild, int idChild);
		void NumberSelected();
	private:
		HWND _hButton[9][9];
		POINT _selectedIndex;
		NumberSelectWindow _numberSelectWindow;
		GameField _gameField;
	};
}

