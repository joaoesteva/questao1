#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 26

typedef struct {
    char nome[50];
    int num_veiculos;
    int num_acidentes;
} Estado;

void coletarDados(Estado estados[NUM_ESTADOS]);
void exibirEstatisticas(Estado estados[NUM_ESTADOS]);

int main() {
    Estado estados[NUM_ESTADOS];

    coletarDados(estados);
    exibirEstatisticas(estados);

    return 0;
}

void coletarDados(Estado estados[NUM_ESTADOS]) {
    for (int i = 0; i < NUM_ESTADOS; i++) {
        printf("Informe o nome do estado %d: ", i + 1);
        fgets(estados[i].nome, sizeof(estados[i].nome), stdin);
        estados[i].nome[strcspn(estados[i].nome, "\n")] = '\0'; 

        printf("Informe o numero de veiculos no estado %s: ", estados[i].nome);
        scanf("%d", &estados[i].num_veiculos);

        printf("Informe o numero de acidentes de transito no estado %s: ", estados[i].nome);
        scanf("%d", &estados[i].num_acidentes);

        getchar();
    }
}

void exibirEstatisticas(Estado estados[NUM_ESTADOS]) {
    int indiceMaior = 0, indiceMenor = 0;
    int somaAcidentes = 0;
    float mediaAcidentes;

    for (int i = 1; i < NUM_ESTADOS; i++) {
        if (estados[i].num_acidentes > estados[indiceMaior].num_acidentes) {
            indiceMaior = i;
        }
        if (estados[i].num_acidentes < estados[indiceMenor].num_acidentes) {
            indiceMenor = i;
        }
        somaAcidentes += estados[i].num_acidentes;
    }

    somaAcidentes += estados[0].num_acidentes;

    mediaAcidentes = (float)somaAcidentes / NUM_ESTADOS;

    printf("\nMaior numero de acidentes: %d no estado %s\n", estados[indiceMaior].num_acidentes, estados[indiceMaior].nome);
    printf("Menor numero de acidentes: %d no estado %s\n", estados[indiceMenor].num_acidentes, estados[indiceMenor].nome);
    printf("\nMedia de acidentes no país: %.2f\n", mediaAcidentes);

    printf("\nEstados acima da média de acidentes:\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        if (estados[i].num_acidentes > mediaAcidentes) {
            printf("%s\n", estados[i].nome);
        }
    }

    for (int i = 0; i < NUM_ESTADOS; i++) {
        float percentual = (float)estados[i].num_acidentes / estados[i].num_veiculos * 100;
        printf("\nPercentual de veículos envolvidos em acidentes no estado %s: %.2f%%\n", estados[i].nome, percentual);
    }
}
