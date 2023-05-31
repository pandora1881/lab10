#include <stdio.h>

int main() {
    FILE *file;
    int num, position = 1;
    
    // Відкриття файлу для допису
    file = fopen("input.txt", "a");
    if (file == NULL) {
        printf("Помилка відкриття файлу.");
        return 1;
    }
    
    // Перебір чисел у файлі
    while (fscanf(file, "%d", &num) == 1) {
        // Перевірка, чи число парне та чи його позиція непарна
        if (num % 2 == 0 && position % 2 != 0) {
            // Запис дубльованого числа
            fprintf(file, "%d ", num);
        }
        
        // Збільшення позиції
        position++;
    }
    
    // Закриття файлу
    fclose(file);
    
    printf("Процес дублювання завершено.");
    return 0;
}
