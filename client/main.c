#include "main.h"

#include <curses.h>

int main(void) {
	initscr();
	clear();
	read_messages();
	setup_input();
	refresh();
	endwin();
}

void read_messages() {
	WINDOW *messages_win = newwin(LINES - 3, 0, 0, 0);

	box(messages_win, 0, 0);
	mvwprintw(messages_win, 0, 0, "Messages");
	wrefresh(messages_win);
}

void setup_input() {
	WINDOW *input_win = newwin(3, 0, LINES - 3, 0);

    box(input_win, 0, 0);
    mvwprintw(input_win, 0, 0, "Input");
    wmove(input_win, 1, 1);
    wgetch(input_win);
}
