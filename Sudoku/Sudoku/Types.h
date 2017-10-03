#pragma once
#include <tchar.h>
#include <string>

#define WM_NUMBER_SELECTED (WM_USER + 0x0001)

#ifndef UNICODE  
typedef std::string tString;
#define to_tstring std::to_string
#else
typedef std::wstring tString;
#define to_tstring std::to_wstring
#endif

