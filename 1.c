#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    int number;
    int position = 1; // змінна, що відстежує поточну позицію числа

    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    if (inputFile == NULL) {
        printf("Помилка при відкритті вхідного файлу\n");
        return 1;
    }

    if (outputFile == NULL) {
        printf("Помилка при відкритті вихідного файлу\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%d", &number) == 1) {
        if (position % 2 == 1 && number % 2 == 0) {
            fprintf(outputFile, "%d %d ", number, number);
        } else {
            fprintf(outputFile, "%d ", number);
        }

        position++;
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Результати записані у файл output.txt\n");

    return 0;
}
