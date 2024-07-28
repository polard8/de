
#ifndef __BROWSER_H
#define __BROWSER_H    1


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


#include "00ui/ui.h"
#include "01net/net.h"
#include "02engine/engine.h"

//#include "your/assets/..."

int uiInitialize( int argc, char *argv[] );

#endif   


