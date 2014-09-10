#pragma once

#include <stdio.h>
#include "uthash.h"
#include "config.h"
#include "my402list.h"

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/wait.h>

// Print function name, filename and line number in print
#define DEBUG(fmt, ...) printf("%s:%d: " fmt, __FILE__, __LINE__, __VA_ARGS__);
#define DBG(...) do{fprintf(stderr, "%s (%s, line %d): ", __func__, __FILE__, __LINE__); \
                         fprintf(stderr, __VA_ARGS__);           \
                         fprintf(stderr, "\n");} while(0)
#define DATA "DATA"
#define NACK "NACK"

// Hashmap data structure
typedef struct hashl {
    // Sequence number
    long long unsigned int seq_num;
    // Address of the node in list.
    My402ListElem *data_node_ptr;
    My402ListElem *nack_node_ptr;
    UT_hash_handle hh;
} hashed_link;

// Data list is stored as node below
// Both nack and data list have same type of node
struct node {
    long long unsigned int seq_num;
    // Its pointing to the start address of data
    char *mem_ptr;
    // Size in bits
    long long unsigned int size;
};

// datal --> Data list
// nackl --> Nack list
struct globals {
    struct config config;
    // Hashmap
    hashed_link *hashl;
    // Linked list
    My402List datal;
    My402List nackl;
    // Current maximum recieved seq num
    long long unsigned current_seq;
    // Reciever fd
    int recv_fd;
    // Sender fd
    int sender_fd;
    // Socket address to the reciever
    struct sockaddr_in serv_addr;
    char hostname_b[100];
    char recv_filename[100];
};

extern struct globals globals;
