#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <sched.h>
#include <linux/sched.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(int argc, char *argv[])
{
    int i, ret;

    for (i = 0; i < 10000; i++) {

        if (0 == (ret = syscall(__NR_clone, CLONE_NEWPID | CLONE_NEWIPC |
CLONE_NEWNET | SIGCHLD, NULL)))
            return 0;

        if (-1 == ret) {
            perror("clone");
            break;
        }

    }

    return 0;
}

