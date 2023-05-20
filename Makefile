TARGET = main
CC = gcc
CFLAGS = -Wall -g3 -O0

SRC = $(wildcard *.c)

$(TARGET)1 : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run : $(TARGET)
	./$(TARGET)

clean :
	rm \$(TARGET)

debag : 
	gdb ./$(TARGET)