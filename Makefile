all:
	g++ -Isrc/Include -Lsrc/lib -o main main.cpp Game.cpp Scene.cpp Wall.cpp Entity.cpp -lmingw32 -lSDL2main -lSDL2