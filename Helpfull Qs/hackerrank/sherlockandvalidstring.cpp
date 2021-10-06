#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s)
{
    int p = s.size();
    unordered_map<char, int> m;
    for (int i = 0; i < p; i++)
    {
        m[s[i]] = 0;
    }
    for (int i = 0; i < p; i++)
    {
        m[s[i]]++;
    }
    int mini = INT_MAX;

    for (int i = 0; i < m.size(); i++)
    {
        if (m[i] < mini)
        {
            mini = m[i];
        }
    }
    bool flag = true;
    for (int i = 0; i < m.size(); i++)
    {
        if (m[i] != mini || m[i] != mini + 1)
        {
            flag = false;
        }
        else if(m[i] != mini || m[i] == mini + 1)
        {
                flag=true;
        }
        else if(m[i] == mini || m[i] == mini + 1)
        {
                flag=true;
        }
    }
    string s1 = "YES", s2 = "NO";
    if (flag)
    {
        return s1;
    }
    else
    {
        return s2;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
