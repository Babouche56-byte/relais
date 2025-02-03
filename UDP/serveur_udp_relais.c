#include "udp.h"
#include "erreur.h"
#include "nombre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 2

int main(int argc, char** argv) {
    traiter_commande(argc != 2, argv[0], "<port>\nmauvais nombre d'arguments");
    
    int port = atoi(argv[1]);
    traiter_commande(port < 1024 || port > 65535, argv[0], "<port>\n<port> est un port non réservé");
    
    SOCK socket_serveur;
    creer_socket(NULL, port, &socket_serveur);
    attacher_socket(&socket_serveur);
    
    printf("Serveur démarré sur le port %d\n", port);
    
    struct sockaddr_in clients[MAX_CLIENTS];
    char messages[MAX_CLIENTS][TAILLE_BUFFER];
    int client_count = 0;
    
    while (client_count < MAX_CLIENTS) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int recv_len = recvfrom(socket_serveur.sockfd, messages[client_count], TAILLE_BUFFER, 0, (struct sockaddr*)&client_addr, &addr_len);
        messages[client_count][recv_len] = '\0';
        
        printf("Message reçu de %s:%d : %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), messages[client_count]);
        
        clients[client_count++] = client_addr;
    }
    
    // Envoyer les messages reçus à l'autre client
    sendto(socket_serveur.sockfd, messages[1], strlen(messages[1]), 0, (struct sockaddr*)&clients[0], sizeof(clients[0]));
    sendto(socket_serveur.sockfd, messages[0], strlen(messages[0]), 0, (struct sockaddr*)&clients[1], sizeof(clients[1]));
    
    printf("Messages relayés entre les clients.\n");
    
    fermer_connexion(&socket_serveur);
    return 0;
}
