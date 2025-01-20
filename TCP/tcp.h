#include <sys/socket.h>
#include "erreur.h"

#ifndef _TCP_H
#define _TCP_H
#define TAILLE_MSG 256

int creer_socket(char*, int);
void connecter_socket(int);
void attacher_socket();
void dimensionner_file_attente_socket(int);
void init_addr_client();
int attendre_connexion();
void recevoir_message(int, char *);
void envoyer_message(int, char *);
void fermer_connexion(int);
#endif // _TCP_H_
