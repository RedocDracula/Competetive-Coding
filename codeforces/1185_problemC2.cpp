#include <bits/stdc++.h> 
#define ll long long 
#define pb push_back 
#define mp make_pair() 

using  namespace std; 
 
int f[101] = {0};


int main() {

    ll n,m;
    cin>>n>>m;
    ll a[n];
    ll sum = 0;

    
    for(int i = 0  ; i < n ; i++)
    {
        cin>>a[i];
        sum += a[i];
        ll x = 0;
        if(sum - m > 0){
            ll needed = sum - m;
            
            double required;
            for(int i = 100 ; i >=1; i--){
                required = ceil(needed*1.0/i*1.0);
                
                if(required > f[i]){
                    x += f[i];
                    needed = needed - f[i]*i;
                }
                else
                {
                    x += required;
                    break;
                }
                
            }
        }
        
        if(i != n-1)
        cout<<x<<" ";
        else
        cout<<x;

        f[a[i]]++;
    }

    return 0; 

}
