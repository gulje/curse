override TARGET = curse
override LIBCURSE_X11 = libcurse-x11.a
override LIBCURSE_WL = libcurse-wl.a

export MAIN_CFLAGS = -std=c11 \
	-Wall \
	-I$(shell pwd)/include

CFLAGS = \
	-L.

BINARY_DEPS =
BINARY_SOURCES = $(wildcard src/*.c)
BINARY_OBJECTS = $(BINARY_SOURCES:.c=.o)

ifneq ($(curse_build_wl),1)
	BINARY_DEPS += $(LIBCURSE_X11)
	CFLAGS += -lcurse-x11 -lX11
	MAIN_CFLAGS += -DCURSE_X11
else
	BINARY_DEPS += $(LIBCURSE_WL)
	CFLAGS += -lcurse-wl
	MAIN_CFLAGS += -DCURSE_WL
endif

.PHONY: all $(LIBCURSE_X11) $(LIBCURSE_WL) libcurse curse
all: $(LIBCURSE_X11) $(LIBCURSE_WL) _$(TARGET)
curse: _$(TARGET)
libcurse: $(BINARY_DEPS)

_$(TARGET): $(BINARY_DEPS) $(BINARY_OBJECTS)
	gcc $(BINARY_OBJECTS) $(CFLAGS) -o $(TARGET) $(MAIN_CFLAGS)

%.o: %.c
	gcc $(MAIN_CFLAGS) -c -o $@ $<

$(LIBCURSE_X11):
	@$(MAKE) -C src/x11 TARGET=$(shell pwd)/$@

$(LIBCURSE_WL):
	@$(MAKE) -C src/wayland TARGET=$(shell pwd)/$@

clean:
	@$(MAKE) -C src/x11 clean TARGET=$(shell pwd)/$(LIBCURSE_X11)
	@$(MAKE) -C src/wayland clean TARGET=$(shell pwd)/$(LIBCURSE_WL)
	rm -rf $(TARGET) $(BINARY_OBJECTS)