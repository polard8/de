
all:
	make -C core/
	make -C shell/

	make -C aurora/
	make -C browser/
	make -C commands/

clean:
	-rm core/server/bin/*.BIN
	-rm shell/bin/*.BIN

	-rm aurora/bin/*.BIN
	-rm browser/bin/*.BIN
	-rm commands/bin/*.BIN

clean-all:
#todo: Clear the libs.
	-rm core/server/bin/*.BIN
	-rm shell/bin/*.BIN

	-rm aurora/bin/*.BIN
	-rm browser/bin/*.BIN
	-rm commands/bin/*.BIN

