#ifndef _NOMBRE_H
#define _NOMBRE_H
int est_un_entier(const char * buffer);
int est_un_entier_positif(const char * buffer);
int est_un_nombre(const char * buffer);
long double convertir_nombre(const char * buffer);
int est_un_port_non_reserve(const char * buffer);
int est_une_adresse_IP(const char * buffer);
#endif // _NOMBRE_H
