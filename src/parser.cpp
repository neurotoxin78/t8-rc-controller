#include "parser.h"
#include "main.h"

uint8_t new_command;

void packetParser(AsyncUDPPacket packet)
{
    const uint8_t *msg = packet.data();
    
    switch (msg[0])
    {
    case 52:
        new_command = UP_CMD; // "UP";
        break;
    case 51:
        new_command = DOWN_CMD; //"DOWN";
        break;
    case 49:
        new_command = LEFT_CMD; //"LEFT";
        break;
    case 50:
        new_command = RIGHT_CMD; //"RIGHT";
        break;
    case 48:
        new_command = ENTER_CMD; //"ENTER";
        break;
    case 54:
        new_command = L_BTN_CMD; //"BTNL";
        break;
    default:
        break;
    }

    //Serial.println(state);
}