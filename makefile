paging: paging.o pagehandler.o
	gcc -Wall -o paging paging.o pagehandler.o
paging.o: paging.c paging.h
	gcc -c paging.c paging.h
pagehandler.o: pagehandler.c pagehandler.h paging.h
	gcc -c pagehandler.c pagehandler.h paging.h
make clean: *.o
	rm *.o
