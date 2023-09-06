#pragma once

#include "main.h"

#include <string>

int connect_to_socket();
void recieve_message(RegularArgs *args);
void send_message(RegularArgs *args, std::string message);
