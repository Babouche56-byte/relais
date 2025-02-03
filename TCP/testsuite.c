#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "tcp.h"
#include "erreur.h"
#include "nombre.h"
#include <stdio.h>
#include "test.c"

/** Montage de la fixation - appelé avant chaque cas de test. **/
int init_suite(void) { return 0; }

/* Démontage de la fixation - appelé après chaque cas de test. */
int clean_suite(void) { return 0; }

/****** Cas de test - validation de l'adresse IP *****/
void test_validation_ip(void) {
    CU_ASSERT_TRUE(is_valid_ip("192.168.1.1"));
    CU_ASSERT_FALSE(is_valid_ip("192.168.11"));
}

/**** Cas de test - validation du port *****/ 
void test_validation_port(void) {
    CU_ASSERT_TRUE(is_valid_port(8080));
    CU_ASSERT_FALSE(is_valid_port(10));
}

/******************* Lancement des tests ***********************/
int main ( void )
{
   CU_pSuite pSuite = NULL;
   unsigned int status = 0;

   /* initialisation des test CUnit */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* ajout de la suite de test */
   pSuite = CU_add_suite( "Test module serveur", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* ajout des cas de test dans la suite de test */
   if ( (NULL == CU_add_test(pSuite, "Cas de test - validation de l'adresse IP", test_validation_ip)) ||
        (NULL == CU_add_test(pSuite, "Cas de test - validation du port", test_validation_port))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* lancement de tous les tests avec l'interface de base */
   CU_basic_set_mode(CU_BRM_NORMAL);
   if ( CUE_SUCCESS != CU_basic_run_tests() )
      return CU_get_error();
   
   status = CU_get_number_of_tests_failed();
   CU_basic_show_failures(CU_get_failure_list());
  
   /* cloture des tests */
   CU_cleanup_registry();
   return status;
}
