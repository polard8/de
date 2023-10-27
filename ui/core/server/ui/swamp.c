
#include "../gwsint.h"

//struct taskbar_d  TaskBar;
//struct start_menu_d StartMenu;
//struct quick_launch_d QuickLaunch;

//const char *startmenu_label = "Gramado";


// Taskbar
#define TB_BUTTON_PADDING  2
// 36
//#define TB_HEIGHT  40
#define TB_HEIGHT  (24+TB_BUTTON_PADDING+TB_BUTTON_PADDING)
//#define TB_BUTTON_PADDING  4
#define TB_BUTTON_HEIGHT  (TB_HEIGHT - (TB_BUTTON_PADDING*2))
#define TB_BUTTON_WIDTH  TB_BUTTON_HEIGHT
// #define TB_BUTTONS_MAX  8


//--------------

void __create_start_menu(void);
// Launch area
void __create_quick_launch_area(void);


//-----------------------------------------


void __create_start_menu(void)
{
}


void __create_quick_launch_area(void)
{
}



// Taskbar
// Display server's widget.
// Cria a barra na parte de baixo da tela.
// com 4 tags.
// os aplicativos podem ser agrupados por tag.
// quando uma tag eh acionada, o wm exibe 
// todos os aplicativos que usam essa tag.
void create_taskbar(int issuper, int show)
{

// ----------------------------
// The taskbar created by the user.
    taskbar2_window = NULL;


/*
// Called by initGUI() in main.c

    unsigned long w = gws_get_device_width();
    unsigned long h = gws_get_device_height();
    int wid = -1;
// Colors for the taskbar and for the buttons.
    unsigned int bg_color     = (unsigned int) get_color(csiTaskBar);
    //unsigned int frame_color  = (unsigned int) get_color(csiTaskBar);
    //unsigned int client_color = (unsigned int) get_color(csiTaskBar);

    unsigned long tb_height = METRICS_TASKBAR_DEFAULT_HEIGHT;

    if (w==0 || h==0){
        gwssrv_debug_print ("create_taskbar: w h\n");
        printf             ("create_taskbar: w h\n");
        exit(1);
    }

    TaskBar.initialized = FALSE;

// Super?
    //TaskBar.is_super = FALSE;
    //TaskBar.is_super = TRUE;
    TaskBar.is_super = (int) issuper;
    if (TaskBar.is_super != TRUE && TaskBar.is_super != FALSE)
    {
        TaskBar.is_super = FALSE;
    }

// It was created by the server.
    TaskBar.is_embedded = TRUE;

// Taskbar.
// Create  window.

    tb_height = METRICS_TASKBAR_DEFAULT_HEIGHT;
    if (TaskBar.is_super == TRUE){
        tb_height = METRICS_SUPERTITLEBAR_DEFAULT_HEIGHT;
    }

    //if (tb_height<40)
    if (tb_height<24){
        tb_height = 24;
    }
    if(tb_height >= h){
        tb_height = h-40;
    }

    unsigned long wLeft   = (unsigned long) 0;
    unsigned long wTop    = (unsigned long) (h-tb_height);
    unsigned long wWidth  = (unsigned long) w;
    unsigned long wHeight = (unsigned long) tb_height;  //40;

    TaskBar.left   = (unsigned long) wLeft;
    TaskBar.top    = (unsigned long) wTop;
    TaskBar.width  = (unsigned long) wWidth;
    TaskBar.height = (unsigned long) wHeight;

    unsigned long tb_style = WS_TASKBAR;

    taskbar_window = 
        (struct gws_window_d *) CreateWindow ( 
                                    WT_SIMPLE, 
                                    tb_style, //style
                                    1, //status 
                                    1, //view
                                    "TaskBar",  
                                    wLeft, wTop, wWidth, wHeight,   
                                    gui->screen_window, 0, 
                                    bg_color, 
                                    bg_color );



// Struture validation
    if ( (void *) taskbar_window == NULL ){
        gwssrv_debug_print ("create_taskbar: taskbar_window\n"); 
        printf             ("create_taskbar: taskbar_window\n");
        exit(1);
    }
    if ( taskbar_window->used != TRUE || taskbar_window->magic != 1234 ){
        gwssrv_debug_print ("create_background: taskbar_window validation\n"); 
        printf             ("create_background: taskbar_window validation\n");
        exit(1);
    }

// Register the window.
    wid = (int) RegisterWindow(taskbar_window);
    if (wid<0){
        gwssrv_debug_print ("create_taskbar: Couldn't register window\n");
        printf             ("create_taskbar: Couldn't register window\n");
        exit(1);
    }

// wid
    taskbar_window->id = wid;
// Setup Window manager.
    WindowManager.taskbar = (struct gws_window_d *) taskbar_window;
// Show
    //flush_window(taskbar_window);

    TaskBar.wid = wid;

    TaskBar.initialized = TRUE;


// ----------------------------
// The taskbar created by the user.
    taskbar2_window = NULL;

// #debug

    //printf ("bar: %d %d %d %d\n",
    //    taskbar_window->left,
    //    taskbar_window->top,
    //    taskbar_window->width,
    //    taskbar_window->height );
    //refresh_screen();
    //while(1){}
    

//
// Start menu.
//

// Start menu.
    //__create_start_menu();

//
// Quick launch area.
//

// Quick launch area.
    //__create_quick_launch_area();

// Show
    if (show)
        flush_window_by_id(wid);
*/

}

// Teremos mais argumentos
void wm_Update_TaskBar(char *string, int flush)
{
}

void swamp_update_taskbar(char *string, int flush)
{
    if ((void*) string == NULL)
        return;
}








