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

#include <curse/io.h>
#include <stdio.h>
#include <stdlib.h>

// OUTPUT IS NOT A NULL-TERMINATED STRING!
// DO NOT USE WITH ANY STANDARD LIBRARY METHOD!
char*
curse_read_file (char* filename) {
	FILE *fp;

	fp = fopen (filename, "rb");
	if (!fp)
		curse_error ("file could not found");
	
	fseek (fp, 0L, SEEK_END);
	long size = ftell (fp);
	rewind (fp);

	char *buffer = (char*)malloc (sizeof(char) * (size + 1));
	if (!buffer)
		curse_error ("memory allocation failed");

	if (fread (buffer, size, 1, fp) != 1) {
		free (buffer);
		fclose (fp);
		curse_error ("file read failed");
	}

	buffer[size] = EOF;
	fclose (fp);

	return buffer;
}

char*
curse_error (char *err) {
	fprintf (stderr, "error: %s\n", err);
	exit (1);
}