#pragma once
/*
https://blog.systemjp.net/entry/2020/02/08/150526
*/
#include <sstream>
#include <Windows.h>

#ifdef OutputDebugString
#undef OutputDebugString
#endif
#ifdef UNICODE
#define OutputDebugString  OutputDebugStringFW
#define OutputDebugStringV OutputDebugStringFVW
#else
#define OutputDebugString  OutputDebugStringFA
#define OutputDebugStringV OutputDebugStringFVA
#endif // !UNICODE
void OutputDebugStringFA(const char* format, ...);
void OutputDebugStringFW(const wchar_t* format, ...);

void OutputDebugStringFVA(const char* format, va_list args)
{
	int len = _vscprintf(format, args) + 1;
	char* buffer = new char[len];
	vsprintf_s(buffer, len, format, args);
	OutputDebugStringA(buffer);
	delete[] buffer;
}
void OutputDebugStringFVW(const wchar_t* format, va_list args)
{
	int len = _vscwprintf(format, args) + 1;
	wchar_t* buffer = new wchar_t[len];
	vswprintf_s(buffer, len, format, args);
	OutputDebugStringW(buffer);
	delete[] buffer;
}
void OutputDebugStringFA(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	OutputDebugStringFVA(format, args);
	va_end(args);
}
void OutputDebugStringFW(const wchar_t* format, ...)
{
	va_list args;
	va_start(args, format);
	OutputDebugStringFVW(format, args);
	va_end(args);
}

//#ifdef _DEBUG
//#   define MyOutputDebugString( str, ... ) \
//      { \
//        TCHAR c[256]; \
//        swprintf_s( c, str, __VA_ARGS__ ); \
//        OutputDebugString( c ); \
//      }
//#else
//#    define MyOutputDebugString( str, ... ) // 空実装
//#endif
//
//int main(int argc, char* argv[])
//{
//	float a = 100.f;
//	float b = 100.f;
//	float c = 100.f;
//	float d = 100.f;
//	OutputDebugString(TEXT("abc %f %f %f %f \n"), a, b, c, d);
//
//	return 0;
//}