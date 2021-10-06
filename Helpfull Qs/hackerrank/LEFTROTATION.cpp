#include <bits/stdc++.h>
using namespace std;
vector<int> rotLeft(vector<int> &a, int d)
{
    vector<int> ans;
    for (int i = d; i < a.size(); i++)
    {
        ans.push_back(a[i]);
    }
    for (int i = 0; i < d; i++)
    {
        ans.push_back(a[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d;
    vector<int> a, a1;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        a.push_back(j);
    }
    a1 = rotLeft(a, d);
    for (int i = 0; i < a1.size(); i++)
    {
        cout << a1[i];
    }
}