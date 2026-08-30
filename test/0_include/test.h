#ifndef TEST_H
#define TEST_H

#define FALSE 0
#define TRUE 1

/* basic */

#include <limits.h>    // INT_MAX, INT_MIN, etc.
#include <errno.h>     // errno, ERANGE, EINVAL...
#include <stdlib.h>    // malloc, free, exit, strtol...
#include <stdio.h>     // printf, fprintf, FILE...
#include <string.h>    // strlen, strcmp, memcpy...
#include <unistd.h>    // read, write, close, fork... (POSIX)


/*
    #include <assert.h>     // assert()
    #include <stdbool.h>   // bool, true, false
    #include <stddef.h>    // size_t, NULL, ptrdiff_t
    #include <stdint.h>    // int32_t, uint64_t, etc.


    #include <fcntl.h>         // open(), O_RDONLY...
    #include <sys/types.h>     // pid_t, ssize_t...
    #include <sys/stat.h>      // stat(), chmod()...
    #include <dirent.h>        // opendir(), readdir()...
    #include <signal.h>        // signal(), kill(), SIGINT...
    #include <sys/wait.h>      // wait(), waitpid()
    #include <time.h>          // time(), clock()

    #include <pthread.h>       // pthread_create(), mutex...
    #include <semaphore.h>     // sem_t, sem_wait...

    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netdb.h>
*/


#endif