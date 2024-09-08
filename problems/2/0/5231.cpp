#include <iostream>
using namespace std;

int max(int num1, int num2)
{
    if (num1 > num2) return num1;
    else             return num2;
}

int min(int num1, int num2)
{
    if (num1 < num2) return num1;
    else             return num2;
}


int main(void)
{
    int num_of_days;
    cin >> num_of_days;
    int biggest = 0;
    int nums[100000];
    cin >> nums[0];
    int is_rise = 0;
    int curr_rise = 0;
    int min_num, max_num;
    for (int curr_day = 1; curr_day < num_of_days; curr_day++)
    {  
        cin >> nums[curr_day];
        if (nums[curr_day] > nums[curr_day - 1])
        {
            if (!is_rise)
            {
                is_rise = 1;
                min_num = nums[curr_day - 1];
                curr_rise = nums[curr_day] - nums[curr_day - 1];
            }
            else
            {
                curr_rise += nums[curr_day] - nums[curr_day - 1];
            }
        }
        else
        {
            if (curr_rise <= 0)
            {
                is_rise = 0;
                curr_rise = 0;
            }
            else
            {
                biggest = max(biggest, curr_rise);
                curr_rise += nums[curr_day] - nums[curr_day - 1];
            }
        }
    }
    cout << biggest;
    return 0;
}