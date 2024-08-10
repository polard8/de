# It builds the de/ project.

all:
# Display server and libraries
	make -C core/
# Client-side GUI applications
	make -C shell/
# Extra: No time for this.
	make -C t00/aurora/
	make -C t00/browser/
	make -C t00/commands/

clean:
# Display server and libraries
	-rm core/server/bin/*.BIN
# Client-side GUI applications
	-rm shell/bin/*.BIN
# Extra: No time for this.
	-rm t00/aurora/bin/*.BIN
	-rm t00/browser/bin/*.BIN
	-rm t00/commands/bin/*.BIN

clean-all:
# Display server and libraries
	-rm core/server/bin/*.BIN
# Client-side GUI applications
	-rm shell/bin/*.BIN
# Extra: No time for this.
	-rm t00/aurora/bin/*.BIN
	-rm t00/browser/bin/*.BIN
	-rm t00/commands/bin/*.BIN


