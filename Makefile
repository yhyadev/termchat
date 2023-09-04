all: c python 

python:
	python3 ./server/main.py

c:
	gcc ./client/* -lncurses
	mkdir -p bin
	mv a.out ./bin/termchat
