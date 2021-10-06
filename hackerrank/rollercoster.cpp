#include <bits/stdc++.h>
using namespace std;

void minimumBribes(vector<int> q)
{
    int ans = 0;
    for (int i = q.size() - 1; i >= 0; i--)
    {
        if (q[i] != i + 1)
        {
            if ((i - 1 >= 0) && q[i - 1] == i + 1)
            {
                ans++;
                swap(q[i], q[i - 1]);
            }
            else if ((i - 2 >= 0) && q[i - 2] == i + 1)
            {
                ans += 2;
                int temp = q[i - 2];
                q[i - 2] = q[i - 1];
                q[i - 1] = q[i];
                q[i] = temp;

            }
            else
            {
                cout << "Too chaotic"
                     << "\n";
                return;
            }
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
