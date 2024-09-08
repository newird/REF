#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int happiness = 0;
    int daysSinceLastCinema = 1;
    int cinemasVisited = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > daysSinceLastCinema * d) {
            if (cinemasVisited < m) {
                happiness = happiness + a[i] - (daysSinceLastCinema * d);
                cinemasVisited++;
                daysSinceLastCinema = 1;
            }
            else {
                break;
            }
        }
        else {
            daysSinceLastCinema++;
        }
    }

    cout << happiness << endl;

    return 0;
}