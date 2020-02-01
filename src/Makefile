.PHONY: all clean

LIBRARIES := ../lib

INCLUDE := ../include

FILES := \
	vload.c

OPT := 
# OPT := -O

libX16.lib: $(FILES)
	cc65 $(OPT) -t cx16 -I $(INCLUDE) vload.c
	ca65 -t cx16 vload.s
	ar65 r libX16.lib vload.o
	cp *.lib $(LIBRARIES)
	rm -f *.o *.s

clean:
	rm -f $(LIBRARIES)/*.lib *.o *.s *.lib