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
#include <cstring>
#include <forward_list>
#include <list>

using namespace std;
#define fdiv(a,b) ((double)a/b)
#define fceil(a,b) (ceil(fdiv(a,b)))
#define ll long long
#define lld long long double
#define F first
#define S second
#define vi vector<int>
#define vll vector<ll>
#define sort_n(a) sort(a.begin(), a.end())
#define sort_r(a) sort(a.begin(), a.end(), grreater<int>())
#define push(x) push_back(x)
#define find_v(a, x) find(a.begin(), a.end(), x)
#define erase_v(a, x) erase(find(a, x))
#define max3(a, b, c) (max(a, max(b, c)))
#define max4(a, b, c, d) (max(a, max3(b, c, d)))
#define min3(a, b, c) (min(a, min(b, c)))
#define min4(a, b, c, d) (min(a, min3(b, c, d)))
#define scan(v) {for(auto&i:v) {cin>>i;} }
#define print(v) {cout<<endl; for(auto &i:v) {cout<<i<<" ";} cout<<endl;}
#define mfind(Map,k) Map.find(k)!=Map.end()
#define initdp(dp) memset(dp,-1,sizeof(dp))
#define init_v(arr, start) iota(arr.begin(), arr.end(), start)
#define isodd(x) (x&1)
#define iseven(x) (!isodd(x))
#define b_search(a,x) binary_search(a.begin(),a.end(),x)
#define _strcmp(s1,s2) strcmp(s1.data(),s2.data())
class Solution
{
public:
    int numberOfDigits(int N, int B)
    {
        return floor(log(static_cast<long double>(N)) / log(static_cast<long double>(B)) + 1);
    }
};

void helper(){
    int N,B;
    cin>>N>>B;
    Solution s;
    cout<<s.numberOfDigits(N,B);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        helper();
        cout<<endl;
    }
    return 0;
}