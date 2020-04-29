.PHONY: all clean

LIBRARIES := ../lib

INCLUDE := ../include

all: vload_test.prg load_bank_test.prg load_file_test.prg save_file_test.prg save_bank_test.prg soundfx_test.prg

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
	load_bank_test.c

load_bank_test.prg: $(FILES2)
	cl65 -t cx16 -o load_bank_test.prg -I $(INCLUDE) -L$(LIBRARIES) $(FILES2) libX16.lib cx16.lib

FILES3 := \
	load_file_test.c

load_file_test.prg: $(FILES3)
	cl65 -t cx16 -o load_file_test.prg -I $(INCLUDE) -L$(LIBRARIES) $(FILES3) libX16.lib cx16.lib

FILES4 := \
	save_file_test.c

save_file_test.prg: $(FILES4)
	cl65 -t cx16 -o save_file_test.prg -I $(INCLUDE) -L$(LIBRARIES) $(FILES4) libX16.lib cx16.lib

FILES5 := \
	save_bank_test.c

save_bank_test.prg: $(FILES5)
	cl65 -t cx16 -o save_bank_test.prg -I $(INCLUDE) -L$(LIBRARIES) $(FILES5) libX16.lib cx16.lib

FILES6 := \
	soundfx_test.c

soundfx_test.prg: $(FILES6)
	cl65 -t cx16 -o soundfx_test.prg -I $(INCLUDE) -L$(LIBRARIES) $(FILES6) libX16.lib cx16.lib

