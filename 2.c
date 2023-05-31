#include <stdio.h>

int main() {
    int array[] = {5, 8, 2, 1, 0, 4, 6, 3, 0, 9};
    int length = sizeof(array) / sizeof(array[0]);
    int count = 0;
    int product = 1;
    int first_zero_index = -1;
    int second_zero_index = -1;

    for (int i = 0; i < length; i++) {
        if (array[i] < 7) {
            count++;
        }

        if (array[i] == 0) {
            if (first_zero_index == -1) {
                first_zero_index = i;
            } else if (second_zero_index == -1) {
                second_zero_index = i;
                break;
            }
        }
    }

    if (first_zero_index != -1 && second_zero_index != -1) {
        for (int i = first_zero_index + 1; i < second_zero_index; i++) {
            product *= array[i];
        }
    } else {
        product = 0;  // Якщо немає двох нулів, добуток буде 0
    }

    printf("Кількість елементів масиву, менших за число сім: %d\n", count);
    printf("Добуток елементів масиву, розташованих між першим і другим нульовими елементами: %d\n", product);

    return 0;
}
