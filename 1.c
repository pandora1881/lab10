#include <stdio.h>

int main() {
    FILE *file = fopen("input.txt", "r+");
    if (file == NULL) {
        printf("Помилка при відкритті файлу.");
        return 1;
    }

    int number;
    int position = 0;

    while (fscanf(file, "%d", &number) == 1) {
        if (position % 2 != 0 && number % 2 == 0) {
            fprintf(file, "%d ", number);
        }
        fprintf(file, "%d ", number);
        position++;
    }

    fclose(file);
    printf("Операція завершена.");
    return 0;
}
