all: cpp python 

python:
	python3 ./server/main.py

cpp:
	g++ ./client/*.cpp -lncurses
	mkdir -p bin
	mv a.out ./bin/termchat
