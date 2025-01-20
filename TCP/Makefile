COMPILER=gcc
EXE_DIR=/tmp/
FICHIERS=erreur tcp nombre
OBJS:=$(FICHIERS:%=%.o)

all: division echo ping_pong somme relais
	-rm $(OBJS)

echo: client_tcp_echo.c serveur_tcp_echo.c $(EXE_DIR) $(OBJS)
	mkdir -p $(EXE_DIR)/$@/TCP
	$(COMPILER) erreur.o tcp.o nombre.o client_tcp_$@.c -o $(EXE_DIR)/$@/TCP/client_tcp_$@
	$(COMPILER) erreur.o tcp.o nombre.o serveur_tcp_$@.c -o $(EXE_DIR)/$@/TCP/serveur_tcp_$@
	chmod -R u+x $(EXE_DIR)/$@/TCP

ping_pong: client_tcp_ping_pong.c serveur_tcp_ping_pong.c $(EXE_DIR) $(OBJS)
	mkdir -p $(EXE_DIR)/$@/TCP
	$(COMPILER) erreur.o tcp.o nombre.o client_tcp_$@.c -o $(EXE_DIR)/$@/TCP/client_tcp_$@
	$(COMPILER) erreur.o tcp.o nombre.o serveur_tcp_$@.c -o $(EXE_DIR)/$@/TCP/serveur_tcp_$@
	chmod -R u+x $(EXE_DIR)/$@/TCP

somme: client_tcp_somme.c serveur_tcp_somme.c $(EXE_DIR) $(OBJS)
	mkdir -p $(EXE_DIR)/$@/TCP
	$(COMPILER) erreur.o tcp.o nombre.o client_tcp_$@.c -o $(EXE_DIR)/$@/TCP/client_tcp_$@
	$(COMPILER) erreur.o tcp.o nombre.o serveur_tcp_$@.c -o $(EXE_DIR)/$@/TCP/serveur_tcp_$@
	chmod -R u+x $(EXE_DIR)/$@/TCP

division: client_tcp_division.c serveur_tcp_division.c $(EXE_DIR) $(OBJS)
	mkdir -p $(EXE_DIR)/$@/TCP
	$(COMPILER) erreur.o tcp.o nombre.o client_tcp_$@.c -o $(EXE_DIR)/$@/TCP/client_tcp_$@
	$(COMPILER) erreur.o tcp.o nombre.o serveur_tcp_$@.c -o $(EXE_DIR)/$@/TCP/serveur_tcp_$@
	chmod -R u+x $(EXE_DIR)/$@/TCP

relais: client_tcp_relais.c serveur_tcp_relais.c $(EXE_DIR) $(OBJS)
	mkdir -p $(EXE_DIR)/$@/TCP
	$(COMPILER) erreur.o tcp.o nombre.o client_tcp_$@.c -o $(EXE_DIR)/$@/TCP/client_tcp_$@
	$(COMPILER) erreur.o tcp.o nombre.o serveur_tcp_$@.c -o $(EXE_DIR)/$@/TCP/serveur_tcp_$@
	chmod -R u+x $(EXE_DIR)/$@/TCP

tcp.o: tcp.c tcp.h
	$(COMPILER) -c tcp.c -o tcp.o

erreur.o: erreur.c erreur.h
	$(COMPILER) -c erreur.c -o erreur.o

nombre.o: nombre.c nombre.h
	$(COMPILER) -c nombre.c -o nombre.o

$(EXE_DIR):
	mkdir -p $(EXE_DIR)


