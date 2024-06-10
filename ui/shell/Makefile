
# Client-side GUI applications.

all:

# The libraries

	make -C alpha/

#
# External shell 
#

	# Gramado Desktop Manager
	make -C desktop/gdm/
	# Taskbar (The launcher)
	make -C desktop/taskbar/

#
# Internal shell 
#

	make -C programs/browser/
	# First client (GWS.BIN)
	make -C programs/client/
	make -C programs/cmdline/
	make -C programs/doc/
	make -C programs/editor/
	# Virtual terminal connected with the child.
	# It launches the child shell.
	make -C programs/pubterm/
	# Setup programs to install the o.s.
	#make -C desktop/setup/ 
	# Virtual terminal 
	# with an embedded command line interpreter.
	make -C programs/terminal/


clean:
	-rm bin/*.BIN
clean-all:

	#-rm -f alpha/libs/libcpp/obj/*.o
	-rm -f alpha/libs/libdisp/obj/*.o
	-rm -f alpha/libs/libgr/obj/*.o
	-rm -f alpha/libs/libgr3d/obj/*.o
	-rm -f alpha/libs/libgws/obj/*.o
	-rm -f alpha/libs/libio01/obj/*.o
	-rm -f alpha/libs/rtl/obj/*.o

	-rm bin/*.BIN


