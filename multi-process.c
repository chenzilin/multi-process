#include <wait.h>
#include <stdio.h>
#include <unistd.h>

#ifdef INITROOT_STARTUP
#include <initroot_startup.h>
#endif

int server_main(int argc, char *argv[])
{
    printf("========*******************===========\n");
    printf("          int server_main             \n");
    printf("========*******************===========\n");

    while(1); // loop to prevent return

    return 0;
}

#ifdef INITROOT_STARTUP
int startup_pre_end(void) { return 0; }
#endif

int main(int argc, char *argv[])
{
    pid_t pid = -1;
    unsigned continue_loop = 1;

#ifdef INITROOT_STARTUP
    startup_begin();
    startup_cend(startup_pre_end);
#endif

    do {
        if (0 == (pid = fork())) {

#ifdef RUN_SYSTEM_APP
            // para1: app path, para2: app name, para3: app para
            return execl("/bin/ls", "ls", "-l", NULL);
#else
            return server_main(argc, argv);
#endif
        }
        else if (pid > 0) {
            int status;
            wait(&status);
            fprintf(stdout, "server_main exit with status: %d\n", status);
        }
        else {
            fprintf(stdout, "main fork server fail: %d\n", pid);
            break;
        }
    } while (continue_loop);

#ifndef INITROOT_STARTUP
    return 0;
#else
    return startup_end(0);
#endif
}
