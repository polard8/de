# It builds the de/ project.


all:
# Client-side GUI applications
	make -C apps/
	make -C apps/browser/
# Display server and libraries
	make -C ds/
# Extra: No time for this.
	make -C extra/aurora/
	make -C extra/commands/

clean:
# Client-side GUI applications
	-rm apps/bin/*.BIN
	-rm apps/browser/bin/*.BIN
# Display server and libraries
	-rm ds/server/bin/*.BIN
# Extra: No time for this.
	-rm extra/aurora/bin/*.BIN
	-rm extra/commands/bin/*.BIN

clean-all:
# Client-side GUI applications
	-rm apps/bin/*.BIN
	-rm apps/browser/bin/*.BIN
# Display server and libraries
	-rm ds/server/bin/*.BIN
# Extra: No time for this.
	-rm extra/aurora/bin/*.BIN
	-rm extra/commands/bin/*.BIN

