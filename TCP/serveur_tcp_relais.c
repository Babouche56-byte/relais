#include "tcp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <time.h>

// Fonction pour vérifier si une chaîne est une adresse IP valide
int est_ip_valide(const char* ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) == 1;
}

int main(int argc, char** argv) {
    // Vérifier le nombre d'arguments
    traiter_commande(argc != 2, argv[0], "<port>\nmauvais nombre d'arguments");
    
    // Vérifier que le port est valide (non réservé et dans la plage correcte)
    int port = atoi(argv[1]);
    traiter_commande(port < 1024 || port > 65535, argv[0], "<port>\n<port> est un port non réservé");

    // Créer la socket serveur
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        traiter_erreur("Erreur lors de la création de la socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        traiter_erreur("Erreur lors de l'attachement de la socket");
    }

    if (listen(sock, 5) < 0) {
        traiter_erreur("Erreur lors du dimensionnement de la file d'attente");
    }

    printf("Serveur démarré sur le port %d\n", port);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int socktraitement = accept(sock, (struct sockaddr*)&client_addr, &addr_len);
        if (socktraitement < 0) {
            traiter_erreur("Erreur lors de l'attente de connexion");
        }

        char buffer[TAILLE_BUFFER];
        int recv_len = recv(socktraitement, buffer, TAILLE_BUFFER, 0);
        if (recv_len < 0) {
            traiter_erreur("Erreur lors de la réception du message");
        }
        buffer[recv_len] = '\0';

        printf("Message reçu : %s\n", buffer);

        // Préparer et envoyer la réponse
        char reponse[TAILLE_BUFFER];
        snprintf(reponse, TAILLE_BUFFER, "Message reçu: %s", buffer);
        if (send(socktraitement, reponse, strlen(reponse), 0) < 0) {
            traiter_erreur("Erreur lors de l'envoi du message");
        }

        fermer_connexion(socktraitement);
    }

    fermer_connexion(sock);
    return 0;
}
