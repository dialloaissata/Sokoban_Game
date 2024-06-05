LD_LIBRARY_PATH =/../install_dir/lib
CFLAGS+= -Wall -std=c11 -Wextra	  # option de compilation
LDFLAGS+= -lm -L/../install_dir -l SDL2 -Wl,-rpath=$(LD_LIBRARY_PATH)	#Edition des liens
IFLAGS = -Iinclude

OPATH = obj/
CPATH = src/
BPATH = bin/

INPUT = include/
INPUT = src/


vpath %.h include
vpath %.c src
vpath %.o obj

sokoban: grid.o player.o main.o sdl2.o
	gcc $(OPATH)*.o -o sokoban $(LDFLAGS)
	

grid.o: grid.c grid.h
	gcc $(CFLAGS) -c $(CPATH)grid.c $(IFLAGS)
	mv grid.o $(OPATH)
	
player.o: player.c player.h
	gcc $(CFLAGS) -c $(CPATH)player.c $(IFLAGS)
	mv player.o $(OPATH)
	
main.o:main.c
	gcc $(CFLAGS) -c $(CPATH)main.c $(IFLAGS)
	mv main.o $(OPATH)
	
sdl2.o:sdl2.c sdl2.h
	gcc $(CFLAGS) -c $(CPATH)sdl2.c $(IFLAGS)
	mv sdl2.o $(OPATH)
	
run:
	cd ./bin/ && ./sokoban
	
install_dir:
	cd ../SDL2 && ./configure --prefix=$PWD/../install_dir
	cd ../SDL2 && make install -j6
	
clean : 
	rm obj/* bin/*

clean_all:
	rm html *.tar.gz
	
doc:
	doxygen Doxyfile

archive:
	tar -cvf DIALLO_AISSATA_IGERSHEIM_EMILIE.tar.gz src include html install_dir obj Makefile level1.txt README.md Doxyfile
