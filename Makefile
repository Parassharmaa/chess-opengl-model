LDFLAGS =  -lGL -lGLU -lglut
CC = g++

main: clean
	$(CC) src/*.cpp $(LDFLAGS) -o chessboard

clean:
	rm -rf chessboard