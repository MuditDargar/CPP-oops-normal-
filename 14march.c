#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);  // get number of processes from command-line argument

    for (int i = 1; i <= n; i++) {
        pid_t pid = fork();  // create a child process
        if (pid == 0) {
            // child process
            char *program;
            switch (i % 3) {
                case 0:
                    program = "./program1";  // execute program1 for every 3rd child
                    break;
                case 1:
                    program = "./program2";  // execute program2 for every 1st child
                    break;
                case 2:
                    program = "./program3";  // execute program3 for every 2nd child
                    break;
            }
            execl(program, program, NULL);  // execute the program
            exit(0);  // exit the child process
        } else if (pid < 0) {
            printf("Error creating child process %d\n", i);
            exit(1);
        }
    }

    // parent process
    printf("Created %d child processes\n", n);
    return 0;
}
