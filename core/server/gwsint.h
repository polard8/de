// gwsint.h 
// Internal definitions for Gramado Window Server.
// Created by Fred Nora.

// Version?
// See protocol version in protocol.h.

// ...
extern int current_mode;

// rtl
#include <types.h>
#include <sys/types.h>
#include <sys/cdefs.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <rtl/gramado.h>


// Gramado Window Server
#include "gws.h"
#include "callback.h"

// Configuration and debug support.
#include "config/config.h"
#include "protocol.h"
#include "async.h"
#include "globals.h"
#include "vwui/colors.h"
#include "vwui/themes/humility.h"
#include "vwui/themes/honey.h"

// #imported
// Display device library.
#include <libdisp.h>

#include "vwlib/char.h"
#include "vwlib/dtext.h"
#include "vwlib/line.h"

#include "vwui/wt.h"
#include "vwui/menu.h"
//#include "zres/grinput.h"   //#test
#include "vwui/metrics.h"
#include "vwui/window.h"
#include "vwui/areas/bar.h"    // Notification bar. (yellow)
#include "vwui/areas/wa.h"     // Working Area
#include "vwui/areas/swamp.h"  // Swamp
#include "vwui/wm.h"

#include "vwlib/bitblt.h"

#include "vwui/vdesktop.h"
#include "vwui/painter.h"
#include "vwui/bmp.h"

// h:0.0
#include "osdep/gramado/screen.h"   // X-like
#include "osdep/gramado/display.h"  // X-like
#include "osdep/gramado/host.h"     // X-like h:0.0

#include "osdep/gramado/surface.h"
#include "osdep/gramado/gramado.h"


#include "vwui/gui.h"

// Compositor
#include "vwc/comp.h"

#include "event.h"    // view inputs

// #imported

#include <grprim0.h>
#include <libgr.h>

#include "vwlib/grprim.h"
#include "vwlib/camera.h"
#include "vwlib/proj.h"

#include "sprite.h"
#include "demos.h"

#include "osdep/gramado/packet.h"
#include "osdep/gramado/connect.h"

#include "vwui/font.h"

// Client structure.
// O proprio servidor poderia ser o cliente 0??
#include "client.h"

// Device Context.
// This is the structure that is gonna be used by the
// drawing routines.
// 'dc->something'
// It needs to be the last one.
#include "osdep/gramado/dc.h"

#include "actions.h"


struct gws_graphics_d
{
    int used;
    int magic;
    struct gui_d  *gui;
    // ...
};
extern struct gws_graphics_d *Currentgraphics;


struct engine_d
{

// flag: When to quit the engine.
// We can quit the engine and reinitialize it again.
    int quit;
// Engine status
    int status;
// graphics support.
    struct gws_graphics_d *graphics;
    // ...
};
extern struct engine_d  Engine;


// MAIN STRUCTURE
// This is the main data structure for the display server.

struct display_server_d 
{
    int initialized;

// The name of the display server.
    char name[64];
    char edition_name[64];

    char version_string[16];

    unsigned long version_major;
    unsigned long version_minor;

// fd
    int socket;

// flag: When to quit the display server.
    int quit;

// display server status
    int status;

// sinaliza que registramos o servidor no sistema.
    int registration_status;
    int graphics_initialization_status;
    // ...

// Se devemos ou não lançar o primeiro cliente.
    int launch_first_client;

// graphics engine 
    struct engine_d *engine;
    
    // os info.
    // input support
    // ...
};

//see: main.c
extern struct display_server_d  *display_server;

#define STATUS_RUNNING    1

//
// == Prototypes =============================
//

void invalidate(void);
void validate(void);
int isdirty(void);

void invalidate_background(void);
void validate_background(void);
int is_background_dirty(void);

void gwssrv_set_keyboard_focus(int window);

void xxxThread (void);
void ____test_threads (void);

void *gwssrv_create_thread ( 
    unsigned long init_eip, 
    unsigned long init_stack, 
    char *name );

void gwssrv_start_thread (void *thread);

// Drain input
int service_drain_input (void);

void gwssrv_debug_print (char *string);

unsigned long gwssrv_get_system_metrics (int index);

void gwssrv_enter_critical_section (void);
void gwssrv_exit_critical_section (void);

char *gwssrv_get_version(void);

unsigned long gws_get_device_width(void);
unsigned long gws_get_device_height(void);

void gws_show_backbuffer(void);
void gwssrv_quit(void);
void gwssrv_broadcast_close(void);

int is_accepting_input(void);
void set_input_status(int is_accepting);

void ServerShutdown(int server_fd);

//
// End
//


