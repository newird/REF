#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> nums;
    int input;
    int money=0;
    int minget=-1;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        if (minget==-1 || input < minget){
            minget = input;
        }else{
            money = max(input - minget,money);
        }
    }
    cout << money;
}
