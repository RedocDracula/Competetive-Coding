#include <iostream>
#include <vector>

using namespace std;

void LIS(int *a, int n){
    int t[n] = {0};
    int max = 1;
    vector <int> global[n];
    vector <int> temp;
    for(int i=0;i< n; i++){
        t[i] = 1; // The largest increasing subsequence at this point is at least of size 1.
        
            for(int j = 0 ; j <i ; j++)
            {
                if(a[i] > a[j] && t[i] < t[j] + 1){ // The current number must be appended to the largest previous subsequence only if it is greater than the last element of the previous subsequence
                    t[i] = t[j] +1;
                    max = t[i];
                    global[i].resize(global[j].size());
                    copy(global[j].begin(),global[j].end(),global[i].begin());
                }
            }
        

         global[i].push_back(a[i]); // regardless we need to push a[i] to the LIS at this poiny

         if(global[i].size() > temp.size()){
             temp.resize(global[i].size());
             copy(global[i].begin(),global[i].end(),temp.begin());
         }
    }

    

    cout<<"Largest Subsequence (increasing) : ";
    for(int i = 0 ; i < temp.size() ; i++)
        cout<<temp[i]<< " ";

        cout<<endl;


}

int main()
{
    int *a;
    int n;
    cout<<"Enter the size of the sequence : ";
    cin>>n;
    a  = new int[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    LIS(a,n);
    return 0;
}
