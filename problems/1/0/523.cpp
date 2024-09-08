#include <iostream>
using namespace std;

void Test1() {
    int A = 0, B = 0;
    cin >> A >> B;
    cout << A + B;
};

void Test2() {
    int N = 0;
    cin >> N;
    if (N < 1)  cout << -1;
    else {
        long long ans = (1 + N) * N / 2;
        cout << ans;
    }
};


int main()
{
    Test2();
}


