#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "erreur.h"

/* Afficher une éventuelle erreur et quitter */
void traiter_erreur(const char * msg) {
	if (errno) {
		perror(msg);
		exit(1);
	}
}

/* Verifier le ligne de commande */
void traiter_commande(int erreur, const char * cmd, const char * arg_desc) {
	if (erreur) {
  		fprintf(stderr, "Ligne de commande invalide\n");
  		fprintf(stderr, "Usage : %s %s\n", cmd, arg_desc);
		exit(1);
	}
}

/* Traiter le mode verbose */
int verbose_mode() {
	return (getenv("VERBOSE") != NULL && \
		strcmp(getenv("VERBOSE"), "1") == 0);
}
