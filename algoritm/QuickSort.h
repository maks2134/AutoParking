#include <iostream>
#include <vector>
#include <algorithm>

class QuickSort {
private:
    // Вспомогательная функция для разделения массива (partition)
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // Опорный элемент
        int i = low - 1;       // Индекс меньшего элемента

        for (int j = low; j < high; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                std::swap(arr[i], arr[j]); // Обмениваем элементы
            }
        }

        std::swap(arr[i + 1], arr[high]); // Устанавливаем опорный элемент на место
        return i + 1; // Возвращаем индекс опорного элемента
    }

    // Вспомогательная рекурсивная функция для сортировки
    void quicksort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quicksort(arr, low, pivotIndex - 1); // Сортировка левой части
            quicksort(arr, pivotIndex + 1, high); // Сортировка правой части
        }
    }

public:
    // Метод для запуска сортировки
    void sort(std::vector<int>& arr) {
        if (!arr.empty()) {
            quicksort(arr, 0, arr.size() - 1);
        }
    }

    // Метод для вывода содержимого массива
    void printArray(const std::vector<int>& arr) const {
        for (const auto& elem : arr) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};
