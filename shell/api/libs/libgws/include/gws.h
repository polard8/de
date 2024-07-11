/*
 * File: gws.h 
 *     Client-side library for Gramado Window Server. 
 * History:
 *     2020 -  Created by Fred Nora.
 */

//
// == Base ===========================================
//


#include "version.h"

// Definitions and types.
#include "gwsdefs.h"

//h:d.s
#include "base/screen.h"
#include "base/display.h"
#include "base/host.h"

//
// Connections
//

// Network ports used by the socket routines.
#include "base/ports.h"
// Part of the connection/communication support.
#include "base/gwspack.h"
// Read and write from socket.
#include "base/rw.h"

#include "base/connect.h"

// The lingws protocol.
#include "protocol.h"

#include "grambase.h"


//
// == Gr ===========================================
//

// Client-side 3D graphics support.
#include "gr/gr.h"


//
// == User ===========================================
//

// This is the part when we support
// the interaction with the user.


// Virtual keys.
#include "user/vk.h"
// Window Messages.
#include "user/wm.h"
// Window types.
#include "user/wt.h"
// Colors.
#include "user/colors.h"
// Windows.
#include "user/window.h"
// Menu
#include "user/menu.h"
// Events
#include "user/events.h"

#include "gramuser.h"

//
// End
//

