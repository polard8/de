
// swamp.h
// Swamp area.

#ifndef __AREAS_SWAMP_H
#define __AREAS_SWAMP_H    1

#define SWAMP_STATE_GRACE  2000
#define SWAMP_STATE_BRIO   1000

struct swamp_info_d
{
// BRIO, GRACE
    int state;
};

/*
// ----------------------------
// Start menu
struct start_menu_d
{
    int initialized;
    int wid;
    int is_created;
    int is_selected;   // Focus
    int is_visible;  // Pressed
};
extern struct start_menu_d StartMenu;
*/

/*
// ----------------------------
// Quick launch area
// default left position.
#define QUICK_LAUNCH_AREA_PADDING  80
#define QL_BUTTON_MAX  4
struct quick_launch_d
{
    int initialized;
// Número de botões efetivamente criados.
    int buttons_count;
// List of buttons. (wid)
    int buttons[QL_BUTTON_MAX];
};
extern struct quick_launch_d  QuickLaunch;
*/

/*
// ----------------------------
struct taskbar_d
{
    int initialized;

    int wid;

    unsigned long left;
    unsigned long top;
    unsigned long height;
    unsigned long width;

    int is_super;  // Higher
    int is_embedded;  // Created by the server.
    // ...
    
};
extern struct taskbar_d  TaskBar;
*/


void create_taskbar(int issuper, int show);
void wm_Update_TaskBar( char *string, int flush );

void swamp_update_taskbar(char *string, int flush);

#endif   

