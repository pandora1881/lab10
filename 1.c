#include <stdio.h>

int main() {
    // Відкриваємо файл для читання
    FILE *file = fopen("numbers.txt", "r");
    
    // Перевіряємо, чи файл існує
    if (file == NULL) {
        printf("Помилка: неможливо відкрити файл.\n");
        return 1;
    }
    
    // Тут можна продовжити роботу з файлом
    
    // Закриваємо файл
    fclose(file);
    
    return 0;
}
