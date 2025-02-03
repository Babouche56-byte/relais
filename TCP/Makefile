COMPILER=gcc
EXE_DIR=/tmp/
FICHIERS=erreur tcp nombre
OBJS:=$(FICHIERS:%=%.o)
CUNIT_FLAGS=-lcunit -I/usr/include/CUnit

all: relais testsuite
	-rm $(OBJS)

relais: client_tcp_relais.c serveur_tcp_relais.c $(EXE_DIR) $(OBJS)
	mkdir -p $(EXE_DIR)/$@/tcp
	$(COMPILER) erreur.o tcp.o nombre.o client_tcp_$@.c -o $(EXE_DIR)/$@/tcp/client_tcp_$@
	$(COMPILER) erreur.o tcp.o nombre.o serveur_tcp_$@.c -o $(EXE_DIR)/$@/tcp/serveur_tcp_$@
	chmod -R u+x $(EXE_DIR)/$@/tcp

testsuite: testsuite.c $(OBJS)
	$(COMPILER) $(OBJS) testsuite.c -o testsuite $(CUNIT_FLAGS)

tcp.o: tcp.c tcp.h
	$(COMPILER) -c tcp.c -o tcp.o

erreur.o: erreur.c erreur.h
	$(COMPILER) -c erreur.c -o erreur.o

nombre.o: nombre.c nombre.h
	$(COMPILER) -c nombre.c -o nombre.o

$(EXE_DIR):
	mkdir -p $(EXE_DIR)

clean:
	rm -f $(OBJS) testsuite
