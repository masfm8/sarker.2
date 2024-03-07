#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "ipc.h"


#define MAX_WORKERS 20
#define MSG_PERMS 0644
//#ifndef MSG_BUFFER_H
//#define MSG_BUFFER_H
//#define _XOPEN_SOURCE 700 // at the very top of oss.c, before any #include statements
//#define _SVID_SOURCE



//typedef struct msgbuffer {
    //long mtype;
   // char mtext[100];
//} msgbuffer;
//#endif // MSG_BUFFER_H

int main(void) {
    int msqid;
    key_t key;
    pid_t pid, workers[MAX_WORKERS];
    key = ftok("msgqueuefile", 'b');
	    if (key == -1) {
        perror("ftok");
        return 1;
    }
    msqid = msgget(key, MSG_PERMS | IPC_CREAT);
	    if (msqid == -1) {
        perror("msgget");
        return 1;
    }
	

    printf("OSS: Message queue created with ID: %d\n", msqid);



    // Fork the worker processes
    for (int i = 0; i < MAX_WORKERS; ++i) {
        pid = fork();
        if (pid == 0) { // Child process
            execl("./worker", "worker", (char *)NULL);
            perror("execl"); // If execl fails
            exit(1);
        } else if (pid < 0) { // fork failed
            perror("fork");
            return 1;
        } else { // Parent process
            workers[i] = pid;
            printf("OSS: Worker process %d created with PID %d\n", i, pid);
        }
    }
    
    // Implement your messaging and round-robin logic here

    // Wait for all worker processes to terminate
    for (int i = 0; i < MAX_WORKERS; ++i) {
        int status;
        pid_t childPid = waitpid(workers[i], &status, 0);
        if (childPid != -1) {
            printf("OSS: Worker process %d terminated\n", i);
        }
    }

    // Delete the message queue
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("OSS: Message queue deleted\n");

    return 0;
}
