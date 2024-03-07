#ifndef IPC_H
#define IPC_H

#include <sys/types.h>

// Define permissions for the message queue
#define PERMS 0644

// Define the key file for ftok
#define KEY_FILE "msgq.txt"

// Define a maximum message size
#define MAX_MSG_SIZE 100

// Message buffer structure for sending and receiving messages
typedef struct msgbuffer {
    long mtype;             // message type, must be > 0
    char mtext[MAX_MSG_SIZE]; // message data
    int mdata;              // Additional integer data if needed
} msgbuffer;

// Define any other constants, global variables, or function prototypes here

#endif // IPC_H
