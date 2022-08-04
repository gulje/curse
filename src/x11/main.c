// Copyright 2022 Xin Yue

// Licensed under the Apache License, Version 2.0 (the "License"); you may not
// use this file except in compliance with the License. You may obtain a copy
// of the License at

//   http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations
// under the License.

#include <curse/curse.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

static Display *dpy;
static Window root_window;

void
curse_init (void) {
	dpy = XOpenDisplay (0);
	root_window = XRootWindow (dpy, XDefaultScreen (dpy));
}

void
curse_move_cursor (int x, int y) {
	XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, x, y);
	XFlush(dpy);	
}