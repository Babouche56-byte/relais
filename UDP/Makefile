COMPILER=gcc
EXE_DIR=/tmp/
FICHIERS=erreur udp nombre
OBJS:=$(FICHIERS:%=%.o)

all: division echo ping_pong somme relais
	-rm $(OBJS)

echo: client_udp_echo.c serveur_udp_echo.c $(EXE_DIR) $(OBJS)
	mkdir -p $(EXE_DIR)/$@/UDP
	$(COMPILER) erreur.o udp.o nombre.o client_udp_$@.c -o $(EXE_DIR)/$@/UDP/client_udp_$@
	$(COMPILER) erreur.o udp.o nombre.o serveur_udp_$@.c -o $(EXE_DIR)/$@/UDP/serveur_udp_$@
	chmod -R u+x $(EXE_DIR)/$@/UDP

ping_pong: client_udp_ping_pong.c serveur_udp_ping_pong.c $(EXE_DIR) $(OBJS)
	mkdir -p $(EXE_DIR)/$@/UDP
	$(COMPILER) erreur.o udp.o nombre.o client_udp_$@.c -o $(EXE_DIR)/$@/UDP/client_udp_$@
	$(COMPILER) erreur.o udp.o nombre.o serveur_udp_$@.c -o $(EXE_DIR)/$@/UDP/serveur_udp_$@
	chmod -R u+x $(EXE_DIR)/$@/UDP

somme: client_udp_somme.c serveur_udp_somme.c $(EXE_DIR) $(OBJS)
	mkdir -p $(EXE_DIR)/$@/UDP
	$(COMPILER) erreur.o udp.o nombre.o client_udp_$@.c -o $(EXE_DIR)/$@/UDP/client_udp_$@
	$(COMPILER) erreur.o udp.o nombre.o serveur_udp_$@.c -o $(EXE_DIR)/$@/UDP/serveur_udp_$@
	chmod -R u+x $(EXE_DIR)/$@/UDP

division: client_udp_division.c serveur_udp_division.c $(EXE_DIR) $(OBJS)
	mkdir -p $(EXE_DIR)/$@/UDP
	$(COMPILER) erreur.o udp.o nombre.o client_udp_$@.c -o $(EXE_DIR)/$@/UDP/client_udp_$@
	$(COMPILER) erreur.o udp.o nombre.o serveur_udp_$@.c -o $(EXE_DIR)/$@/UDP/serveur_udp_$@
	chmod -R u+x $(EXE_DIR)/$@/UDP

relais: client_udp_relais.c serveur_udp_relais.c $(EXE_DIR) $(OBJS)
	mkdir -p $(EXE_DIR)/$@/UDP
	$(COMPILER) erreur.o udp.o nombre.o client_udp_$@.c -o $(EXE_DIR)/$@/UDP/client_udp_$@
	$(COMPILER) erreur.o udp.o nombre.o serveur_udp_$@.c -o $(EXE_DIR)/$@/UDP/serveur_udp_$@
	chmod -R u+x $(EXE_DIR)/$@/UDP

udp.o: udp.c udp.h
	$(COMPILER) -c udp.c -o udp.o

erreur.o: erreur.c erreur.h
	$(COMPILER) -c erreur.c -o erreur.o

nombre.o: nombre.c nombre.h
	$(COMPILER) -c nombre.c -o nombre.o

$(EXE_DIR):
	mkdir -p $(EXE_DIR)
