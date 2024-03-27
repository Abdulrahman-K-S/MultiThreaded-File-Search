#include "multithread_search.h"

/**
 * @brief main - The starting point for the program.
 *
 * @param argc: The number of arguements passed to the program.
 * @param argv: The different arguements passed to the program.
 *
 * @return int: 0 indicating success or 1 indicating exit/fail
*/
int main(int argc, char *argv[]) 
{
    char *keyword = NULL;
    pthread_t threads[MAX_FILES];
    ThreadData thread_data[MAX_FILES];
    int num_files = 0;

    /*Check if the entered arguements are the appropriate ammount or not*/
    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s <keyword> <file1> <file2> ... <fileN>\n", argv[0]);
        return (1);
    }

    /*Parse the keyword so the threads could look for it later*/
    keyword = argv[1];

    /**Parse the number of files the user has set for the program to look for
    * Why -2 from the arguements number?
    * - Because the first is the program name while the second is the keyword to look for.
    */
    num_files = argc - 2;
    if (num_files > MAX_FILES)
    {
        fprintf(stderr, "Exceeded maximum number of files\n");
        return (1);
    }

    /**Loop over the number of files and copy their content into
     * the struct then create that thread.
    */
    for (int i = 0; i < num_files; i++)
    {
        strncpy(thread_data[i].filename, argv[i + 2], MAX_FILENAME_LENGTH - 1);
        strncpy(thread_data[i].keyword, keyword, MAX_KEYWORD_LENGTH - 1);
        pthread_create(&threads[i], NULL, searchFile, &thread_data[i]);
    }

    /**Loop over the number of files and wait for their threads
     * to finish executing.
    */
    for (int i = 0; i < num_files; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return (0);
}
