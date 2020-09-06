//
// Python wrapper for PyBFD3 (libbfd & libopcodes extension module)
//
// Copyright (c) 2013 Groundworks Technologies
//

#ifndef PYBFD3_HEADERS
#define PYBFD3_HEADERS

#define PACKAGE "pybfd3"
#define PACKAGE_VERSION "0.1.4"

#include <dis-asm.h>

#ifdef PYBFD3_BFD_GE_2_29
// In binutils 2.29 print_insn_i386 disappeared from the dis-asm.h header
int print_insn_i386 (bfd_vma, disassemble_info *);
#endif

#define PYBFD3_SYMBOL_VALUE_FMT "k" // unsigned long
#define PYBFD3_SYMBOL_FLAG_FMT "I" // typedef unsigned int flagword;	/* 32 bits of flags */

#ifdef BFD64
#define PY_VMA_FMT "L" /* unsigned long */
#else
#define PY_VMA_FMT "L" /* unsigned long */
#endif /* noy BFD64 */

//
// List of Python callback function return values.
//
enum PYBFD3_DISASM_CALLBACK_RESULT {
    PYBFD3_DISASM_CONTINUE = 0,
    PYBFD3_DISASM_STOP
};

#endif /* PYBFD3_HEADERS */
