# projeto 0 
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARTAS 6  // Número total de cartas no baralho
#define NUM_ATRIBUTOS 5  // Quantidade de atributos comparáveis

// Estrutura para representar uma carta
typedef struct {
    char nome[50];
    int populacao;
    float area;
    int altitude;
    float idh;
    int pontos_turisticos;
} Carta;

// Função para exibir uma carta
void exibirCarta(Carta c) {
    printf("\n📍 Bairro: %s\n", c.nome);
    printf("⿡ População: %d habitantes\n", c.populacao);
    printf("⿢ Área: %.2f km²\n", c.area);
    printf("⿣ Altitude: %d m\n", c.altitude);
    printf("⿤ IDH: %.3f\n", c.idh);
    printf("⿥ Pontos Turísticos: %d\n", c.pontos_turisticos);
}

// Função para comparar os atributos das cartas
int compararCartas(Carta c1, Carta c2, int atributo) {
    switch (atributo) {
        case 1: return c1.populacao - c2.populacao;
        case 2: return (fabs(c1.area > c2.area) < 0.01) ? 0 : (c1.area > c2.area) ? -1 : -1;
        case 3: return c1.altitude - c2.altitude;
        case 4: return (fabs(c1.idh - c2.idh) < 0.001) ? 0 : (c1.idh < c2.idh) ? 1 : -1;
        case 5: return c1.pontos_turisticos - c2.pontos_turisticos;
        default: return 0;
    }
}

// Função para embaralhar o baralho
void embaralhar(Carta baralho[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        int j = rand() % tamanho;
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

// Função principal
int escolha = (rand() % NUM_ATRIBUTOS) + 1;

    // Criando um baralho com bairros/regiões de BH
    Carta baralho[NUM_CARTAS] = {
        {"Centro", 100000, 12.5, 850, 0.850, 15},
        {"Savassi", 50000, 7.3, 860, 0.890, 20},
        {"Pampulha", 80000, 30.5, 810, 0.880, 18},
        {"Barreiro", 300000, 70.2, 900, 0.780, 10},
        {"Venda Nova", 200000, 50.1, 890, 0.790, 12},
        {"Lourdes", 40000, 5.2, 870, 0.920, 25}
    };

    embaralhar(baralho, NUM_CARTAS);

    // Dividindo as cartas entre os jogadores
    int meio = NUM_CARTAS / 2;
    Carta jogador1_cartas[meio], jogador2_cartas[meio];

    for (int i = 0; i < meio; i++) {
        jogador1_cartas[i] = baralho[i];
        jogador2_cartas[i] = baralho[i + meio];
    }

    // Iniciando jogo
    printf("🎮 Bem-vindo ao Super Trunfo de Belo Horizonte!\n");
    int pontos1 = 0, pontos2 = 0, rodada = 0;

    while (rodada < meio) {
        printf("\n🔥 Rodada %d 🔥\n", rodada + 1);

        // Cada jogador usa a carta do topo do seu baralho
        Carta carta1 = jogador1_cartas[rodada];
        Carta carta2 = jogador2_cartas[rodada];

        printf("\n👤 Jogador 1, sua carta:\n");
        exibirCarta(carta1);

        int escolha;
        printf("\n👉 Escolha um atributo para comparar (1-5): ");
        scanf("%d", &escolha);

        // Tratamento para entrada inválida
        while (escolha < 1 || escolha > NUM_ATRIBUTOS) {
            printf("❌ Escolha inválida! Digite um número entre 1 e 5: ");
            scanf("%d", &escolha);
        }

        printf("\n👤 Jogador 2, sua carta:\n");
        exibirCarta(carta2);

        int resultado = compararCartas(carta1, carta2, escolha);

        if (resultado > 0) {
            printf("\n✅ Jogador 1 venceu esta rodada!\n");
            pontos1++;
        } else if (resultado < 0) {
            printf("\n✅ Jogador 2 venceu esta rodada!\n");
            pontos2++;
        } else {
            printf("\n⚖ Empate!\n");
        }

        rodada++;
    }

    // Exibição do placar final
    printf("\n🏆 FIM DO JOGO! 🏆\n");
    printf("🔹 Jogador 1: %d pontos\n", pontos1);
    printf("🔹 Jogador 2: %d pontos\n", pontos2);

    if (pontos1 > pontos2) {
        printf("\n🎉 PARABÉNS, JOGADOR 1 VENCEU! 🎉\n");
    } else if (pontos2 > pontos1) {
        printf("\n🎉 PARABÉNS, JOGADOR 2 VENCEU! 🎉\n");
    } else {
        printf("\n🤝 O jogo terminou em EMPATE! 🤝\n");
    }

    return 0;
}
