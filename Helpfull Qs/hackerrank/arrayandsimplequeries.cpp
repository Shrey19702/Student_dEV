

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define asc(i, x, n) for (I i = x; i < n; i++)
#define dsc(i, x, n) for (I i = x; i >= n; i--)
#define W(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define U unsigned
#define I long long int
#define S string
#define C char
#define D long double
#define A auto
#define B bool
#define pb push_back
#define V(x) vector<x>
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    V(int)
    a;
    asc(i, 0, n)
    {
        int x;
        cin >> x;
        a.pb(x);
    }
    asc(i, 0, m)
    {
        int x, y, z;
        V(int)
        a1, b1, c1;
        cin >> x >> y >> z;
        if (x == 1)
        {
            asc(j, 0, n)
            {
                if (j >= y - 1 && j <= z - 1)
                {
                    a1.pb(a[j]);
                    // cout<<a1[j]<<" ";
                }
                else
                {
                    b1.pb(a[j]);
                    // cout<<b1[j]<<" ";
                }
            }

            asc(i, 0, a1.size())
            {
                c1.pb(a1[i]);
            }
            asc(i, 0, b1.size())
            {
                c1.pb(b1[i]);
            }
            asc(i, 0, c1.size())
            {
                a[i] = c1[i];
                // cout<<a[i]<<" ";
            }
            // cout<<endl;
        }
        else if (x == 2)
        {
            asc(j, 0, n)
            {
                if (j >= y -1 && j <= z -1)
                {
                    a1.pb(a[j]);
                    // cout<<a[j]<<" ";
                }
                else
                {
                    b1.pb(a[j]);
                    // cout<<a[j]<<" ";
                }
            }

            asc(i, 0, b1.size())
            {
                c1.pb(b1[i]);
            }
            asc(i, 0, a1.size())
            {
                c1.pb(a1[i]);
            }
            asc(i, 0, c1.size())
            {
                a[i] = c1[i];
                // cout<<a[i]<<" ";
            }
            // cout<<endl;
        }
    }
    cout<<abs(a[0]-a[a.size()-1])<<endl;
    asc(i,0,a.size())
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";

    return 0;
}