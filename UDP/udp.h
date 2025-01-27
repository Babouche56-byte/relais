#ifndef UDP_H
#define UDP_H

#include <netinet/in.h>

#define TAILLE_BUFFER 1024

typedef struct {
    int sockfd;                     // Descripteur de la socket
    struct sockaddr_in addr;        // Structure d'adresse
    socklen_t addrlen;             // Longueur de l'adresse
} SOCK;

// Prototypes des fonctions
void creer_socket(char* adresseIP, int port, SOCK* sock);
void attacher_socket(SOCK* sock);
void init_addr(SOCK* sock);
void dimensionner_file_attente_socket(int taille, SOCK* sock);
void recevoir_message(SOCK* dst, char* buffer);
void envoyer_message(SOCK* dst, char* message);
void fermer_connexion(SOCK* sock);

#endif
