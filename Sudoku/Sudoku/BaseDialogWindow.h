#pragma once
#include <windows.h>
#include <CommCtrl.h>
#include "Types.h"

//#include "resource.h"

namespace Sudoku
{
	class BaseDialogWindow
	{
	public:
		virtual  ~BaseDialogWindow();
		BaseDialogWindow(INT nResource);
		BOOL IsCreated();
		HWND Create(HWND hwndParent = NULL, HINSTANCE hInstance = GetModuleHandle(NULL));
		INT_PTR CreateModal(HWND hwndParent = NULL, HINSTANCE hInstance = GetModuleHandle(NULL));
		HWND GetWindowHandle();
		INT GetResourceID();
		HWND hWindow();
		SIZE GetClientSize();
		SIZE GetSize();
		void SetSize(int with, int height);
		RECT GetRect();
		void SetPos(int x, int y);
		POINT GetLocalPosition();
		static tString GetText(HWND hWnd);
		static POINT GetLocalPosition(HWND hWnd);
		static SIZE GetClientSize(HWND hWnd);
		static SIZE GetSize(HWND hWnd);
		static void SetSize(HWND hWnd, int width, int height);
		static void SetPos(HWND hWnd, int x, int y);
		static INT GetMenuItemPosById(HMENU hMenu, INT id);
		/*~~~~~~~~~~~~~~ methods~~~~~~~~~~~~~~~~~~*/
		void Close();
	protected:
		HWND _hwnd;
		INT _nResource;
		INT _nResult;
		/*~~~~~~~~~~~~~~ methods~~~~~~~~~~~~~~~~~~*/
		BOOL IsModal();
		inline static BaseDialogWindow * GetWindowObjectFromHandle(HWND hWnd);
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
	private:
		BOOL _bModal;
		//prohobit coping
		BaseDialogWindow(const BaseDialogWindow &);
		static INT_PTR CALLBACK MessageRoute(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); // routes messages from all windows
	};

}