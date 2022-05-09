CC = gcc
CFLAGS = -W -Wall
TARGET = book
OBJECTS = book.o main.c
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm *.o book