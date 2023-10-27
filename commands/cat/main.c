// cat - concatenate files and print on the standard output
// 2022 - Fred Nora.
// See:
// https://man7.org/linux/man-pages/man1/cat.1.html

//#include <rtl/gramado.h>
//#include <types.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define FALSE  0
#define TRUE   1

//4KB
#define __BufferSize  (4*1024)

static void doHelp(void);
static void doVersion(void);

//-----------------------------

static void doHelp(void)
{
    printf("~Help\n");
}
static void doVersion(void)
{
    printf("~Version\n");
}

int main(int argc, char *argv[])
{
    FILE *fp;
    static char buffer[__BufferSize];  // tmp

    int fd=-1;
    register int nreads = 0;
    register int nwrites = 0;
    size_t size=0;
    int Max = 8;  //#test
    register int i=0;
// Flags
    int fNumber=FALSE;
    int fShowTabs=FALSE;
    int fShowEnds=FALSE;

    /*
    // #debug
    printf("CAT.BIN: argc %d | argv[0] %s | argv[1] %s\n", 
        argc,       // quantos argumentos 
        argv[0],    // CAT.BIN
        argv[1] );  // FILE.TXT
    printf("\n");
    */

    if (argc <= 0){
        printf("cat: No args\n");
        goto fail;
    }
    if (argc == 1){
        printf("cat: We need more args\n");
        //call usage()
        goto fail;
    }

// Clear the tmp buffer.
// #todo: Actually we're gonna malloc the buffer
// based on the file size. I guess.

    for (i=0; i<__BufferSize; i++){
        buffer[i] = 0;
    };

    if (argc > Max){
        printf("Too much files in the commnad line\n");
        goto fail;
    }

// Probe for some flags.
    int isFlag=FALSE;
    for (i=1; i<argc; i++)
    {
        isFlag=FALSE;

        if ( strncmp( argv[i], "--help", 6) == 0 ){
            doHelp();
            isFlag=TRUE;
            goto done;
        }
        if ( strncmp( argv[i], "--version", 9) == 0 ){
            doVersion();
            isFlag=TRUE;
            goto done;
        }
        if ( strncmp( argv[i], "--number", 8) == 0 ){
            fNumber = TRUE;
            isFlag=TRUE;
        }
        if ( strncmp( argv[i], "--show-tabs", 11) == 0 ){
            fShowTabs = TRUE;
            isFlag=TRUE;
        }
        if ( strncmp( argv[i], "--show-ends", 11) == 0 ){
            fShowEnds = TRUE;
            isFlag=TRUE;
        }
        
        //
        // It's not a flag.
        //

        // Open the file and print the content into the screen.
        if (isFlag == FALSE)
        {
            fd = (int) open((char *) argv[i], 0, "a+");
            if (fd < 0){
                goto fail;
            }
            // Read from fd.
            nreads = read( fd, buffer, 511 );
            if (nreads <= 0){
                printf ("cat: read() failed\n");
                goto fail;
            }
            // Write on stdout.
            nwrites = write( 1, buffer, sizeof(buffer) );
            if (nwrites <= 0){
                printf ("cat: File {%d} failed on write()\n", i);
                goto fail;
            }
        }
    };

done:
    return EXIT_SUCCESS;
fail:
    return EXIT_FAILURE;
}




