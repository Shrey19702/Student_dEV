#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[6][6], max = INT_MIN, sum[16], count = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j< 4; j++)
        {
            sum[count] = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
            count = count + 1;
        }
    }
    for (int i = 0; i < 16; i++)
    {
        if (max < sum[i])
        {
            max = sum[i];
        }
    }
    cout << max << "\n";

    return 0;
}