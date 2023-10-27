
// ffa.h
// Far Far Away area.

#ifndef __AREAS_FFA_H
#define __AREAS_FFA_H    1


#define FFA_STATE_GRACE   2000
#define FFA_STATE_UNBRIO  1000

struct ffa_info_d
{
// UNBRIO, GRACE
    int state;
};


//
// Yellow status bar.
//

void yellowstatus0(char *string,int refresh);
void yellow_status(char *string);
void ffa_status(char *string);

#endif   


