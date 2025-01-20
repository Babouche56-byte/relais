#include "erreur.h"
#include "udp.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Créer une socket */
void creer_socket(char* adresseIP, int port, SOCK* sock) {
	
	/*A COMPLETER*/
	traiter_erreur(__FUNCTION__);
	/*A COMPLETER*/
}

/* Attacher une socket */
void attacher_socket(SOCK* sock) {
	/*A COMPLETER*/
	traiter_erreur(__FUNCTION__);
}

/*Initialiser la structure adresse client */
void init_addr(SOCK* sock) {
	/*A COMPLETER*/
}

/* Dimensionner la file d'attente d'une socket */
void dimensionner_file_attente_socket(int taille, SOCK* sock) {
	/*A COMPLETER*/
	traiter_erreur(__FUNCTION__);
}

/* Recevoir un message */
void recevoir_message(SOCK* dst, char * buffer) {
	/*A COMPLETER*/	
	traiter_erreur(__FUNCTION__);
}

/* Émettre un message */
void envoyer_message(SOCK* dst, char * message) {
	/*A COMPLETER*/
	traiter_erreur(__FUNCTION__);
}
/* Fermer la connexion */
void fermer_connexion(SOCK* sock) {
	/*A COMPLETER*/
	traiter_erreur(__FUNCTION__);
}
