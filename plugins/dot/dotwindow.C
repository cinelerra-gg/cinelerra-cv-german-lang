
/*
 * CINELERRA
 * Copyright (C) 2008 Adam Williams <broadcast at earthling dot net>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * 
 */

#include "bcdisplayinfo.h"
#include "dotwindow.h"
#include "language.h"
#include "pluginclient.h"

PLUGIN_THREAD_OBJECT(DotMain, DotThread, DotWindow)






DotWindow::DotWindow(DotMain *client, int x, int y)
 : PluginWindow(client->gui_string,
	x,
	y,
	300, 
	170)
{ 
	this->client = client; 
}

DotWindow::~DotWindow()
{
}

int DotWindow::create_objects()
{
	int x = 10, y = 10;
	add_subwindow(new BC_Title(x, y, 
		_("DotTV from EffectTV\n"
		"Copyright (C) 2001 FUKUCHI Kentarou")
	));

	show_window();
	flush();
	return 0;
}







