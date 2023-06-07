#include <stdio.h>
#include <stdlib.h>

void removeAndInsertIntegers(const char* inputFileName, const char* outputFileName, int startPos, int numToRemove, int insertPos) {
    FILE* inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Помилка відкриття вхідного файлу.\n");
        return;
    }

    FILE* outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Помилка відкриття вихідного файлу.\n");
        fclose(inputFile);
        return;
    }

    // Отримуємо розмір файлу
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    // Розмір одного цілого числа (припускаючи, що у файлі зберігаються лише цілі числа)
    int intSize = sizeof(int);

    // Перевірка чи є достатньо даних для видалення та вставки
    if (startPos < 0 || startPos >= fileSize / intSize ||
        insertPos < 0 || insertPos > fileSize / intSize ||
        startPos + numToRemove > fileSize / intSize) {
        printf("Некоректні параметри для видалення та вставки.\n");
        fclose(inputFile);
        fclose(outputFile);
        return;
    }

    // Вираховуємо розмір нового файлу
    long newFileSize = fileSize - (numToRemove * intSize) + (numToRemove * intSize);

    // Виділяємо пам'ять для збереження даних
    int* buffer = (int*)malloc(fileSize);
    if (buffer == NULL) {
        printf("Помилка виділення пам'яті.\n");
        fclose(inputFile);
        fclose(outputFile);
        return;
    }

    // Зчитуємо дані з вхідного файлу
    fread(buffer, intSize, fileSize / intSize, inputFile);
    fclose(inputFile);

    // Видаляємо задану кількість цілих чисел
    int* newBuffer = (int*)malloc(newFileSize);
    if (newBuffer == NULL) {
        printf("Помилка виділення пам'яті.\n");
        free(buffer);
        fclose(outputFile);
        return;
    }

    int i;
    for (i = 0; i < startPos; i++) {
        newBuffer[i] = buffer[i];
    }

    for (i = startPos + numToRemove; i < fileSize / intSize; i++) {
        newBuffer[i - numToRemove] = buffer[i];
    }

    // Вставляємо видалені числа на нову позицію
    for (i = 0; i < numToRemove; i++) {
        newBuffer[insertPos + i] = buffer[startPos + i];
    }

    // Записуємо дані у вихідний файл
    fwrite(newBuffer, intSize, newFileSize / intSize, outputFile);
    fclose(outputFile);

    // Звільняємо пам'ять
    free(buffer);
    free(newBuffer);

    printf("Операція успішно завершена.\n");
}

int main() {
    const char* inputFileName = "input.bin";
    const char* outputFileName = "output.bin";
    int startPos = 2;
    int numToRemove = 3;
    int insertPos = 5;

    removeAndInsertIntegers(inputFileName, outputFileName, startPos, numToRemove, insertPos);

    return 0;
}
