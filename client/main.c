#include "main.h"

#include "vector.h"

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	initscr();
	noecho();

	WINDOW *messages_win = setup_messages_window();
	read_messages(messages_win);

	WINDOW *input_win = setup_input_window();
	capture_input(input_win);

	endwin();
}

WINDOW *setup_messages_window() {
	WINDOW *messages_win = newwin(LINES - 3, 0, 0, 0);

	box(messages_win, 0, 0);
	mvwprintw(messages_win, 0, 0, "Messages");
	wrefresh(messages_win);

	return messages_win;
}

void read_messages(WINDOW *messages_win) {}

WINDOW *setup_input_window() {
	WINDOW *input_win = newwin(3, 0, LINES - 3, 0);

	box(input_win, 0, 0);
	mvwprintw(input_win, 0, 0, "Input");
	wmove(input_win, 1, 1);

	return input_win;
}

void capture_input(WINDOW *input_win) {
	nodelay(input_win, 1);

	char_vector *buffer = init_char_vec();

	if (buffer == NULL)
		printf("You need to be more reach brother");

	while (1) {
		/*
		wclear(input_win);
		for (int i = 0; i <= buffer->size; i++) {
			if (buffer->values[i]) {
				waddch(input_win, buffer->values[i]);
			}
		}
		wrefresh(input_win);
		*/

		int key = wgetch(input_win);

		if (key == ERR) {
			continue;
		} else if (key == 13 || key == 10) {
			if (buffer->size == 0)
				continue;
		} else if (key == 8 || key == 121) {
			if (buffer->size == 0)
				continue;
			pop(buffer);
		} else {
			push(buffer, key);
		}

		napms(1000);
	}
}
