#include <stdio.h>
#include <stdbool.h>

#define FILAS 7
#define COLUMNAS 7

char laberinto[FILAS][COLUMNAS] = {
    {'#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', '#', '#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#'}
};

void imprimir_laberinto(int jugador_x, int jugador_y) {
    for (int y = 0; y < FILAS; y++) {
        for (int x = 0; x < COLUMNAS; x++) {
            if (x == jugador_x && y == jugador_y) {
                printf("P ");
            } else {
                printf("%c ", laberinto[y][x]);
            }
        }
        printf("\n");
    }
}

bool mover(char direccion, int *jugador_x, int *jugador_y) {
    int nuevo_x = *jugador_x;
    int nuevo_y = *jugador_y;

    switch (direccion) {
        case 'w': nuevo_y--; break;
        case 's': nuevo_y++; break;
        case 'a': nuevo_x--; break;
        case 'd': nuevo_x++; break;
        default: return false;
    }

    if (nuevo_x >= 0 && nuevo_x < COLUMNAS && nuevo_y >= 0 && nuevo_y < FILAS && laberinto[nuevo_y][nuevo_x] != '#') {
        *jugador_x = nuevo_x;
        *jugador_y = nuevo_y;
        return true;
    }
    return false;
}

void jugar() {
    int jugador_x = 1, jugador_y = 1;
    int salida_x = 5, salida_y = 5;
    char movimiento;

    while (true) {
        imprimir_laberinto(jugador_x, jugador_y);

        if (jugador_x == salida_x && jugador_y == salida_y) {
            printf("¡Felicidades! Has escapado del laberinto.\n");
            break;
        }

        printf("Ingresa tu movimiento (w/a/s/d) o 'q' para salir: ");
        scanf(" %c", &movimiento);

        if (movimiento == 'q') {
            printf("Gracias por jugar.\n");
            break;
        } else if (movimiento == 'w' || movimiento == 'a' || movimiento == 's' || movimiento == 'd') {
            if (!mover(movimiento, &jugador_x, &jugador_y)) {
                printf("No puedes moverte en esa dirección.\n");
            }
        } else {
            printf("Movimiento inválido. Usa w/a/s/d para moverte.\n");
        }
    }
}

int main() {
    jugar();
    return 0;
}