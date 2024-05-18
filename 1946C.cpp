#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
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
#include <bitset>
#include <functional>
#include <cassert>

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
template<typename T1,typename T2>
void pxsum(vector<T1>& v,vector<T2>& arr){v[0]=arr[0];for(int k=1;k<arr.size();k++){v[k]=v[k-1]+arr[k];}}
string binary(auto &a) { assert(a>=0);string s=bitset<128> (a).to_string(); elz(s);return s;}
#define YES cout<<"YES"
#define NO cout<<"NO"
#define Umap unordered_map
#define Uset unordered_set
template<typename T>
vector<T> uniq(vector<T>& v){
    Uset<T> s(v.begin(),v.end());
    return vector<T>(s.begin(),s.end());
}
struct phash{
    template<typename T1,typename T2>
    size_t operator() (const pair<T1,T2> &p) const{
        size_t h1=hash<T1> {} (p.F);
        size_t h2=hash<T2> {} (p.S);
        return h1^h2<<3;
    }
};
struct vhash
{
    template <typename T>
    size_t operator()(const vector<T> &v) const
    {
        size_t x = 0;
        for (int i = 0; i < v.size(); i++)
            x ^= (std::hash<T>{}(v[i]) << min(i,15L));
        return x;
    }
};

int numCon(int i,auto & adj,auto & vis){
    vis[i] = true;
    int tot = 1;
    for (int p : adj[i])
    {
        if (!vis[p])
            tot += numCon(p, adj, vis);
    }
    vis[i] = false;
    return tot;
}

void helper(){
  int n,k;
  cin>>n>>k;
  map<pair<int,int>,int> count;
  vector<vector<int>> adj(n);
  vector<pair<int,int>> edges;
  int p,q;
  for(int i=0;i<n-1;i++){
    cin>>p>>q;
    adj[p-1].push_back(q-1);
    adj[q-1].push_back(p-1);
   // edges.push_back({p-1,q-1});
  }
    vector<bool> visited(n,false);

    for (int i = 0; i < n; i++)
    {
        for (int t = 0; t < adj[i].size(); t++)
        {
            int e = adj[i][t];
            if (count.find({i, e}) == count.end() && count.find({e, i}) == count.end())
            {
                adj[i].erase(adj[i].begin() + t);
                ll z = find_v(adj[e], i) - adj[e].begin();
                adj[e].erase(adj[e].begin() + z);
                int p = numCon(i, adj, visited);
                int q = min(p, numCon(e, adj, visited));
                count[{i,e}]=min(p,q);
                if(min(p,q)>M){
                    M=min(p,q);
                    s=i;d=e;
                }
                adj[i].insert(adj[i].begin() + t, e);
                adj[e].insert(adj[e].begin() + z, i);
            }
        }
    }

    while(k--){

    }



  
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