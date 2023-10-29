
# Client-side GUI applications.

all:

# The libraries, drivers and servers.
	make -C alpha/

	make -C browser/

# First client (GWS.BIN)
	make -C client/

	make -C cmdline/
	make -C doc/
	make -C editor/
	make -C gdm/
	#make -C setup/

# Virtual terminal connected with the child.
# It launches the child shell.
	make -C pubterm/


# The taskbar application
# important
	make -C taskbar/

# Virtual terminal 
# with an embedded command line interpreter.
	make -C terminal/


clean:
	-rm bin/*.BIN
clean-all:

	-rm alpha/drivers/bin/*.BIN
	-rm alpha/servers/bin/*.BIN

	#-rm -f alpha/libs/libcpp/obj/*.o
	-rm -f alpha/libs/libdisp/obj/*.o
	-rm -f alpha/libs/libgr/obj/*.o
	-rm -f alpha/libs/libgr3d/obj/*.o
	-rm -f alpha/libs/libgws/obj/*.o
	-rm -f alpha/libs/libio01/obj/*.o
	-rm -f alpha/libs/rtl/obj/*.o

	-rm bin/*.BIN


