# Copyright 2022 Xin Yue 

# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy
# of the License at

#   http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations
# under the License.

TARGET = curse

SOURCES = src/main.c
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = \
	-Iinclude/

ifeq ($(CURSE_USE_WAYLAND),)
	SOURCES += $(wildcard src/x11/*.c)
	OBJECTS = $(SOURCES:.c=.o)
else
	SOURCES += $(wildcard src/wayland/*.c)
	OBJECTS = $(SOURCES:.c=.o)
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	gcc $(OBJECTS) -o $(@)

%.o: %.c
	gcc -c $(CFLAGS) $(<) -o $(@)