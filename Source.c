#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparsionCounter;
int swapCounter;

void insertionSort(int* array, int length) {
    int currentIndex, currentValue, prevIndex;
    for (currentIndex = 1; currentIndex < length; currentIndex++) { //îò âòîðîãî ýëåìåíòà äî ïîñëåäíåãî
        currentValue = array[currentIndex]; //çàïèñü òåêóùåãî çíà÷åíèÿ
        prevIndex = currentIndex - 1; //çàïèñü ïðåäûäóùåãî çíà÷åíèÿ

        //ïåðåìåùåíèå ýëåìåíòîâ, ÷òî áîëüøå òåêóùåãî íà îäíó ïîçèöèþ âïåðåä
        while (prevIndex >= 0 && array[prevIndex] > currentValue) { 
            comparsionCounter++;
            array[prevIndex + 1] = array[prevIndex]; //ñìåùåíèå ýëåìåíòà íà ïîçèöèþ âïåðåä
            swapCounter++;
            prevIndex = prevIndex - 1; //ïåðåõîä ê ñëåäóþùåìó ýëåìåíòó
        }
        array[prevIndex + 1] = currentValue; //çàïèñü òåêóùåãî çíà÷åíèÿ â êîððåêòíîå ìåñòî
    }
}

int* sort(int* array, int length) {
    int compare = 0, rearrange = 0, i, j, element;
    for (i = 1; i < length; i++) {
        element = array[i];
        array[0] = element;
        j = i - 1;
        while (array[j] > element) {
            comparsionCounter++;
            swapCounter++;
            array[j + 1] = array[j];
            j = j - 1;
        }
        swapCounter++;
        array[j + 1] = element;
    }
    return array;
}

int* sort_with_sentinel(int* arr, int size) {
    // Выделить место для сторожевого элемента
    int* sentinel = malloc(sizeof(int));
    *sentinel = INT_MIN; // INT_MIN

    // Скопировать элементы в массив с sentinel
    for (int i = 0; i < size; i++) {
        arr[i + 1] = arr[i];
    }

    // Сортировка
    for (int i = 1; i < size + 1; i++) {
        int current = arr[i];
        int j = i - 1;
        while (current < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }

    // Освободить память
    free(sentinel);
    return arr;
}

int main() {
    SetConsoleOutputCP(1251);
    srand(time(0));

    FILE* file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Îøèáêà îòêðûòèÿ ôàéëà.");
        exit(1);
    }
    fprintf(file, "Ðàçìåð ìàññèâà;Ñðåäíåå êîëè÷åñòâî ñðàâíåíèé;Ñðåäíåå êîëè÷åñòâî ïåðåñòàíîâîê\n");

    //çàïèñü ðåçóëüòàòîâ äëÿ ìàññèâîâ äëèíîé 100..10000 ýëåìåíòîâ ñ øàãîì 100
    for (int length = 100; length <= 10000; length += 100) {
        //ñáðîñ ñ÷åò÷èêîâ
        comparsionCounter = 0;
        swapCounter = 0;

        //ïÿòü ðàç
        for (int i = 0; i < 5; i++) {
            int* array = malloc(length * sizeof(int)); //ñîçäàíèå

            for (int index = 0; index < length; index++) {//çàïîëíåíèå
                array[index] = rand() % 100;
            }
            sort_with_sentinel(array, length); //ñîðòèðîâêà
            free(array); //îñâîáîæäåíèå
        }
        fprintf(file, "%d;%lf\n", length, (comparsionCounter / 5.0 + swapCounter / 5.0));
    }
    fclose(file);
    printf("Ãîòîâî.");

    return 0;
}