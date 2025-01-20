#include "nombre.h"
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

/* Vérifier si la chaîne de caractères représente un entier */
int est_un_entier(const char * buffer) {
	char *endptr;
	strtol(buffer, &endptr, 10);
	return (*endptr == 0);
}

/* Vérifier si la chaîne de caractères représente un entier positif */
int est_un_entier_positif(const char * buffer) {
	char *endptr;
	int valeur = strtol(buffer, &endptr, 10);
	return (*endptr == 0 && valeur >= 0);
}

/* Vérifier si la chaîne de caractères représente un nombre */
int est_un_nombre(const char * buffer) {
	char *endptr;
	strtol(buffer, &endptr, 10);
	if (*endptr == '.' && *(endptr + 1) != 0) {
	       	strtol(endptr + 1, &endptr, 10);       	
	}
	return (*endptr == 0);
}

/* Retourner un nombre à partir de la chaîne de caractères */
long double convertir_nombre(const char * buffer) {
	char *endptr;
	return strtold(buffer, &endptr);
}

/* Vérifier si la chaîne de caractères représente un numéro de port non réservé */
int est_un_port_non_reserve(const char * buffer) {
	return est_un_entier_positif(buffer) && convertir_nombre(buffer) > 1023 && convertir_nombre(buffer) < 65536;
}

int est_une_adresse_IP(const char * buffer) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, buffer, &(sa.sin_addr));
    return result != 0;
}
