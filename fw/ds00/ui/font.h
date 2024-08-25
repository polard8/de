// font.h
// Headers for font support.
// Created by Fred Nora.

#ifndef GWS_FONT_H
#define GWS_FONT_H    1


#define DEFAULT_FONT_WIDTH  8
#define DEFAULT_FONT_HEIGHT  8
extern char *font_lt8x8;

#define FNT8X16_FONTDATAMAX   4096
extern unsigned char fontdata_8x16[FNT8X16_FONTDATAMAX];


//
// Font
//

//As fontes usadas pelo servidor gws
extern unsigned long g8x8fontAddress;          // 8×8, 80×25,CGA, EGA
extern unsigned long g8x14fontAddress;         // 8x14,80×25,EGA
extern unsigned long g8x16fontAddress;         // ??
extern unsigned long g9x14fontAddress;         // 9x14,80×25,MDA, Hercules
extern unsigned long g9x16fontAddress;         // 9x16,80×25,VGA
//extern unsigned long gws_eye_sprite_address;

// Font initialization
struct font_initialization_d
{
    int initialized;
    int width;
    int height;
    unsigned long address;
    // ...
};
// See: font.c
extern struct font_initialization_d  FontInitialization;


//
// == prototypes =============================
//

int font_initialize(void);

#endif   







