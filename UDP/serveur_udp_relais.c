#include "udp.h"
#include "erreur.h"
#include "nombre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
    // Vérifier le nombre d'arguments
    traiter_commande(argc != 2, argv[0], "<port>\nmauvais nombre d'arguments");
    
    // Convertir le port en nombre et vérifier s'il est valide (non réservé)
    int port = atoi(argv[1]);
    traiter_commande(port < 1024 || port > 65535, argv[0], "<port>\n<port> est un port non réservé");
    
    // Créer la socket serveur
    SOCK socket_serveur;
    creer_socket(NULL, port, &socket_serveur);
    
    // Attacher la socket
    attacher_socket(&socket_serveur);
    
    printf("Serveur démarré sur le port %d\n", port);
    
    // Buffer pour recevoir les messages
    char buffer[TAILLE_BUFFER];
    
    // Boucle principale du serveur
    while(1) {
        // Initialiser l'adresse client pour chaque nouvelle connexion
        init_addr(&socket_serveur);
        
        // Recevoir le message
        recevoir_message(&socket_serveur, buffer);
        
        // Afficher le message reçu
        printf("Message reçu : %s\n", buffer);
        
        // Préparer et envoyer la réponse
        char reponse[TAILLE_BUFFER];
        snprintf(reponse, TAILLE_BUFFER, "Message reçu: %s", buffer);
        envoyer_message(&socket_serveur, reponse);
    }
    
    // Fermer la socket (ce code ne sera jamais atteint dans cette version)
    fermer_connexion(&socket_serveur);
    exit(0);
}
