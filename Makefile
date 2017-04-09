CC=gcc
CFLAGS=-Wall
SOURCE=Framework_Main.c eventQueue.c HSM.c
EXECUTABLE=FrameworkMain
 
all : $(EXECUTABLE)

$(EXECUTABLE) : $(SOURCE)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCE)

valgrind : $(EXECUTABLE)
	valgrind -v --leak-check=yes ./$(EXECUTABLE)
