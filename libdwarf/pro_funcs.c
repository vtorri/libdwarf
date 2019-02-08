/*

  Copyright (C) 2000,2004 Silicon Graphics, Inc.  All Rights Reserved.
  Portions Copyright 2011  David Anderson. All Rights Reserved.

  This program is free software; you can redistribute it and/or modify it
  under the terms of version 2.1 of the GNU Lesser General Public License
  as published by the Free Software Foundation.

  This program is distributed in the hope that it would be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  Further, this software is distributed without any warranty that it is
  free of the rightful claim of any third person regarding infringement
  or the like.  Any license provided herein, whether implied or
  otherwise, applies only to this software file.  Patent licenses, if
  any, provided herein do not apply to combinations of this program with
  other software, or any other product whatsoever.

  You should have received a copy of the GNU Lesser General Public
  License along with this program; if not, write the Free Software
  Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston MA 02110-1301,
  USA.

*/

#include "config.h"
#ifdef HAVE_ELF_H
#include "libdwarfdefs.h"
#include <stdio.h>
#include <string.h>
#ifdef HAVE_ELFACCESS_H
#include <elfaccess.h>
#endif
#include "pro_incl.h"
#include "pro_section.h"

/*  This function adds another function name to the
    list of function names for the given Dwarf_P_Debug.
    It returns 0 on error, and 1 otherwise. */
Dwarf_Unsigned
dwarf_add_funcname(Dwarf_P_Debug dbg,
   Dwarf_P_Die die,
   char *function_name, Dwarf_Error * error)
{
    int res = 0;

    res = _dwarf_add_simple_name_entry(dbg, die, function_name,
        dwarf_snk_funcname, error);
    if (res != DW_DLV_OK) {
        return 0;
    }
    return 1;
}
int
dwarf_add_funcname_a(Dwarf_P_Debug dbg,
   Dwarf_P_Die die,
   char *function_name, Dwarf_Error * error)
{
    int res = 0;

    res = _dwarf_add_simple_name_entry(dbg, die, function_name,
        dwarf_snk_funcname, error);
    return res;
}
#endif /* HAVE_ELF_H */
