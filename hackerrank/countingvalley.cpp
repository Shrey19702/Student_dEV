//LOGIC SUM /-(WHEN SUM IS ZERO AND ELEMTN CORRESPOND TO IT IS 1 THEN IS A VALLEY AND IF SUM IS 0 AND ELEMENT CORRESPOND TO IT EQUAL TO -1 THEN ITS A MOUNTAIN)
# include<bits/stdc++.h>
using namespace std;

int main()
{
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
string path;
int steps;
cin>>steps;
int a[steps],sum=0,COUNT=0;
cin>>path;
for(int i=0;i<path.length();i++){
    if(path[i]=='U'){
        a[i]=1;
    }
    if(path[i]=='D'){
        a[i]=-1;
    }
}
 for (int i = 0; i < steps; i++)
    {
       sum=sum+ a[i];
       if(sum==0&&a[i]==1){
           COUNT++;
       }
       
    }
    
   
   cout<< COUNT;
    

}