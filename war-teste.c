#include <stdio.h> 
#define NUM_PAISES 5
#define TAMANHO_NOME 30

int main() {
    
    char paises[NUM_PAISES][TAMANHO_NOME] = {
        "Brasil",
        "Canada",
        "Japao",
        "Alemanha",
        "Australia"
    };

    int i; 

    printf("==================================\n");
    printf(" Lista de %d Países Cadastrados \n", NUM_PAISES);
    printf("==================================\n");
    
    for (i = 0; i < NUM_PAISES; i++) {
        
        printf("%d. %s\n", i + 1, paises[i]);
    }

    printf("==================================\n");
    
    return 0; 
}