
all:
	make -C core/
	make -C shell/
	make -C teabox/

clean:
	-rm core/server/bin/*.BIN
	-rm shell/bin/*.BIN
	-rm teabox/bin/*.BIN

clean-all:
#todo: Clear the libs.
	-rm core/server/bin/*.BIN
	-rm shell/bin/*.BIN
	-rm teabox/bin/*.BIN

