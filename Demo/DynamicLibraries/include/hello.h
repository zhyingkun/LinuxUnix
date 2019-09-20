#if defined(HELLO_BUILD_AS_DLL)
#if defined(HELLO_CORE)
#define HELLO_API __declspec(dllexport) // for sudoku.dll
#else
#define HELLO_API __declspec(dllimport) // for user who use sudoku.dll, with SUDOKU_BUILD_AS_DLL
#endif
#else
#define HELLO_API extern
#endif

HELLO_API void PrintHello();
