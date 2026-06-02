#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
/*
int main() {
    int arr[4] = {7, 3, 9, 4};
    int n = 4;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) { // j < n - 1 führt zu unnötig vielen Durchläufen (richtig: j < n - i - 1)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j + 1] = temp;   // das muss danach sein
                arr[j] = arr[j + 1]; // das muss davor sein
            }
            printArray(arr, n);
        }
    }

    return 0;
}*/