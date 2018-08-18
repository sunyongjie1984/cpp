/*  fileName    sigkill.c
    @Describe    Use kill function to send a signal to a process with the pid from argv[1]
 * @Author      vfhky 2015.08.03 https://typecodes.com/cseries/unixsigtermkill.html
 * @Return      success:0    failure: -1
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main( int argc, char ** argv )
{
    if( argc != 2 )
    {
        printf( "Usage: ./sigkill process_pid" );
        return -1;
    }
    printf( "You will send a signal to the process=[%s]!\n", argv[1] );
    kill( atoi(argv[1]), SIGTERM );
    printf( "Send over!\n" );
    return 0;
}
