// #include <bits/stdc++.h>

// using namespace std;

// // Complete the makeAnagram function below.
// int makeAnagram(string a, string b) {
// int count=0;
// for(int i=0;i<strlen(a);i++){
//     for(int j=1;j<strlen(a);j++){
//         if(a[i]==b[j]){
//             count=count+1;
//         }
//     }
// }
// return (strlen(a)+strlen(b)-count);

// }

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string a;
//     getline(cin, a);

//     string b;
//     getline(cin, b);

//     int res = makeAnagram(a, b);

//     fout << res << "\n";

//     fout.close();

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    int val, diff=0;
    cin >> a >> b;
    int one_arr[26] = {0}, two_arr[26] = {0};
    for (int i = 0; i < a.length(); i++)
    {
        val = a[i] - 97; //store occurance in int form of words in our string
        one_arr[val]++;
    }
    for (int i = 0; i < b.length(); i++)
    {
        val = b[i] - 97; //store occurance in int form of words in our string
        two_arr[val]++;
    }
    for (int i = 0; i < 26; i++)
    {
        diff += abs(one_arr[i] - two_arr[i]);
    }
    cout << diff;
    return 0;
}
