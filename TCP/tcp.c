#include "erreur.h"
#include "tcp.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TAILLE_BUFFER 1024

/* Créer une socket */
int creer_socket(char* adresseIP, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        traiter_erreur("Erreur lors de la création de la socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, adresseIP, &server_addr.sin_addr) <= 0) {
        traiter_erreur("Adresse IP invalide");
    }

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        traiter_erreur("Erreur lors de la connexion de la socket");
    }

    return sock;
}

/* Attacher une socket */
void attacher_socket(int sock, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        traiter_erreur("Erreur lors de l'attachement de la socket");
    }
}

/* Dimensionner la file d'attente d'une socket */
void dimensionner_file_attente_socket(int sock, int taille) {
    if (listen(sock, taille) < 0) {
        traiter_erreur("Erreur lors du dimensionnement de la file d'attente");
    }
}

/* Initialiser la structure adresse client */
void init_addr_client(struct sockaddr_in* client_addr) {
    memset(client_addr, 0, sizeof(struct sockaddr_in));
    client_addr->sin_family = AF_INET;
}

/* Attendre une connexion */
int attendre_connexion(int sock) {
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int socktraitement = accept(sock, (struct sockaddr*)&client_addr, &addr_len);
    if (socktraitement < 0) {
        traiter_erreur("Erreur lors de l'attente de connexion");
    }
    return socktraitement;
}

/* Recevoir un message */
void recevoir_message(int socktraitement, char * buffer) {
    int recv_len = recv(socktraitement, buffer, TAILLE_BUFFER, 0);
    if (recv_len < 0) {
        traiter_erreur("Erreur lors de la réception du message");
    }
    buffer[recv_len] = '\0';
}

/* Émettre un message */
void envoyer_message(int socktraitement, char * message) {
    if (send(socktraitement, message, strlen(message), 0) < 0) {
        traiter_erreur("Erreur lors de l'envoi du message");
    }
}

/* Fermer la connexion */
void fermer_connexion(int socktraitement) {
    if (close(socktraitement) < 0) {
        traiter_erreur("Erreur lors de la fermeture de la connexion");
    }
}
