#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

int traiter_commande_wrapper(int argc, char** argv) {
	traiter_commande(argc, argv[0], "<adresse IP> <port> <message>\nmauvais nombre d'aguments");	
	traiter_commande(argc, argv[0], "<adresse IP> <port> <message>\n<adresse IP> est une adresse IP au format décimal pointé");
	traiter_commande(argc, argv[0], "<adresse IP> <port> <message>\n<port> est un port non réservé");
	
}

int main(int argc, char** argv) {
	
	traiter_commande_wrapper(argc, argv);

}
