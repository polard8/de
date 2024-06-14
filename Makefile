
all:
	make -C commands/
	make -C ui/
	make -C user3d/
clean:
	-rm -f *.o 
clean-all:
	-rm -f *.o 
	-rm -f commands/bin/*.BIN
	-rm -f ui/core/server/bin/*.BIN
	-rm -f ui/shell/bin/*.BIN
	-rm -f 3ddemos/bin/*.BIN
