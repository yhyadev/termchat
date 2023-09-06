#include <curses.h>

WINDOW *setup_messages_window();
void read_messages(WINDOW *messages_window);
WINDOW *setup_input_window();
void capture_input(WINDOW *input_win);
