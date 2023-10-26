#include "std_headings.h"

int main() {
    // One file reads from file_desriptor[0] and the other reads from fd[1]
    static int file_descriptor[2], pipRet, nbytes;
    static pid_t fork_id;
    static char message[] = "Hello there!", buf[512];

    fork_id = fork();

    if(fork_id == -1) {
        perror("error opening file descriptor!\n");
        return EXIT_FAILURE;
    }
    printf("This is how file desc looks like %d[0] and %d[1]\n", file_descriptor[0], file_descriptor[1]);
    pipRet = pipe(file_descriptor);

    if(pipRet == -1) {
        perror("error creating pipe!\n");
    return EXIT_FAILURE;
    }

    if(fork_id == 0) {
        close(file_descriptor[0]);
        printf("This is the child process: \n");
        write(file_descriptor[1], message, (strlen(message)+1));
    } else {
        close(file_descriptor[1]);
        printf("This is the parent process: \n");
        nbytes = read(file_descriptor[0], buf, sizeof(buf));
        printf("Message from child: %s\nof size %d", buf, nbytes);
    }

    return EXIT_SUCCESS;
}