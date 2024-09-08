#include <iostream>

using namespace std;

int max(int num1, int num2)
{
    if (num1 > num2)    return num1;
    else                return num2;
}

int main(void)
{
    int digit1, digit2;
    cin >> digit1 >> digit2;
    int num1[100001], num2[100001], res[100001];
    int digit3 = max(digit1, digit2);
    for(int i = 0; i < digit1; i++)
    {
        cin >> num1[i];
    }
    for(int i = 0; i < digit2; i++)
    {
        cin >> num2[i];
    }
    int curr1, curr2;
    int cin = 0;
    for (int i = 0; i < max(digit1, digit2); i++)
    {
        if (i >= digit1)
        {
            curr1 = 0;
        }
        else
        {
            curr1 = num1[i];
        }
        if (i >= digit2)
        {
            curr2 = 0;
        }
        else
        {
            curr2 = num2[i];
        }
        if (curr1 + curr2 + cin >= 10)
        {
            res[i] = (curr1 + curr2 + cin) % 10;
            cin = 1;
            if (i == max(digit1, digit2) - 1)
            {
                digit3++;
                res[i + 1] = 1;
                break;
            }
        }
        else
        {
            res[i] = curr1 + curr2 + cin;
            cin = 0;
        }
    }
    for(int i = digit3 - 1; i >= 0; i--)
    {
        cout << res[i];
    }
    return 0;
}