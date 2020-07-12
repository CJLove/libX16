.PHONY: all clean

LIBRARIES := ../lib

INCLUDE := ../include

FILES := \
	vload.c load.c save.c soundfx.c

OBJ = $(FILES:%.c=%.o)

OPT := -Oi
# OPT := -g

.c.o:
	cc65 -t cx16 $(OPT) -I $(INCLUDE) $<
	ca65 -t cx16 $(<:%.c=%.s)

libX16.lib: $(OBJ)
	ar65 r libX16.lib $(OBJ)
	cp *.lib $(LIBRARIES)

clean:
	rm -f $(LIBRARIES)/*.lib *.o *.s *.lib

artifacts: all
	cd .. ; rm -f libX16.zip ; zip libX16.zip include/* lib/*

