#pragma once

#include <curses.h>

typedef struct {
    WINDOW *win;
    int sockfd;
} RegularArgs;

WINDOW *setup_messages_window();
void read_messages(RegularArgs* args);
WINDOW *setup_input_window();
void capture_input(RegularArgs* args);
