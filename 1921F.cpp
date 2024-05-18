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

void helper(){
    int n,q,s,d,k;
    cin>>n>>q;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    long long p=0,i;
    long long res;
    for(int j=0;j<q;j++){
        cin >> s >> d >> k;
        i = 0;
        p=0;
        res=0;
        while (i < k)
        {
            p += arr[s + i * d];
            res -= (k - i) * 1ll * arr[s + i * d];
             i++;
        }
        //cout<<"P "<<p<<" ";
        res+=(k+1)*1ll*p;
        cout<<res<<" ";
    }



}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t)
    {
        helper();
        cout << endl;
        t--;
    }
    return 0;
}