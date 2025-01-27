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
    // Créer une socket UDP
    sock->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock->sockfd < 0) {
        traiter_erreur(__FUNCTION__);
    }
    
    // Initialiser la structure d'adresse
    memset(&sock->addr, 0, sizeof(sock->addr));
    sock->addr.sin_family = AF_INET;
    sock->addr.sin_port = htons(port);
    sock->addrlen = sizeof(struct sockaddr_in);
    
    // Si adresseIP est NULL, on utilise INADDR_ANY
    if (adresseIP == NULL) {
        sock->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    } else {
        sock->addr.sin_addr.s_addr = inet_addr(adresseIP);
    }
}

/* Attacher une socket */
void attacher_socket(SOCK* sock) {
    int result = bind(sock->sockfd, (struct sockaddr*)&sock->addr, sock->addrlen);
    if (result < 0) {
        traiter_erreur(__FUNCTION__);
    }
}

/* Initialiser la structure adresse client */
void init_addr(SOCK* sock) {
    memset(&sock->addr, 0, sizeof(sock->addr));
    sock->addr.sin_family = AF_INET;
    sock->addrlen = sizeof(struct sockaddr_in);
}

/* Dimensionner la file d'attente d'une socket */
void dimensionner_file_attente_socket(int taille, SOCK* sock) {
    // Cette fonction n'est pas nécessaire pour UDP car il n'y a pas de file d'attente
    (void)taille; // Pour éviter l'avertissement de variable non utilisée
    (void)sock;   // Pour éviter l'avertissement de variable non utilisée
}

/* Recevoir un message */
void recevoir_message(SOCK* dst, char* buffer) {
    ssize_t nbytes = recvfrom(dst->sockfd, buffer, TAILLE_BUFFER - 1, 0,
                             (struct sockaddr*)&dst->addr, &dst->addrlen);
    if (nbytes < 0) {
        traiter_erreur(__FUNCTION__);
    }
    buffer[nbytes] = '\0'; // Assurer que le message est terminé par un caractère nul
}

/* Émettre un message */
void envoyer_message(SOCK* dst, char* message) {
    ssize_t nbytes = sendto(dst->sockfd, message, strlen(message), 0,
                           (struct sockaddr*)&dst->addr, dst->addrlen);
    if (nbytes < 0) {
        traiter_erreur(__FUNCTION__);
    }
}

/* Fermer la connexion */
void fermer_connexion(SOCK* sock) {
    if (close(sock->sockfd) < 0) {
        traiter_erreur(__FUNCTION__);
    }
}
