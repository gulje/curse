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
#include <stdlib.h>
#include <stdio.h>

// code MUST BE ALLOCATED by the caller
Interpreter*
curse_interpreter_new (char *code) {
	Interpreter *interpreter = (Interpreter*)malloc(sizeof(Interpreter));

	if (!interpreter)
		curse_error ("memory allocation failed");

	interpreter->code = code;
	interpreter->pos = 0;
	interpreter->current = interpreter->code[interpreter->pos];

	return interpreter;
}

// code MUST NOT BE DEALLOCATED by the caller
void
curse_interpreter_free (Interpreter *interpreter) {
	free(interpreter->code);
	free(interpreter);
}

void
curse_interpreter_run (Interpreter *interpreter) {
	while (interpreter->current != EOF) {
		switch (interpreter->current) {
			case CURSE_MOVE_CURSOR:
				printf ("got MOVE_CURSOR\n");
				curse_interpreter_advance (interpreter);
				unsigned int x = curse_interpreter_word (interpreter);
				unsigned int y = curse_interpreter_word (interpreter);

				curse_move_cursor (x, y);
				break;
			default:
				curse_interpreter_advance (interpreter);
				break;
		}
	}
}

void
curse_interpreter_advance (Interpreter *interpreter) {
	interpreter->current = interpreter->code[++interpreter->pos];
}

// This code is written for big-endian sorted data.
unsigned int
curse_interpreter_word (Interpreter *interpreter) {
	unsigned short n = interpreter->current << 8;
	curse_interpreter_advance (interpreter);

	n |= interpreter->current;

	curse_interpreter_advance (interpreter);

	return n;
}