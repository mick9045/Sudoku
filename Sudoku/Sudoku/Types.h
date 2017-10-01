#pragma once
#include <tchar.h>
#include <string>


#ifndef UNICODE  
typedef std::string tString;
#define to_tstring std::to_string
#else
typedef std::wstring tString;
#define to_tstring std::to_wstring
#endif

