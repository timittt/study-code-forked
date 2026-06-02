#include <iostream>

int main() {
    // Array mit 4 Elementen initialisieren
    int arr[4] = { 34, 12, 5, 23 };
    int n = 4;

    // Ausgabe des unsortierten Arrays
    std::cout << "Unsortiert: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Insertion Sort Algorithmus
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Verschiebe die Elemente, die größer als der 'key' sind,
        // um eine Position nach rechts
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        // Setze den 'key' an seine richtige Position
        arr[j + 1] = key;
    }

    // Ausgabe des sortierten Arrays
    std::cout << "Sortiert:   ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}