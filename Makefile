CC=gcc
CFLAGS=-Wall
LINKS=-lwiringPi -lpigpio -lm -lpthread
SOURCE=Framework_Main.c eventQueue.c HSM.c SubUltrasonicEvent.c UltrasonicEventChecker.c
EXECUTABLE=FrameworkMain
 
all : $(EXECUTABLE)

$(EXECUTABLE) : $(SOURCE)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCE)

valgrind : $(EXECUTABLE)
	valgrind -v --leak-check=yes ./$(EXECUTABLE)
