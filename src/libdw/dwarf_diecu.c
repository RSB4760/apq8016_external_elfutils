/* Return CU DIE containing given DIE.
   Copyright (C) 2005-2010 Red Hat, Inc.
   This file is part of elfutils.

   This file is free software; you can redistribute it and/or modify
   it under the terms of either

     * the GNU Lesser General Public License as published by the Free
       Software Foundation; either version 3 of the License, or (at
       your option) any later version

   or

     * the GNU General Public License as published by the Free
       Software Foundation; either version 2 of the License, or (at
       your option) any later version

   or both in parallel, as here.

   elfutils is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received copies of the GNU General Public License and
   the GNU Lesser General Public License along with this program.  If
   not, see <http://www.gnu.org/licenses/>.  */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <string.h>
#include "libdwP.h"


Dwarf_Die *
dwarf_diecu (die, result, address_sizep, offset_sizep)
     Dwarf_Die *die;
     Dwarf_Die *result;
     uint8_t *address_sizep;
     uint8_t *offset_sizep;
{
  if (die == NULL)
    return NULL;

  *result = CUDIE (die->cu);

  if (address_sizep != NULL)
    *address_sizep = die->cu->address_size;
  if (offset_sizep != NULL)
    *offset_sizep = die->cu->offset_size;

  return result;
}
