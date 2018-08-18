/** 
 * @FileName    sigterm.c
 * @Describe    Use kill function to send a signal to a process with the pid coming from argv[1]
 * @Author      vfhky 2015.08.03 https://typecodes.com/cseries/unixsigtermkill.html
 * @Excute      ./sigterm means sTerminate() do not exit before;  ./sigterm 1 means sTerminate() containing exit function.
 * @Return      0
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sTerminate();
static int iExtFlag = 0;

int main( int argc, char ** argv )
{
    sigset( SIGTERM, sTerminate );
    printf( "Main process_pid=[%d] will sleep!\n", getpid() );
    if( argc == 2 && *argv[1] == 0x31 )
        iExtFlag = 1;

    //the process will be hung up forever if not receving a signal.
    pause();

    //if there is a signal coming, this code will keep going. 
    printf( "Main process begin to work!\n" );

    //let the process being sleeping 10 sec, and exit then.
    sleep(10);
    printf( "Main process exit!\n" );
    return 0;
}

/**
 * functions to handle the signal of SIGTERM.
 * if the value of static variable iExtFlag is not equal zero, this func will exit without waiting for the main function to do to other things.
 */
void sTerminate()
{
    printf( "Get a SIGTERM signal!\n" );
    if( iExtFlag )
    {
        printf( "Making process exit!\n" );
        exit(EXIT_SUCCESS);
    }
    return;
}
