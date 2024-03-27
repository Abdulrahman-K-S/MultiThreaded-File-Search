#ifndef MULTITHREAD_SEARCH_H
#define MULTITHREAD_SEARCH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 256
#define MAX_KEYWORD_LENGTH 256
#define MAX_LINE_LENGTH 1024

/**
 * @brief ThreadData - A simple struct to hold the different number of
 *                     files alongside their names and the keyword for each to
 *                     look for.
 *
 * @param filename: A char that holds the filename with a maxiumum word length
 *                  of MAX_FILENAME_LENGTH. Which is defeault to 256.
 * @param keyword: A char that holds the keyword which the thread will look for
 *                 with a maximum word length of MAX_KEYWORD_LENGTH. Which is defeault to 256.
*/
typedef struct
{
    unsigned long threadID;
    char filename[MAX_FILENAME_LENGTH];
    char keyword[MAX_KEYWORD_LENGTH];
} ThreadData;

void *searchFile(void *arg);

#endif
