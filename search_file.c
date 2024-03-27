#include "multithread_search.h"

/**
 * @brief searchFile - A function that takes uses a thread to search
 *                     in a file for a keyword the user enteres
 *
 * @param arg: A struct that will get passed as a void so
 *             the thread could be created which holds the
 *             filename and keyword for the thread to search for.
 *
 * @return void*: Which is the normal for a thread function
*/
void *searchFile(void *arg) 
{
    ThreadData *data = (ThreadData *)arg;
    data->threadID = pthread_self();
    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    /**
    * Open the file and check if the opened file is NULL
    * or not
    */
    FILE *file = fopen(data->filename, "r");
    if (file == NULL) 
    {
        perror("Error opening file");
        pthread_exit(NULL);
    }

    /**
     * Start off by printing the thread id.
     * Then loop over the opened file looking for the keyword.
     *  - If keyword found print the filename, line number and the line
     * And end by printing a new line
    */
    printf("Thread #%lu:\n", data->threadID);
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        if (strstr(line, data->keyword) != NULL) 
        {
            printf("\t\tFound in file '%s' at line '%d': %s",
                                data->filename, line_number, line);
        }
        line_number++;
    }
    printf("\n");

    /**
     * Close the file & then close the thread as it's no
     * as it's no longer in use
    */
    fclose(file);
    pthread_exit(NULL);
}
