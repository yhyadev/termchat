#include "main.h"

#include <curses.h>

int main(void) {
  initscr();
  read_messages();
  setup_input();
  endwin();
}

void read_messages() {}

void setup_input() {}
