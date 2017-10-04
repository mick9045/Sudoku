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
		HBRUSH Cls_OnCtlColor(HWND hwnd, HDC hdc, HWND hwndChild, int type);
		POINT FindButton(HWND hWindow);
		VOID Cls_OnParentNotify(HWND hwnd, UINT msg, HWND hwndChild, int idChild);
		VOID Cls_OnMove(HWND hwnd, int x, int y);
		void NumberSelected();
		void Reset();
		void Initialize();
	private:
		HWND _harButton[9][9];
		HBRUSH _hbrBorder;
		POINT _selectedIndex;
		NumberSelectWindow _numberSelectWindow;
		GameField _gameField;
	};
}

