TARGET = curse

SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = \
	-Iinclude/ \
	-g

ifeq ($(CURSE_USE_WAYLAND),)
	SOURCES += $(wildcard src/x11/*.c)
	OBJECTS = $(SOURCES:.c=.o)
	CFLAGS += -lX11
else
	SOURCES += $(wildcard src/wayland/*.c)
	OBJECTS = $(SOURCES:.c=.o)
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o $(@)

%.o: %.c
	gcc -c $(CFLAGS) $(<) -o $(@)