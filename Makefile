# It builds the de/ project.


all:
# Client-side GUI applications
	make -C apps/
	make -C apps/browser/
# Display server and libraries
	make -C fw/
# Extra: No time for this.
	make -C native/aurora/
	make -C native/commands/


clean:
# Client-side GUI applications
	-rm apps/bin/*.BIN
	-rm apps/browser/bin/*.BIN
# Display server and libraries
	-rm fw/server/bin/*.BIN
# Extra: No time for this.
	-rm native/aurora/bin/*.BIN
	-rm native/commands/bin/*.BIN


clean-all:
# Client-side GUI applications
	-rm apps/bin/*.BIN
	-rm apps/browser/bin/*.BIN
# Display server and libraries
	-rm fw/server/bin/*.BIN
# Extra: No time for this.
	-rm native/aurora/bin/*.BIN
	-rm native/commands/bin/*.BIN

