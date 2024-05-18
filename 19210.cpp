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
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;
    cin>>x4>>y4;
    if(x1==x2){
        cout<<(y1-y2)*(y1-y2);
    }else if(x1==x3){
        cout<<(y1 - y3) * (y1 - y3);
    }else{
        cout<<(y1 - y4) * (y1 - y4);
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