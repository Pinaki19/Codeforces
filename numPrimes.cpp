#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <cstdlib>
using namespace std;
#define ll long long
#include <bitset>

vector<bool> prime(2 * 1e6 + 2, true);
void markPrimes(){
    prime[0]=false;
    prime[1]=false;
    for (ll i = 2; i < 2 * 1e6 + 2;i++){
        if(prime[i]){
            for (ll j = 2; i*j < 2 * 1e6 + 2;j++){
                prime[i*j]=false;
            }
        }
    }
}

void helper(){
    ll l,r;
    cin>>l>>r;
    ll ans=0;
    for(ll i=l;i<=r;i++){
        if(prime[i])
            ans++;
        if (i + 1<=r && prime [2 * i + 1])
            ans++;
    }
    cout<<ans;
}

int main()
{
   
    int t;
    cin >> t;
    markPrimes();
    while (t)
    {
        helper();
        cout << endl;
        t--;
    }
    return 0;
}