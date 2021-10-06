#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr;
    int n, count = 0, min,r=1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        while (arr[i] != (i + 1))
        {
           swap(arr[i],arr[arr[i]-1]);
            
            count++;
        }
    }
    cout << count;
    return 0;
}