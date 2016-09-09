///////////////////////////////////////////////////////////////////////
// "Detecting Memory Leaks" by Douglas Cox
// Tip Of The Day Entry from flipCode (http://www.flipcode.com/totd/)
//

// Simple test showing how to use the Win32 crtdbg library
// to track memory leaks. -- Build this debug.

#if !defined(_memoryLeak_Defined_)
#define _memoryLeak_Defined_

#if defined(_DEBUG)
  #define _CRTDBG_MAP_ALLOC
  #include <stdlib.h>
  #include <crtdbg.h>
#endif // defined(_DEBUG)

//=============================================================
// Define our allocation macros
//=============================================================
#if defined(_DEBUG)
  #define malloc(s)     _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
  #define calloc(c, s)  _calloc_dbg(c, s, _NORMAL_BLOCK, __FILE__, __LINE__)
  #define realloc(p, s) _realloc_dbg(p, s, _NORMAL_BLOCK, __FILE__, __LINE__)
  #define _expand(p, s) _expand_dbg(p, s, _NORMAL_BLOCK, __FILE__, __LINE__)
  #define free(p)       _free_dbg(p, _NORMAL_BLOCK)
  #define _msize(p)     _msize_dbg(p, _NORMAL_BLOCK)

  #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
  //#define delete delete

  // Set to dump leaks at the program exit.
  #define InitMemoryLeak() \
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF)

#else

  #define InitMemoryLeak()

#endif // defined(_DEBUG)

#endif // !defined(_memoryLeak_Defined_)

/* Usage Example:

#include "memoryLeak.h"
#include <stdio.h>


//=============================================================
class CTest1
{
public:
  CTest1()
  {
    m_mem = malloc(1234);
  }
  
  ~CTest1()
  {
    // whoops, no:
    // free(m_mem);
  }
  void* m_mem;
};

// global instance of CTest1
CTest1 g_test;


//=============================================================
void main()
{
  InitMemoryLeak();

  // new some memory here 
  int* iptr = new int[200]; // will be 200 * sizeof(int) bytes = 800

  // doh, forgot to delete it: 
  // delete []iptr;

  char* cptr = new char[100];
  // we'll properly delete this to prove it works..
  delete[] cptr;

  // Watch the debug spew when the program exits...
  // Double click on each output line to jump to the source code line
  // where the allocation occurred.

  // Note the output is from the most recent allocation to the oldest.

}

  //////////////////////////
  // Debug Output on VC6

    // Loaded 'C:\WINDOWS\SYSTEM\KERNEL32.DLL', no matching symbolic information found.
    // Detected memory leaks!
    // Dumping objects ->
    // D:\MyProjects\Console\console.cpp(32) : {20} normal block at 0x00780340, 800 bytes long.
    //  Data: <                > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD 
    // D:\MyProjects\Console\console.cpp(11) : {19} normal block at 0x007709A4, 1234 bytes long.
    //  Data: <                > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD 
    // Object dump complete.
    // The thread 0xFFF92175 has exited with code 17 (0x11).
    // The program 'D:\MyProjects\Console\Debug\Console.exe' has exited with code 17 (0x11).


*/
