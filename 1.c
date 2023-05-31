#include <stdio.h>

void duplicateEvenNumbers(int arr[], int size) {
    int i;
    for (i = 1; i < size; i += 2) {
        if (arr[i] % 2 == 0) {
            // Перед дублюванням елемента зсунемо всі елементи вправо
            for (int j = size - 1; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            // Дублюємо парне число
            arr[i] = arr[i - 1];
            size++; // Збільшуємо розмір масиву
            i++; // Збільшуємо індекс, щоб перейти до наступної пари чисел
        }
    }
}

int main() {
    // Вхідний масив чисел
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Початковий масив:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    duplicateEvenNumbers(numbers, size);

    printf("Масив після дублювання парних чисел:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
