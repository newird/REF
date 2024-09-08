#include<iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int part(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = part(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

    int main() {
	int n, m, d;
	cin >> n >> m >> d;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int result = 0;
	int last_time = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i - 1; j < n; j++) {

            int* b = new int[j+1];
            for (int k = 0; k < j; k++) {
                b[k] = a[k];
            }
            quickSort(b, 0, j);
            for (int k = 0; k < (j + 1) / 2; k++) {
                swap(b[k], b[j - k]);
            }
            int movie = a[j];
            for (int k = 0; k < i - 1; k++) {
                movie += b[k];
            }
            int happiness = movie - (j + 1) * d;
            if (happiness > result)
                result = happiness;
        }
    }
    cout << result;
    return 0;
}