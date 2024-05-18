#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <numeric>
#include <cstdlib>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <cstdlib>
#include <cstring>
using namespace std;
#define ll long long

void helper(){
    int n;
    string s1,s2;
    cin>>n;
    cin.ignore();
    cin>>s1;
    cin.ignore();
    cin>>s2;
    int f1=0,f2=0;
    int start=0,c=0;
    while(start<s1.length()){
        if(s1[start]==s2[start] && s1[start]=='1')
            c++;  
        if(s1[start]=='1')
            f1++;
        if(s2[start]=='1')
            f2++;
        start++;
    }
    cout<<max(f2,f1)-c;
    
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