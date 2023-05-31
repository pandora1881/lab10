#include <stdio.h>

int main() {
    FILE *file;
    int num, position = 1;
    
    // Відкриття файлу для читання та запису
    file = fopen("input.txt", "r+");
    if (file == NULL) {
        printf("Помилка відкриття файлу.");
        return 1;
    }
    
    // Перебір чисел у файлі
    while (fscanf(file, "%d", &num) == 1) {
        // Перевірка, чи число парне та чи його позиція непарна
        if (num % 2 == 0 && position % 2 != 0) {
            // Зсув позиції назад та переміщення вказівника файлу на потрібну позицію
            fseek(file, -sizeof(int), SEEK_CUR);
            
            // Запис дубльованого числа
            fprintf(file, "%d %d ", num, num);
            
            // Зсув позиції вперед
            fseek(file, sizeof(int), SEEK_CUR);
        }
        
        // Збільшення позиції
        position++;
    }
    
    // Закриття файлу
    fclose(file);
    
    printf("Процес дублювання завершено.");
    return 0;
}
