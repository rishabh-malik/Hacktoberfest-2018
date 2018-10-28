/*
 *  A Polite Fork Bomb
 *    CPU usage is monitored via getrusage() and the parent
 *    process shuts things down when MAX_CPU_TIME is reached
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/resource.h>

#define MAX_CPU_TIME  5500

static bool time_to_go_home = false;
static int forks = 0;

void misbehave(void)
{
    while (!time_to_go_home)
    {
	/* Burn some CPU cycles */
	for (int i = -50000; i < 50000; i++)
	{
	    if (i == 0)
		i = 2;
	}	
    }
}

void watch_the_children(void)
{
    /* rusage struct holds usage statistics from getrusage() */	
    struct rusage our_family = {0};
    getrusage(RUSAGE_SELF, &our_family);

    usleep(500000);    /* One half second delay */

    printf("Our CPU usage is %ld.%ld and I have fork()\'d %d children\n", 
        our_family.ru_utime.tv_sec, our_family.ru_utime.tv_usec, forks);

    /* be sure to terminate eventually */
    if (our_family.ru_utime.tv_usec >= MAX_CPU_TIME)
    {
	printf("Time to call it a day.\n");
	time_to_go_home = true;
    }
}

int main()
{
    while (!time_to_go_home)
    {
        pid_t child_pid;
        switch (child_pid = fork()) {
            case -1:
		/* An error occurred */    
	        printf("fork() failed\n");
	        exit(EXIT_FAILURE);
	    case 0:
		/* I am a child process */
	        misbehave();
	        exit(EXIT_SUCCESS);
	    default:
		/* I am the parent */
		forks++;
	        watch_the_children();
        }
    }
}
