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
#define line(s) {ignore;getline(cin,s);}
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

struct chash{
    static const uint64_t splitmix64( uint64_t x){
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);}
    template <typename T>size_t operator()(const T x) const{
        uint64_t t=hash<T> {} (x);
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(t + FIXED_RANDOM);}
};
struct phash{   // use only upto 1e5
private:
    static struct chash* hash;
public:
    phash(){hash=new struct chash();}
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2> &p) const{
        size_t h1=(*hash)(p.F);size_t h2=(*hash)(p.S);return h1^h2<<3;}
};
struct chash *phash::hash = nullptr;

void helper()
{
    int n;
    cin >> n;
    vi k(n);
    scan(k);

    int tot = (int)1e9, lim = tot;
    vi ans;
    for (int i : k)
    {
        int bet = lim / i + 1;
        if (tot < bet)
        {
            cout << -1;
            return;
        }
        tot -= bet;
        ans.push_back(bet);
    }
    for (int i : ans)
    {
        cout << i << ' ';
    }
}

class Solution
{
public:
    int getMax(int i, int cur, auto &rew, auto &dp)
    {
        if (i >= rew.size() || cur > rew.back())
            return 0;
        if (dp.find({i, cur}) != dp.end())
            return dp[{i, cur}];
        if (rew[i] <= cur)
            return dp[{i, cur}] = getMax(i + 1, cur, rew, dp);
        int iftake = cur + rew[i];
        int pos = lower_bound(rew.begin() + i, rew.end(), iftake) - rew.begin();
        // if(pos<rew.size())cout<<rew[pos]<<"  ";
        return dp[{i, cur}] = max(rew[i] + getMax(pos, iftake, rew, dp), getMax(i + 1, cur, rew, dp));
    }
    int maxTotalReward(vector<int> &reward)
    {
        int n = 0;
        sort(reward.begin(), reward.end());
        map<pair<int, int>, int> dp;
        int ans = getMax(0, 0, reward, dp);
        return ans;
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    Solution s;
    while (t--){
        int n,k;
        cin>>n>>k;
        s.valueAfterKSeconds(n,k);
        cout << endl;
    }
    return 0;
}