
// ffa.c

#include "../gwsint.h"


// yellow bar. (rectangle not window)
// developer status.
void yellowstatus0(char *string,int refresh)
{
// System notifications?
// Combinations

// methods. get with the w.s., not with the system.
    unsigned long w = gws_get_device_width();
    unsigned long h = gws_get_device_height();

// String offset
// right after the bmp icon. (16x16)
    unsigned long offset_string1 = 48;  //( 8*1 );
    //unsigned long offset_string2 = ( 8*5 );
    //unsigned long bar_size = w;
    //struct gws_window_d *aw;

    if (WindowManager.initialized != TRUE)
        return;

/*
    // Working Area
    unsigned long Left   = 0;  //WindowManager.wa.left;
    unsigned long Top    = 0;  // WindowManager.wa.top;
    unsigned long Width  = w;  //WindowManager.wa.width;
    unsigned long Height = 24; //WindowManager.wa.height;
*/
/*
    unsigned long Left   = WindowManager.wa.left;
    unsigned long Top    = WindowManager.wa.height - 24;
    unsigned long Width  = w;  //WindowManager.wa.width;
    unsigned long Height = 24; //WindowManager.wa.height;
*/

    unsigned long Left   = WindowManager.wa.width >> 1;
    unsigned long Top    = WindowManager.wa.height - 24;
    unsigned long Width  = WindowManager.wa.width >> 1;
    unsigned long Height = 24; //WindowManager.wa.height;


    unsigned long bar_size = Width;
    unsigned int bar_color = COLOR_WHITE;

// Validation
    //aw = (struct gws_window_d *) windowList[active_window];
    //aw = (void*) active_window;
    //if ( (void*) aw == NULL ){
    //    return;
    //}
    //if (aw->magic!=1234){
    //    return;
    //}

    //if(aw->type!=WT_OVERLAPPED){
    //    return;
    //}

    //debug_print ("yellow_status:\n");
    
    //#todo
    //if ( (void*) string == NULL ){ return; }
    //if ( *string == 0 ){ return; }


// paint the bar into the backbuffer
    painterFillWindowRectangle ( 
        Left, Top, bar_size, Height, 
        bar_color, 0 );

// paint the bmp into the backbuffer
// dont show it.
// bar = 24
// 24-16 = 8;
// 8/2=4
    bmp_decode_system_icon( 
        (int) 1,  // icon id 
        (unsigned long) Left +4, 
        (unsigned long) Top +4,
        FALSE );  // dont show it

// Paint the string, but dont show it.
    grDrawString ( 
        Left + offset_string1, 
        Top  +8, 
        COLOR_BLACK, 
        string );

    //grDrawString ( offset_string2, 8, COLOR_BLACK, "FPS" );

    if (bar_size == 0){
        bar_size = 32;
    }

// Mostra o retângulo.
    if (refresh){
        gws_refresh_rectangle( Left, Top, bar_size, Height );
    }
}

void yellow_status(char *string)
{
    if ( (void*)string==NULL ){
        return;
    }
    yellowstatus0(string,TRUE);
}

// System notifications?
// Combinations?
void ffa_status(char *string)
{
    if ((void*) string == NULL)
        return;
    yellow_status(string);
}






