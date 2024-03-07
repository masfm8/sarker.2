#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "ipc.h"


#define MSG_PERMS 0644
//#define _SVID_SOURCE
//#define _XOPEN_SOURCE

//typedef struct msgbuffer {
    //long mtype;
    //char mtext[100];
//} msgbuffer;

int main(void) {
    int msqid;
    key_t key;
    //msgbuffer msg;
    
    // Access the message queue
  key = ftok("msgqueuefile", 'b');
  msqid = msgget(key, MSG_PERMS | IPC_CREAT);
  if (msqid == -1) {
    perror("msgget");
    exit(1);
  }

  printf("WORKER PID:%d -- Just Starting\n", getpid());
      // Define a variable to control loop continuation
    int shouldTerminate = 0;
  
// Logic to check the shared memory clock goes here
while(shouldTerminate) {  // Placeholder condition
printf("WORKER PID:%d -- Checking clock and waiting for messages...\n", getpid());
    // ... logic for receiving messages and checking clock
printf("WORKER PID:%d -- Still running\n", getpid());
    // ... logic to determine if it's time to terminate
}
printf("WORKER PID:%d -- Terminating\n", getpid());

  // This might involve receiving messages from oss, accessing the clock, and
  // making decisions based on the information received.

  // Replace this with your actual implementation
  printf("Worker process running...\n");

  // Wait for a termination signal from oss (implementation needed)

  return 0;
}
