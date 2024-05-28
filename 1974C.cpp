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
struct phash{
    template<typename T1,typename T2>size_t operator() (const pair<T1,T2> &p) const{
        size_t h1=hash<T1> {} (p.F);size_t h2=hash<T2> {} (p.S);return h1^h2<<3;}
};

#define ll long long
class Solution
{
public:
    int MOD = (int)1e9 + 7;
    ll maxSum(auto &arr, auto &t)
    {
        int n = arr.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return max(arr[0], 0L);

        ll include = arr[0];
        ll exclude = 0;
        t.clear();
        if (include > exclude)
        {
            t.insert(0);
        }
        for (int i = 1; i < n; i++)
        {
            ll prevInclude = include;
            include = exclude + arr[i];
            exclude = max(prevInclude, exclude);
            if (include > exclude)
            {
                if (t.size() && t.find(i - 1) != t.end())
                    t.erase(i - 1);
                t.insert(i);
            }
        }
        return max(include, exclude);
    }

    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        ll ans = 0;
        unordered_set<int> part;
        ll cur = maxSum(nums, part) % MOD;
        for (int i : part)
            cout << i << "  ";
        cout << endl;
        for (auto q : queries)
        {
            int i = q[0], x = q[1];
            nums[i] = x;
            if (part.find(i) != part.end())
                cur = maxSum(nums, part);
            ans += cur % MOD;
            ans %= MOD;
        }
        return (int)ans % MOD;
    }
};

void helper(){
  int n;
  cin>>n;
  vi arr(n);
  scan(arr);
    map<pair<pair<int,int>,int>,int> cnt,cnt2;
    int v1,v2,v3,t1,t2,t3;
  for(int i=0;i<n-2;i++){
      t1 = arr[i];
      t2 = arr[i + 1];
      t3 = arr[i + 2];
      pair<pair<int, int>, int> p2 = {{t1, t2}, t3};
      cnt2[p2]++;
      for (int j = i; j < i + 3; j++)
      {
          v1 = arr[i];
          v2 = arr[i + 1];
          v3 = arr[i + 2];
          if (j == i)
              v1 = -1;
          else if (j == i + 1)
              v2 = -1;
          else
              v3 = -1;
          pair<pair<int, int>, int> p = {{v1, v2}, v3};
          cnt[p]++;
        }
  }
    ll ans=0;
    for (int i = 0; i < n - 2; i++)
    {
        t1 = arr[i];
        t2 = arr[i + 1];
        t3 = arr[i + 2];
        pair<pair<int, int>, int> p2 = {{t1, t2}, t3};
        int v=cnt2[p2];
        for (int j = i; j < i + 3; j++)
        {
            v1 = arr[i];
            v2 = arr[i + 1];
            v3 = arr[i + 2];
            if (j == i)
                v1 = -1;
            else if (j == i + 1)
                v2 = -1;
            else
                v3 = -1;
            pair<pair<int, int>, int> p = {{v1, v2}, v3};
            int z=cnt[p];
            if(z){
                //cnt[p]=0;
                ans+=(z-1)-(v-1);
            }
        }
    }

    cout<<ans/2;
}

signed main()
{
    Solution s;
    vector<long> nums={3,5,9};
    vector<vector<long>> q = { { 1, -2} , {0, -3} } ;
    s.maximumSumSubsequence(nums,q);
}