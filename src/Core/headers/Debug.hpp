#ifndef DEBUG_HPP
#define DEBUG_HPP



//DRK_NDBG is cmake flag which can be changed in the cmake cache
#ifndef DRK_NDBG
#include <iostream>
#include <memory>
#include <cstdint>
#define __MAIN main()
#define DBG_CTOR(_MSG,_RAWPTR)  std::cout << std::dec << "INITALISED:       " << (_MSG) << ". loc: 0x" << std::hex <<  reinterpret_cast<std::uintptr_t>(_RAWPTR) << std::endl
#define DBG_DTOR(_MSG,_RAWPTR)  std::cout << std::dec << "DESTROYED:        " << (_MSG) << ". loc: 0x" << std::hex <<  reinterpret_cast<std::uintptr_t>(_RAWPTR) << std::endl
#define DBG_MSG(_MSG)           std::cout << std::dec << "INFO:             " << (_MSG) << std::endl
#define DBG_MSG_AT(_MSG,_RAWPTR)std::cout << std::dec << "INFO:             " << (_MSG) << ". loc: 0x" << std::hex <<  reinterpret_cast<std::uintptr_t>(_RAWPTR) << std::endl
#define DBG_ERR(_MSG)           std::cout << std::dec << "ERROR:            " << (_MSG) << std::endl
#else
#include <windows.h>
#define __MAIN WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#define DBG_CTOR(_MSG,_RAWPTR)
#define DBG_DTOR(_MSG,_RAWPTR)
#define DBG_MSG(_MSG)
#define DBG_MSG_AT(_MSG,_RAWPTR) 
#define DBG_ERR(_MSG) 
#endif


#endif