
// comp.h
// The purpose of these routines is compose the final frame
// into the backbuffer and display it into the frontbuffer.

#ifndef __COMP_H
#define __COMP_H    1

extern int __compose_lock;

// Flush the window's rectangle
int gws_show_window_rect(struct gws_window_d *window);

//
// Flush window
//

int flush_window(struct gws_window_d *window);
int flush_window_by_id(int wid);


//
// Flush backbuffer.
//

void gwssrv_show_backbuffer (void);
// Flush the whole backbuffer.
void flush_frame(void);

//
// Compose
//

// A worker for wmCompose().
void reactRefreshDirtyWindows(void);
void wmReactToPaintEvents(void);
// A worker for wmCompose().
void compose(void);
void 
wmCompose(
    unsigned long jiffies, 
    unsigned long clocks_per_second );


//
// Mouse support.
//

long comp_get_mouse_x_position(void);
long comp_get_mouse_y_position(void);
void comp_set_mouse_position(long x, long y);
void comp_initialize_mouse(void);
void mouse_at(void);

void set_refresh_pointer_status(int value);

#endif    


