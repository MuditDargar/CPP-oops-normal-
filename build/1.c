#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int n= 10;
    int i=0;
    int status=0;

    printf("Creating %d children\n", n);
    for(i=0; i<n; i++)
    {
        pid_t pid = fork();

        if (pid == 0) /* only execute this if child */
        {
            // do something with the command line arguments
            // eg. execlp with argv[i]
            exit(0);
        }
        wait(&status);  /* only the parent waits */
    }

    printf("\nAll children process has terminated.\n");


    return 0;
}