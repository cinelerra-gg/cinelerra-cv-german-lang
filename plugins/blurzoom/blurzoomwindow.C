
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
#include "blurzoomwindow.h"

#include <libintl.h>
#define _(String) gettext(String)
#define gettext_noop(String) String
#define N_(String) gettext_noop (String)


BlurZoomThread::BlurZoomThread(BlurZoomMain *client)
 : Thread()
{
	this->client = client;
	set_synchronous(0);
	gui_started.lock();
	completion.lock();
}

BlurZoomThread::~BlurZoomThread()
{
// Window always deleted here
	delete window;
}
	
void BlurZoomThread::run()
{
	BC_DisplayInfo info;
	window = new BlurZoomWindow(client, 
		info.get_abs_cursor_x() - 105, 
		info.get_abs_cursor_y() - 100);
	window->create_objects();
	gui_started.unlock();
	int result = window->run_window();
	completion.unlock();
// Last command executed in thread
	if(result) client->client_side_close();
}






BlurZoomWindow::BlurZoomWindow(BlurZoomMain *client, int x, int y)
 : PluginWindow(client->gui_string,
	x,
	y,
	300, 
	170)
{ 
	this->client = client; 
}

BlurZoomWindow::~BlurZoomWindow()
{
}

int BlurZoomWindow::create_objects()
{
	int x = 10, y = 10;
	add_subwindow(new BC_Title(x, y, 
		_("RadioacTV from EffectTV\n"
		"Copyright (C) 2001 FUKUCHI Kentarou")
	));

	show_window();
	flush();
	return 0;
}



