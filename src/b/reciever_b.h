#include "globals.h"

void reciever();

int recv_packet();

void data_packet_handler(char *buffer, int size_recieved);

void dummy_packet_handler(char *buffer, int size_recieved);
