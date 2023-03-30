#ifndef DEBUG_HPP
#define DEBUG_HPP


#define DRK_DBG 1

#if DRK_DBG == 1
#include <iostream>
#define DBG_CTOR(_MSG,_RAWPTR)  std::cout << std::dec << "Initalised:    " << (_MSG) << ". loc: 0x" << std::hex <<  reinterpret_cast<std::uintptr_t>(_RAWPTR) << std::endl
#define DBG_DTOR(_MSG,_RAWPTR)  std::cout << std::dec << "Freed:         " << (_MSG) << ". loc: 0x" << std::hex <<  reinterpret_cast<std::uintptr_t>(_RAWPTR) << std::endl
#define DBG_MSG(_MSG)           std::cout << std::dec << (_MSG) << std::endl
#define DBG_MSG_AT(_MSG,_RAWPTR)std::cout << std::dec << (_MSG) << ".Called at: 0x" << std::hex <<  reinterpret_cast<std::uintptr_t>(_RAWPTR) << std::endl
#else
#define DBG_CTOR(_MSG,_RAWPTR)
#define DBG_DTOR(_MSG,_RAWPTR)
#define DBG_MSG(_MSG)
#define DBG_MSG_AT(_MSG,_RAWPTR) 
#endif


#endif