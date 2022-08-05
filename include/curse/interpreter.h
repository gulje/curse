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

#include <stdint.h>

#ifndef _CURSE_INTERPRETER_H
	#define _CURSE_INTERPRETER_H

	// Reduced size: 13 bytes from 24 bytes
	// Interpreter automatically tokenizes and interprets the code, there is no need for lexer
	typedef struct {
		char current;
		uint32_t pos;
		char *code;
	} __attribute__((packed)) Interpreter;

	// allocation
	Interpreter *curse_interpreter_new(char*);
	void curse_interpreter_free(Interpreter*);

	// methods
	void curse_interpreter_run(Interpreter*);
	void curse_interpreter_advance(Interpreter*);
	unsigned int curse_interpreter_word(Interpreter*);

#endif