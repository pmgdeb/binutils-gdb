/* Target-dependent code for GNU/Linux SPARC.

   Copyright 2003 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#include "defs.h"
#include "gdbarch.h"
#include "osabi.h"

#include "sparc-tdep.h"

static void
sparc32_linux_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
{
  /* GNU/Linux is very similar to Solaris ...  */
  sparc32_sol2_init_abi (info, gdbarch);

  /* ... but doesn't have kernel-assisted single-stepping support.  */
  set_gdbarch_software_single_step (gdbarch, sparc_software_single_step);
}

/* Provide a prototype to silence -Wmissing-prototypes.  */
extern void _initialize_sparc_linux_tdep (void);

void
_initialize_sparc_linux_tdep (void)
{
  gdbarch_register_osabi (bfd_arch_sparc, 0, GDB_OSABI_LINUX,
			  sparc32_linux_init_abi);
}
