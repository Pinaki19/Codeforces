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
   long long n,charge,lostWhenOn,lostToStdn;
   cin>>n>>charge>>lostWhenOn>>lostToStdn;
   int arr[n];
   for(int i=0;i<n;i++)
        cin>>arr[i];
    bool flag=true;
    long long start=0,t,t1;
    if(arr[0]*1ll*lostWhenOn>lostToStdn){
        charge-=lostToStdn;
    }else{
        charge-=arr[0]*1ll*lostWhenOn;
    }
    while(start<n && charge>0){
        if(start<n-1){
            t=arr[start+1]-arr[start];
            //cout<<"Curr: "<<charge<<" "<<t<<endl;
            if(t*1ll*lostWhenOn>lostToStdn){
                charge-=lostToStdn;
            }else{
                charge-=t*1ll*lostWhenOn;
            }
        }
        start++;
    }
    if(start==n)
        cout<<"YES";
    else
        cout<<"NO";
    
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