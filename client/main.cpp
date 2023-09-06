#include "main.h"

#include <cstdlib>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include <curses.h>
#include <pthread.h>

#include "socket.h"


int main(void) {
	int sockfd = connect_to_socket();

	RegularArgs args = {.win = NULL, .sockfd = sockfd};
	initscr();

	WINDOW *messages_win = setup_messages_window();
	args.win = messages_win;
	read_messages(&args);

	WINDOW *input_win = setup_input_window();
	args.win = input_win;
	capture_input(&args);

	endwin();
}

WINDOW *setup_messages_window() {
	WINDOW *messages_win = newwin(LINES - 3, 0, 0, 0);

	box(messages_win, 0, 0);
	mvwprintw(messages_win, 0, 0, "Messages");
	wrefresh(messages_win);

	return messages_win;
}

void read_messages(RegularArgs *args) {
    std::thread recv_thread(recieve_message, args);

    recv_thread.detach();
}

WINDOW *setup_input_window() {
	WINDOW *input_win = newwin(3, 0, LINES - 3, 0);

	box(input_win, 0, 0);
	mvwprintw(input_win, 0, 0, "Input");
	wmove(input_win, 1, 1);

	return input_win;
}

void capture_input(RegularArgs *args) {
	noecho();

	WINDOW *text_typed_win = newwin(1, 0, LINES - 2, 1);

    std::string text_typed;

	while (true) {
		wclear(text_typed_win);
        waddstr(text_typed_win, text_typed.c_str());
		wrefresh(text_typed_win);

		int key = wgetch(args->win);

		if (key == ERR) {
			continue;
		} else if (key == 13 || key == 10) {
            if (text_typed.length() == 0) continue;

            std::stringstream message;

            message << "user: " << text_typed << "\n";
            
            send_message(args, message.str().c_str());

            text_typed.clear();
		} else if (key == 8 || key == 127) {
            text_typed.pop_back();
		} else {
            text_typed.push_back(key);
		}

		napms(100);
	}
}
