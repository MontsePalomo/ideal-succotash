//11 programa
//Marlen montserrat Palomo
//13-06-25
//codigo que lee y resulve un laberinto desde un bloc de notas 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIM 100

typedef struct {
    char** grid;
    int rows;
    int cols;
} Maze;

int loadMaze(Maze* m, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error al abrir: %s\n", filename);
        return 0;
    }

    char buffer[MAX_DIM];
    int max_cols = 0;
    int line_count = 0;

    while (fgets(buffer, MAX_DIM, file)) {
        int len = strlen(buffer);
        if (buffer[len-1] == '\n') buffer[--len] = '\0';
        if (len > max_cols) max_cols = len;
        line_count++;
    }

    m->rows = line_count;
    m->cols = max_cols;

    m->grid = (char**)malloc(m->rows * sizeof(char*));
    for (int i = 0; i < m->rows; i++) {
        m->grid[i] = (char*)malloc((m->cols + 1) * sizeof(char));
    }

    rewind(file);
    for (int i = 0; i < m->rows; i++) {
        fgets(buffer, MAX_DIM, file);
        int len = strlen(buffer);
        if (buffer[len-1] == '\n') buffer[--len] = '\0';

        strcpy(m->grid[i], buffer);
        for (int j = len; j < m->cols; j++) {
            m->grid[i][j] = ' ';
        }
        m->grid[i][m->cols] = '\0';
    }

    fclose(file);
    return 1;
}

void displayMaze(Maze* m) {
    for (int i = 0; i < m->rows; i++) {
        printf("%s\n", m->grid[i]);
    }
}

int pathfinder(Maze* m, int r, int c, char** visited) {
    if (r < 0 || c < 0 || r >= m->rows || c >= m->cols) return 0;
    if (m->grid[r][c] == '|' || m->grid[r][c] == '-' || visited[r][c]) return 0;
    if (m->grid[r][c] == 'S') return 1;

    visited[r][c] = 1;

    if (m->grid[r][c] != 'E') m->grid[r][c] = '*';

    const int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        if (pathfinder(m, r + moves[i][0], c + moves[i][1], visited)) {
            return 1;
        }
    }

    if (m->grid[r][c] != 'E') m->grid[r][c] = ' ';
    return 0;
}

int solveMaze(Maze* m) {
    int start_r = -1, start_c = -1;

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            if (m->grid[i][j] == 'E') {
                start_r = i;
                start_c = j;
                break;
            }
        }
        if (start_r != -1) break;
    }

    if (start_r == -1) {
        return 0;
    }

    char** visited = (char**)malloc(m->rows * sizeof(char*));
    for (int i = 0; i < m->rows; i++) {
        visited[i] = (char*)calloc(m->cols, sizeof(char));
    }

    int solved = pathfinder(m, start_r, start_c, visited);

    for (int i = 0; i < m->rows; i++) free(visited[i]);
    free(visited);

    return solved;
}

void freeMaze(Maze* m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->grid[i]);
    }
    free(m->grid);
}

int main() {
    Maze my_maze = {0};

    if (!loadMaze(&my_maze, "Laberinto.txt")) {
        return 1;
    }

    if (solveMaze(&my_maze)) {
        displayMaze(&my_maze);
    } else {
        printf("No existe solucion\n");
    }

    freeMaze(&my_maze);
    return 0;
}

