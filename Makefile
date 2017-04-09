
all : Framework_Main.c
	gcc -o Framework_Main Framework_Main.c

valgrind : ./queue
	valgrind -v --leak-check=yes ./queue