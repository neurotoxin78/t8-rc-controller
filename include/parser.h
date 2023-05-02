#include "AsyncUDP.h"
#define UP_CMD 1
#define DOWN_CMD 2
#define LEFT_CMD 3
#define RIGHT_CMD 4
#define ENTER_CMD 5
#define L_BTN_CMD 6

extern uint8_t new_command;

void packetParser(AsyncUDPPacket packet);

