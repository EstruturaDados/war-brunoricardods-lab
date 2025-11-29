#include <stdio.h>
#include <stdlib.h> // Para a função system() (opcional, para limpar o console)
#include <string.h> // Para a função strlen() e strcspn()

// Define um tamanho máximo para o nome do território e a cor
#define TAMANHO_NOME 50
#define NUM_TERRITORIOS 5

// --- 1. Definição da Estrutura (struct) ---
// Define a estrutura para representar um único Território.
// A struct agrupa dados relacionados sob um único nome.
typedef struct {
    char nome[TAMANHO_NOME];       // Nome do território (string)
    char cor_exercito[TAMANHO_NOME]; // Cor do exército dominante (string)
    int numero_tropas;             // Número de tropas presentes (inteiro)
} Territorio;

// --- Função Principal ---
int main() {
    // --- 2. Criação do Vetor Estático ---
    // Declara um vetor estático que pode armazenar 5 estruturas 'Territorio'.
    Territorio mapa[NUM_TERRITORIOS];
    int i; // Variável de controle para os loops

    printf("## 🌍 Cadastro Inicial dos Territórios (%d no total) ##\n\n", NUM_TERRITORIOS);

    // --- 3. Entrada de Dados (Leitura de dados pelo terminal) ---
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("--- Território %d ---\n", i + 1);

        // --- Leitura do Nome do Território (usando fgets) ---
        // fgets é preferível para strings pois evita problemas com espaços e
        // controla o tamanho da entrada para prevenir Buffer Overflow.
        printf("Nome do Território: ");
        // Leitura da linha inteira. O NUM_TERRITORIOS - 1 é para deixar espaço para o '\0'
        if (fgets(mapa[i].nome, TAMANHO_NOME, stdin) == NULL) {
             printf("Erro na leitura.\n");
             return 1;
        }

        // Remove o caractere de nova linha ('\n') adicionado por fgets,
        // substituindo-o por um terminador de string ('\0').
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';


        // --- Leitura da Cor do Exército (usando fgets) ---
        printf("Cor do Exército Dominante: ");
        if (fgets(mapa[i].cor_exercito, TAMANHO_NOME, stdin) == NULL) {
            printf("Erro na leitura.\n");
            return 1;
        }
        // Remove o '\n' da cor também
        mapa[i].cor_exercito[strcspn(mapa[i].cor_exercito, "\n")] = '\0';

        // --- Leitura do Número de Tropas (usando scanf) ---
        // scanf é apropriado para ler tipos numéricos simples.
        printf("Número de Tropas: ");
        // %d para ler um inteiro. O & é essencial para passar o endereço da variável.
        if (scanf("%d", &mapa[i].numero_tropas) != 1) {
            printf("Entrada inválida. Esperado um número inteiro.\n");
            return 1;
        }

        // Limpar o buffer de entrada (stdin)
        // Isso é crucial após o uso de scanf antes de voltar a usar fgets,
        // para descartar o '\n' que sobrou no buffer.
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("\n");
    }

    // Opcional: Limpar o console para uma saída mais organizada
    // Nota: 'cls' no Windows, 'clear' no Linux/macOS
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif


    // --- 4. Saída de Dados (Impressão Organizada) ---
    printf("==========================================\n");
    printf("           ESTADO ATUAL DO MAPA  \n");
    printf("==========================================\n");

    // Imprime um cabeçalho para a tabela de dados
    printf("| %-20s | %-15s | %-8s |\n", "TERRITÓRIO", "EXÉRCITO", "TROPAS");
    printf("|----------------------|-----------------|----------|\n");

    // Loop para iterar sobre todos os 5 territórios e imprimir seus dados.
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        // %-20s: Imprime uma string, justificada à esquerda em um campo de 20 caracteres.
        // %-15s: String justificada à esquerda em 15 caracteres.
        // %-8d: Inteiro justificado à esquerda em 8 caracteres.
        printf("| %-20s | %-15s | %-8d |\n",
               mapa[i].nome,
               mapa[i].cor_exercito,
               mapa[i].numero_tropas);
    }
    printf("==========================================\n");

    return 0; // Indica que o programa terminou com sucesso
}