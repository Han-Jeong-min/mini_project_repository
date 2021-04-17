CC = gcc
CFLAGS = -W -Wall
TARGET = main
DTARGET = main_debug
MANA = manager.o
PRO = product.o
T_OBJECTS = main.c manager.o product.o
M_OBJECTS = manager.c manager.h
P_OBJECTS = product.c product.h
$(TARGET) : $(T_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(T_OBJECTS)
	$(CC) $(CFLAGS) -DEBUG -o $@ $^
$(MANA) : $(M_OBJECTS)
	$(CC) -c manager.c 
$(PRO)	: $(P_OBJECTS)
	$(CC) -c product.c
clean:
	rm *.o main
