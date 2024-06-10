
// rtl 
#include <types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
//#include <arpa/inet.h>
#include <sys/socket.h>
#include <packet.h>
// The client-side library.
#include <gws.h>

#include "browser.h"

int main( int argc, char *argv[] )
{
    return (int) main2(argc,argv);
}

