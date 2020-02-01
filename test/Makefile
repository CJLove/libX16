.PHONY: all clean

LIBRARIES := ../lib

INCLUDE := ../include

all: vload_test.prg file_test.prg

clean:
	rm -f *.prg *.o *.s

FILES := \
	vload_test.c \
	$(LIBRARIES)/libX16.lib

vload_test.prg: $(FILES)
	cc65 -t cx16 -I $(INCLUDE) vload_test.c
	ca65 -t cx16 vload_test.s
	ld65 -t cx16 -L $(LIBRARIES) -o vload_test.prg vload_test.o libX16.lib cx16.lib
	rm -f *.o *.s

FILES2 := \
	file_test.c

file_test.prg: $(FILES2)
	cc65 -t cx16 file_test.c
	ca65 -t cx16 file_test.s
	ld65 -t cx16 -o file_test.prg file_test.o cx16.lib
	rm -f *.o *.s
