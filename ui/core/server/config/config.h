
// config.h

#ifndef __CONFIG_H
#define __CONFIG_H    1

// Call a kernel service to draw rectangles.
// see: rect.c
#define USE_KERNEL_TO_DRAW_RECTANGLES  1


// Wallpaper.
#define CONFIG_USE_WALLPAPER  0
// Notification area, at the top.
#define CONFIG_USE_NA    1
// Taskbar at the bottom.
#define CONFIG_USE_TASKBAR    1

// see: wm.c
// Tile window manager.
#define CONFIG_USE_TILE    1

#endif    


