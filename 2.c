#include <stdio.h>
#include <stdlib.h>

void moveData(const char* sourceFileName, const char* destinationFileName, int startPosition, int numData) {
    FILE* sourceFile = fopen(sourceFileName, "rb");
    FILE* destinationFile = fopen(destinationFileName, "wb");

    if (sourceFile == NULL || destinationFile == NULL) {
        printf("Помилка відкриття файлу.\n");
        return;
    }

    // Отримуємо розмір файлу
    fseek(sourceFile, 0, SEEK_END);
    long fileSize = ftell(sourceFile);
    fseek(sourceFile, 0, SEEK_SET);

    // Перевірка чи startPosition і numData є в межах розміру файлу
    if (startPosition < 0 || startPosition >= fileSize || startPosition + numData > fileSize) {
        printf("Помилкові параметри позиції або кількості даних.\n");
        fclose(sourceFile);
        fclose(destinationFile);
        return;
    }

    // Створюємо буфер для збереження даних
    char* buffer = (char*)malloc(fileSize);

    // Зчитуємо дані з початку файлу до startPosition
    fread(buffer, startPosition, 1, sourceFile);
    fwrite(buffer, startPosition, 1, destinationFile);

    // Зчитуємо дані, які потрібно видалити
    fseek(sourceFile, startPosition + numData, SEEK_SET);
    fread(buffer, fileSize - (startPosition + numData), 1, sourceFile);
    fwrite(buffer, fileSize - (startPosition + numData), 1, destinationFile);

    // Переміщуємо позицію файлового вказівника до startPosition для запису вставлених даних
    fseek(destinationFile, startPosition, SEEK_SET);

    // Зчитуємо дані, які потрібно вставити
    fseek(sourceFile, startPosition, SEEK_SET);
    fread(buffer, numData, 1, sourceFile);
    fwrite(buffer, numData, 1, destinationFile);

    free(buffer);
    fclose(sourceFile);
    fclose(destinationFile);
}

int main() {
    const char* sourceFileName = "input.bin";
    const char* destinationFileName = "output.bin";
    int startPosition = 4;  // Позиція, з якої будуть видалені дані
    int numData = 2;        // Кількість даних, які потрібно видалити та вставити

    moveData(sourceFileName, destinationFileName, startPosition, numData);

    printf("Операція завершена.\n");

    return 0;
}
