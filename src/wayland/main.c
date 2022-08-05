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

#include <curse/wayland.h>
#include <stdio.h>
#include <stdlib.h>

#define NOT_IMPLEMENTED(x) \
	printf ("libcurse-wl#%s is not implemented.\n", # x); \
	exit (1);

void
wl_curse_init (void)
{
	NOT_IMPLEMENTED(wl_curse_init);
}

void
wl_curse_move_cursor (int x, int y)
{
	NOT_IMPLEMENTED(wl_curse_move_cursor);
}