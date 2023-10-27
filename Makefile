
all:
	make -C commands/
	make -C ui/
clean:
	-rm -f commands/bin/*.BIN
	-rm -f ui/core/server/bin/*.BIN
	-rm -f ui/shell/bin/*.BIN

