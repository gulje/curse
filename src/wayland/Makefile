SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar -rcs $(TARGET) $^

%.o: %.c
	gcc $(MAIN_CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS) $(TARGET)