/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2013 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2013 - Daniel De Matteis
 * 
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>

#include <xtl.h>

#include "../../retroarch_logger.h"

static void rarch_console_exec(const char *path, bool should_load_game)
{
   (void)should_load_game;

   RARCH_LOG("Attempt to load executable: [%s].\n", path);
#ifdef IS_SALAMANDER
   XLaunchNewImage(path, NULL);
#else
#ifdef _XBOX1
   LAUNCH_DATA ptr;
   memset(&ptr, 0, sizeof(ptr));
   if (should_load_game)
   {
      snprintf((char*)ptr.Data, sizeof(ptr.Data), "%s", g_extern.fullpath);
      XLaunchNewImage(path, &ptr);
   }
   XLaunchNewImage(path, NULL);
#else
   XLaunchNewImage(path, NULL);
#endif
#endif

}
