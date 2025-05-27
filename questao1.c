#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 26

typedef struct {
    char nome[50];
    int num_veiculos;
    int num_acidentes;
} Estado;

void coletar_dados(Estado estados[NUM_ESTADOS]) {
    for (int i = 0; i < NUM_ESTADOS; i++) {
        printf("Digite o nome do %dº estado: ", i + 1);
        getchar();  
        fgets(estados[i].nome, sizeof(estados[i].nome), stdin);
        estados[i].nome[strcspn(estados[i].nome, "\n")] = 0;  

        printf("Digite o numero de veiculos em %s (2007): ", estados[i].nome);
        scanf("%d", &estados[i].num_veiculos);

        printf("Digite o numero de acidentes em %s (2007): ", estados[i].nome);
        scanf("%d", &estados[i].num_acidentes);
    }
}

void maior_menor_acidentes(Estado estados[NUM_ESTADOS], int *indice_maior, int *indice_menor) {
    int maior = estados[0].num_acidentes, menor = estados[0].num_acidentes;

    *indice_maior = 0;
    *indice_menor = 0;

    for (int i = 1; i < NUM_ESTADOS; i++) {
        if (estados[i].num_acidentes > maior) {
            maior = estados[i].num_acidentes;
            *indice_maior = i;
        }
        if (estados[i].num_acidentes < menor) {
            menor = estados[i].num_acidentes;
            *indice_menor = i;
        }
    }
}

float percentual_acidentes(Estado estados[NUM_ESTADOS], int estado_index) {
    return (float)estados[estado_index].num_acidentes / estados[estado_index].num_veiculos * 100;
}

float media_acidentes(Estado estados[NUM_ESTADOS]) {
    int total_acidentes = 0;
    for (int i = 0; i < NUM_ESTADOS; i++) {
        total_acidentes += estados[i].num_acidentes;
    }
    return (float)total_acidentes / NUM_ESTADOS;
}

void estados_acima_da_media(Estado estados[NUM_ESTADOS], float media) {
    printf("Estados com acidentes acima da media:\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        if (estados[i].num_acidentes > media) {
            printf("%s: %d acidentes\n", estados[i].nome, estados[i].num_acidentes);
        }
    }
}

int main() {
    Estado estados[NUM_ESTADOS];
    int indice_maior, indice_menor;
    float media;

    coletar_dados(estados);
    maior_menor_acidentes(estados, &indice_maior, &indice_menor);

    printf("\nEstado com maior número de acidentes: %s - %d acidentes\n", estados[indice_maior].nome, estados[indice_maior].num_acidentes);
    printf("Estado com menor número de acidentes: %s - %d acidentes\n", estados[indice_menor].nome, estados[indice_menor].num_acidentes);

    printf("\nPercentual de veículos envolvidos em acidentes em cada estado:\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        printf("%s: %.2f%%\n", estados[i].nome, percentual_acidentes(estados, i));
    }

    media = media_acidentes(estados);
    printf("\nMédia de acidentes no país: %.2f\n", media);

    estados_acima_da_media(estados, media);

    return 0;
}
