#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_VERTICAL 3
#define TAMANHO_HORIZONTAL 4
#define TAMANHO_DIAGONAL 3

struct Coordenada {
    int x;
    int y;
};

// Função para inicializar o tabuleiro
void START(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void EXIBIR(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se o navio pode ser posicionado
int posicaoValida(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        int novoX = x + (direcao == 'H' ? i : 0);
        int novoY = y + (direcao == 'V' ? i : 0);

        // Verifica se a posição está fora do tabuleiro ou já ocupada
        if (novoX < 0 || novoX >= TAMANHO_TABULEIRO || novoY < 0 || novoY >= TAMANHO_TABULEIRO || tabuleiro[novoY][novoX] != 0) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        int novoX = x + (direcao == 'H' ? i : 0);
        int novoY = y + (direcao == 'V' ? i : 0);
        tabuleiro[novoY][novoX] = 3;
    }
}

// Função para verificar se o navio diagonal pode ser posicionado
int posicaoValidaDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int tamanho, int direcao) {
    for (int i = 0; i < tamanho; i++) {
        int novoX = x + (direcao == 1 ? i : -i);
        int novoY = y + i;

        // Verifica se o navio diagonal está fora do tabuleiro ou a posição já está ocupada
        if (novoX < 0 || novoX >= TAMANHO_TABULEIRO || novoY < 0 || novoY >= TAMANHO_TABULEIRO || tabuleiro[novoY][novoX] != 0) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio diagonal
void posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int tamanho, int direcao) {
    for (int i = 0; i < tamanho; i++) {
        int novoX = x + (direcao == 1 ? i : -i);
        int novoY = y + i;
        tabuleiro[novoY][novoX] = 3;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    START(tabuleiro);

    int x_inicial, y_inicial, valido;

    // Navio vertical
    valido = 0;
    while (!valido) {
        printf("Digite a posição inicial do navio vertical (coluna linha): ");
        scanf("%d %d", &x_inicial, &y_inicial);
        x_inicial -= 1;  // Ajuste para índice de 0 a 9
        y_inicial -= 1;  // Ajuste para índice de 0 a 9

        if (posicaoValida(tabuleiro, x_inicial, y_inicial, TAMANHO_VERTICAL, 'V')) {
            posicionarNavio(tabuleiro, x_inicial, y_inicial, TAMANHO_VERTICAL, 'V');
            valido = 1;
        } else {
            printf("Posição inválida ou ocupada.\n");
        }
    }

    // Navio horizontal
    valido = 0;
    while (!valido) {
        printf("Digite a posição inicial do navio horizontal (coluna linha): ");
        scanf("%d %d", &x_inicial, &y_inicial);
        x_inicial -= 1;  // Ajuste para índice de 0 a 9
        y_inicial -= 1;  // Ajuste para índice de 0 a 9

        if (posicaoValida(tabuleiro, x_inicial, y_inicial, TAMANHO_HORIZONTAL, 'H')) {
            posicionarNavio(tabuleiro, x_inicial, y_inicial, TAMANHO_HORIZONTAL, 'H');
            valido = 1;
        } else {
            printf("Posição inválida ou ocupada.\n");
        }
    }

    // Navio diagonal 1
    valido = 0;
    while (!valido) {
        printf("Digite a posição inicial do navio diagonal 1 (coluna linha): ");
        scanf("%d %d", &x_inicial, &y_inicial);
        x_inicial -= 1;  // Ajuste para índice de 0 a 9
        y_inicial -= 1;  // Ajuste para índice de 0 a 9

        if (posicaoValidaDiagonal(tabuleiro, x_inicial, y_inicial, TAMANHO_DIAGONAL, 1)) {
            posicionarNavioDiagonal(tabuleiro, x_inicial, y_inicial, TAMANHO_DIAGONAL, 1); // Direção 1 (cima direita)
            valido = 1;
        } else {
            printf("Posição inválida ou ocupada.\n");
        }
    }

    // Navio diagonal 2
    valido = 0;
    while (!valido) {
        printf("Digite a posição inicial do navio diagonal 2 (coluna linha): ");
        scanf("%d %d", &x_inicial, &y_inicial);
        x_inicial -= 1;  
        y_inicial -= 1;  

        if (posicaoValidaDiagonal(tabuleiro, x_inicial, y_inicial, TAMANHO_DIAGONAL, -1)) {
            posicionarNavioDiagonal(tabuleiro, x_inicial, y_inicial, TAMANHO_DIAGONAL, -1); // Direção -1 (baixo direita)
            valido = 1;
        } else {
            printf("Posição inválida ou ocupada.\n");
        }
    }

    printf("\nTabuleiro:\n");
    EXIBIR(tabuleiro);

    return 0;
}
