# It builds the de/ project.

all:

# Display server and libraries
	make -C fw/

# Client-side GUI applications
	make -C apps/
	make -C apps/browser/

# Extra: No time for this.
	make -C native/aurora/
	make -C native/commands/

clean:
# Display server and libraries
	-rm fw/server/bin/*.BIN
# Client-side GUI applications
	-rm apps/bin/*.BIN
	-rm apps/browser/bin/*.BIN
# Extra: No time for this.
	-rm native/aurora/bin/*.BIN
	-rm native/commands/bin/*.BIN

clean-all:
# Display server and libraries
	-rm fw/server/bin/*.BIN
# Client-side GUI applications
	-rm apps/bin/*.BIN
	-rm apps/browser/bin/*.BIN
# Extra: No time for this.
	-rm native/aurora/bin/*.BIN
	-rm native/commands/bin/*.BIN


