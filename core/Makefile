# Gramado display server.

all:

# Libraries
	make -C libs/

# Display servers
	make -C ds00/
#	make -C ds01/
# ...
	make -C dsx/

clean:
	-rm -f ds00/bin/*.BIN
#	-rm -f ds01/bin/*.BIN
	-rm -f dsx/bin/*.BIN
