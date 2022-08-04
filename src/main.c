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
#include <curse/interpreter.h>
#include <curse/io.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
	if (argc < 2)
		curse_error ("usage: curse [filename]");

	curse_init ();

	Interpreter* interpreter = curse_interpreter_new (curse_read_file (argv[1]));

	curse_interpreter_run (interpreter);

	curse_interpreter_free (interpreter);
	
	return 0;
}