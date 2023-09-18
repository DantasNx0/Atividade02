#include <stdio.h>
#include <string.h>

// Função de comparação para o quicksort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Função para trocar dois elementos em um vetor
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Função para calcular a mediana de um vetor ordenado
char* findMedian(char **arr, int size) {
    if (size % 2 == 0) {
        return arr[size / 2 - 1];
    } else {
        return arr[size / 2];
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi", "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int length = sizeof(arr) / sizeof(arr[0]);

    int swaps = 0;
    int comparisons = 0;

    // Ordenar o vetor usando o quicksort
    qsort(arr, length, sizeof(char *), compare);

    // Contar o número de trocas e comparações
    printf("Numero de trocas: %d\n", swaps);
    printf("Numero de comparacoes: %d\n", comparisons);

    // Mostrar o vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < length; i++) {
        printf("%s\n", arr[i]);
    }

    // Calcular e mostrar a mediana
    char *median = findMedian(arr, length);
    printf("Mediana: %s\n", median);

    // Gerar um arquivo de saída
    FILE *file = fopen("saida.txt", "w");
    if (file) {
        fprintf(file, "Numero de trocas: %d\n", swaps);
        fprintf(file, "Numero de comparacoes: %d\n", comparisons);
        fprintf(file, "Vetor ordenado:\n");
        for (int i = 0; i < length; i++) {
            fprintf(file, "%s\n", arr[i]);
        }
        fprintf(file, "Mediana: %s\n", median);
        fclose(file);
    } else {
        printf("Erro ao criar o arquivo de saida.\n");
    }

    return 0;
}
