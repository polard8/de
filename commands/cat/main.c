// cat - Concatenate files and print on the standard output
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
static char buffer[__BufferSize];

const char *VersionString = "Version 1.0";
const char *HelpString = "options: --help, --version, --number";
//...

//-----------------------------
static void doHelp(void);
static void doVersion(void);
// ...
static void __clear_buffer(void);
//-----------------------------

static void doHelp(void)
{
    printf("%s\n",HelpString);
}
static void doVersion(void)
{
    printf("%s\n",VersionString);
}

static void __clear_buffer(void)
{
    register int i=0;
    for (i=0; i<__BufferSize; i++)
        buffer[i] = 0;
}

int main(int argc, char *argv[])
{
    FILE *fp;
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

    if (argc <= 1){
        printf("Few parameters\n");
	doHelp();
        goto fail;
    }
    if (argc >= Max){
        printf("Too many files\n");
	goto fail;
    }

// Clear the tmp buffer.
// #todo: 
// Actually we're gonna malloc the buffer
// based on the file size. I guess.
    __clear_buffer();

// Probe for some flags.
    int isFlag = FALSE;
    for (i=1; i<argc; i++)
    {
        isFlag = FALSE;

        if ( strncmp( argv[i], "--help", 6) == 0 ){
            isFlag=TRUE;
	    doHelp();
            goto done;
        }
        if ( strncmp( argv[i], "--version", 9) == 0 ){
            isFlag=TRUE;
	    doVersion();
            goto done;
        }
        if ( strncmp( argv[i], "--number", 8) == 0 ){
            isFlag=TRUE;
	    fNumber = TRUE;
        }
        if ( strncmp( argv[i], "--show-tabs", 11) == 0 ){
            isFlag = TRUE;
	    fShowTabs = TRUE;
        }
        if ( strncmp( argv[i], "--show-ends", 11) == 0 ){
            isFlag = TRUE;
	    fShowEnds = TRUE;
        }
        
        //
        // It's NOT a flag.
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
	    // Print the file into the screen.
            // Write on stdout.
            nwrites = write( 1, buffer, sizeof(buffer) );
            if (nwrites <= 0){
                printf ("cat: File {%d} failed on write()\n", i);
                goto fail;
            }
	    // Clear the buffer
	    __clear_buffer();
        }
    };

done:
    return EXIT_SUCCESS;
fail:
    return EXIT_FAILURE;
}




