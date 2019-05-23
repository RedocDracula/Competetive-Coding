#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    int n;
    cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; i++)
        cin>>a[i];
    
    int t[n];
    vector <int> arr;

    t[0] = 1;
    int maxindex = 0;

    vector <int> list[n];
    vector <int> longlist;

    for(int i = 0 ; i < n ; i++){
        t[i] = 1;
        
        for(int j = 0 ; j < i ; j++){
            if(a[i] > a[j] && t[i] < t[j] + 1)
              { 
                   t[i] = t[j] + 1;
                   longlist.resize(list[j].size());
                   copy(list[j].begin(),list[j].end(),longlist.begin());
                   longlist.push_back(a[i]);
              }
        }


        if(t[i] == 1)
            list[i].push_back(a[i]);  
        else
           { 
               list[i].resize(longlist.size());
               copy(longlist.begin(), longlist.end(), list[i].begin());
           }
    }

    for(int i = 0 ; i < longlist.size() ; i++)
        cout<<longlist[i]<<" ";
    
    
    return 0 ;
}
