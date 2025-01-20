#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "erreur.h"

#ifndef _UDP_H
#define _UDP_H
#define TAILLE_MSG 256

typedef struct {
	int sockfd;
     	struct sockaddr_in adresse;
     	socklen_t longueur_adresse;
} SOCK;

void creer_socket(char*, int, SOCK*);
void attacher_socket(SOCK*);
void dimensionner_file_attente_socket(int, SOCK*);
void init_addr(SOCK*);
int attendre_connexion(SOCK*, SOCK*);
void recevoir_message(SOCK*, char *);
void envoyer_message(SOCK*, char *);
void fermer_connexion(SOCK*);
#endif // _UDP_H_
