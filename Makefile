
all:
	make -C core/
	make -C shell/

clean:
	-rm core/server/bin/*.BIN
	-rm shell/bin/*.BIN

clean-all:
#todo: Clear the libs.
	-rm core/server/bin/*.BIN
	-rm shell/bin/*.BIN

