#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> s >> n;
    long diff, count = 0, p = s.length(), q, r;
    for (long i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            count++;
        }
    
    }
        q = n / p;
        q = q * count;
        r = n % p;
        long count2=0,sum=0;
        for (int i = 0; i < r; i++)
        {
            if (s[i] == 'a')
            {
                count2++;
            }
        }
        sum=count2+q;
    return 0;
}