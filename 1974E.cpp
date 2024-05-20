#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long
#define fdiv(a,b) ((double)(a)/(b))
#define fceil(a,b) (ceil(fdiv(a,b)))
#define ll long long
#define lld long long double
#define F first
#define S second
#define vi vector<int>
#define vll vector<ll>
#define sort_n(a) sort(a.begin(), a.end())
#define sort_r(a) sort(a.begin(), a.end(), greater<int>())
#define pb(x) push_back(x)
#define find_v(a, x) find(a.begin(), a.end(), x)
#define all(a) a.begin(), a.end()
#define erase_v(a, x) erase(find_v(a, x))
#define max3(a, b, c) (max(a, max(b, c)))
#define max4(a, b, c, d) (max(a, max3(b, c, d)))
#define min3(a, b, c) (min(a, min(b, c)))
#define min4(a, b, c, d) (min(a, min3(b, c, d)))
#define scan(v) {for(auto&i:v) {cin>>i;} }
#define print(v) {cout<<endl; for(auto &i:v) {cout<<i<<" ";} cout<<endl;}
#define contains(M,k) M.find(k)!=M.end()
#define initdp(dp) memset(dp,-1,sizeof(dp))
#define init_v(arr, start) iota(arr.begin(), arr.end(), start)
#define isodd(x) (x&1)
#define iseven(x) (!isodd(x))
#define b_search(a,x) binary_search(a.begin(),a.end(),x)
#define _strcmp(s1,s2) strcmp(s1.data(),s2.data())
#define lb(a,x) lower_bound(a.begin(),a.end(),x)
#define ub(a,x) upper_bound(a.begin(),a.end(),x)
#define lbi(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ubi(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define isclose(a,b) (abs((a)-(b))<1e-9)
#define sum(a,start) accumulate(a.begin(),a.end(),start)
#define psum(a,i,start) accumulate(a.begin(),a.begin()+i,start)
#define sum_ap(a) (a.size()/2 *(a[0]+a.back()))
#define sum_gp(a) ((a.back()*(a[1]/a[0])-a[0])/((a[1]/a[0])-1))
#define ndigs(a,b) floor(log((long double)a)/log((long double)b)+1)
#define elz(s) (s.erase(s.begin(),find_v(s,'1')))
#define ignore cin.ignore()
template<typename T1,typename T2>
void pxsum(vector<T1>& v,vector<T2>& arr){v[0]=arr[0];for(int k=1;k<arr.size();k++){v[k]=v[k-1]+arr[k];}}
inline string binary(auto a) {
    int64_t x=static_cast<int64_t> (a); char temp[65];memset(temp,'0',sizeof(temp));
    temp[64]='\0';int i=63;while(x!=0){
        if(x&1)temp[i]='1';x=x>>1;
        i--;}string s(temp);elz(s);return s;
}
#define YES cout<<"YES"
#define NO cout<<"NO"
#define Umap unordered_map
#define Uset unordered_set
template<typename T>
vector<T> uniq(vector<T>& v){
    Uset<T> s(v.begin(),v.end());
    return vector<T>(s.begin(),s.end());
}
#include <chrono>
#include <functional>
#include <utility>

struct phash
{
    template <typename T1, typename T2>
    size_t operator()(const std::pair<T1, T2> &p) const
    {
        // Get current time point for randomness
        auto now = std::chrono::high_resolution_clock::now().time_since_epoch().count();

        // Hash each element of the pair
        size_t h1 = std::hash<T1>{}(p.first);
        size_t h2 = std::hash<T2>{}(p.second);

        // Combine hashes with time-based randomness
        h1 ^= now + 0x9e3779b9 + (h1 << 6) + (h1 >> 2);
        h2 ^= now + 0x9e3779b9 + (h2 << 6) + (h2 >> 2);

        // Combine final hashes
        return h1 ^ (h2 << 1);
    }
};
int x;
int getMax(int i,auto& ch,auto& dp,int cur){
    if(cur<0) return -99999;
    if(i>=ch.size()) return 0ll;
   if(dp.find(cur)!=dp.end()) return dp[cur];
    if(cur>=ch[i].F)
        return dp[cur]=max(ch[i].S+getMax(i+1,ch,dp,cur-ch[i].F+x),getMax(i+1,ch,dp,cur+x));
    return dp[cur] = getMax(i + 1, ch, dp, cur + x);
}

void helper(){
  int m;
  cin>>m>>x;
  vector<pair<int,int>> ch;
  for(int i=0;i<m;i++){
    int t1,t2;
    cin>>t1>>t2;
    ch.push_back({t1,t2});
  }
    unordered_map<ll,int> dp;
    cout<<getMax(0,ch,dp,0);
  
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        helper();
        cout << endl;
    }
    return 0;
}