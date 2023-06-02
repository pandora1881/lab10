#include <stdio.h>
#include <stdlib.h>

void copyData(const char* inputFile, const char* outputFile, int startPos, int numData) {
    FILE* input = fopen(inputFile, "rb");
    FILE* output = fopen(outputFile, "wb");
    
    if (input == NULL || output == NULL) {
        printf("Помилка при відкритті файлів.\n");
        return;
    }
    
    // Переміщуємо покажчик читання в задану позицію
    fseek(input, startPos * sizeof(int), SEEK_SET);
    
    // Зчитуємо дані, які будемо видаляти
    int* removedData = (int*)malloc(numData * sizeof(int));
    fread(removedData, sizeof(int), numData, input);
    
    // Переміщуємо покажчик читання на початок файлу
    fseek(input, 0, SEEK_SET);
    
    // Копіюємо дані до нового файлу, пропускаючи видалені дані
    int currentData;
    while (fread(&currentData, sizeof(int), 1, input)) {
        int found = 0;
        for (int i = 0; i < numData; i++) {
            if (currentData == removedData[i]) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            fwrite(&currentData, sizeof(int), 1, output);
        }
    }
    
    fclose(input);
    fclose(output);
    
    free(removedData);
}

int main() {
    const char* inputFile = "input.bin";
    const char* outputFile = "output.bin";
    int startPos = 3;   // Початкова позиція, з якої видаляємо дані
    int numData = 4;    // Кількість даних, які видаляємо
    
    copyData(inputFile, outputFile, startPos, numData);
    
    printf("Дані було успішно видалено та скопійовано до нового файлу.\n");
    
    return 0;
}
