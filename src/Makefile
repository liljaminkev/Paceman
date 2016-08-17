CC=gcc
CFLAGS=-c -g
OUTFILE=pacman

MAKEFLAGS += -j 4
all: pacman

# pacman: fruit.o singlePlayerGameController.o Test_GB.o gameBoard.o pacman.o Monster.o
# 	$(CC) -o $(OUTFILE) fruit.o singlePlayerGameController.o Test_GB.o gameBoard.o pacman.o Monster.o -lncurses -lpthread

pacman: menu.o main.o
	$(CC) -o $(OUTFILE) menu.o main.o singlePlayerGameController.o -lncurses -lpthread

# fruit.o: fruit.c
# 	$(CC) $(CFLAGS) fruit.c

# singlePlayerGameController.o: singlePlayerGameController.c
# 	$(CC) $(CFLAGS) singlePlayerGameController.c

# Test_GB.o: Test_GB.c
# 	$(CC) $(CFLAGS) Test_GB.c

# gameBoard.o: gameBoard.c
# 	$(CC) $(CFLAGS) gameBoard.c

# pacman.o: pacman.c
# 	$(CC) $(CFLAGS) pacman.c

# Monster.o: Monster.c
# 	$(CC) $(CFLAGS) Monster.c

menu.o: menu.c
	$(CC) $(CFLAGS) menu.c

main.o: main.c
	$(CC) $(CFLAGS) main.c
	
main.o: singlePlayerGameController.c
	$(CC) $(CFLAGS) singlePlayerGameController.c



clean:
	rm *.o pacman
