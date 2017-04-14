CC=gcc
CFLAGS=-Wall
LINKS=-lpigpio -lwiringPi -lpthread -lm
SOURCE=Framework_Main.c eventQueue.c HSM.c SubUltrasonicEvent.c autoMotorFunctions.c
EXECUTABLE=FrameworkMain
 
all : $(EXECUTABLE)

$(EXECUTABLE) : $(SOURCE)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCE) $(LINKS)

valgrind : $(EXECUTABLE)
	valgrind -v --leak-check=yes ./$(EXECUTABLE)

clean :
	rm -f $(EXECUTABLE) $(OBJECTS)
