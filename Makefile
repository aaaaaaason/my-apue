ROOT=.
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)
include $(ROOT)/Make.libapue.inc

clean:
	rm -f $(TEMPFILES) *.o

%: $(LIBAPUE) %.o
