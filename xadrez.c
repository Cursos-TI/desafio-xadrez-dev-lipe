#include <stdio.h>

// Função recursiva para mover a Torre para a Direita
void moverTorre(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Função recursiva para mover o Bispo na diagonal (Cima, Direita)
void moverBispoRecursivo(int casas) {
    if (casas <= 0) return;
    printf("Cima, Direita\n");
    moverBispoRecursivo(casas - 1);
}

// Movimento do Bispo com loops aninhados simulando movimento diagonal
void moverBispoLoops(int casas) {
    printf("Movimento do Bispo (loops aninhados):\n");
    for (int vertical = 1; vertical <= casas; vertical++) {
        for (int horizontal = 1; horizontal <= casas; horizontal++) {
            if (horizontal == vertical) {
                printf("Cima, Direita\n");
            }
        }
    }
}

// Função recursiva para mover a Rainha para a Esquerda
void moverRainha(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Movimento do Cavalo com loops aninhados, múltiplas variáveis e uso de continue/break
// Movimento válido: 2 para cima e 1 para direita (em "L")
void moverCavalo(int movimentosDesejados) {
    int movimentosFeitos = 0;

    printf("Movimento do Cavalo:\n");

    for (int cima = 1; cima <= 3; cima++) {
        for (int direita = 1; direita <= 3; direita++) {

            // Verifica se a combinação forma um movimento em "L"
            if (!((cima == 2 && direita == 1) || (cima == 1 && direita == 2))) {
                continue; // ignora combinações inválidas
            }

            // Imprime o movimento válido
            for (int i = 0; i < cima; i++) {
                printf("Cima\n");
            }
            for (int j = 0; j < direita; j++) {
                printf("Direita\n");
            }

            printf("\n"); 

            movimentosFeitos++;

            // Interrompe o loop se atingir a quantidade desejada
            if (movimentosFeitos >= movimentosDesejados) break;
        }

        if (movimentosFeitos >= movimentosDesejados) break;
    }
}

int main() {
    // Definindo número de casas/movimentos para cada peça
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;
    int movimentosCavalo = 1;

    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);

    printf("\nMovimento do Bispo (recursivo):\n");
    moverBispoRecursivo(casasBispo);

    printf("\n");
    moverBispoLoops(casasBispo);

    printf("\nMovimento da Rainha:\n");
    moverRainha(casasRainha);

    printf("\n");
    moverCavalo(movimentosCavalo);

    return 0;
}