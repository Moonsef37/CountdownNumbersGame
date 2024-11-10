CFLAGS = -Wall
LDFLAGS= -lm

CC=gcc

algorithme1: recapFonctions.c algorithme1.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	
algorithme2: recapFonctions.c algorithme2.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
