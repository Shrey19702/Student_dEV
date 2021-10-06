class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        
        vector<int> c;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    vector<int>::iterator i=a.begin();
    vector<int>::iterator j=b.begin();

    while(i!=a.end() && j!=b.end())
    {
        if(*i==*j){
            c.push_back(*i);
            i++;
            j++;
        }

        else if(*i>*j)
            j++;

        else if(*i<*j)
            i++;
    }
        
        return c;
        
    }
};
