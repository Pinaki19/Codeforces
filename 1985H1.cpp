#include <bits/stdc++.h>
#include <iostream>
using namespace std;
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
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs (int i, int j,auto& grid,int n,int m,auto& par,auto& sz)
{
    auto isvalid = [&n, &m,i,j](int x, int y) -> bool{
        return x >= 0 && x < n && y >= 0 && y < m && x!=i && y!=j;
    };
    queue<pair<int, int>> q;
    q.push({i, j});
    while (q.size())
    {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : dir)
        {
            int nx = x + dx, ny = y + dy;
            cout << dx << "  " << dy <<"  "<< endl;
            if (isvalid(nx, ny) && grid[nx][ny] == '#' && sz[nx][ny])
            {
                cout<<nx<<"  "<<ny<<endl;
                par[nx][ny] = {i, j};
                sz[i][j]+=1;
                sz[nx][ny]=0;
                q.push({nx,ny});
            }
        }
    }
}

void helper(){
    int n,m;
    cin>>n>>m;
    vector<string> grid;
    string s;
    ignore;
    for(int i=0;i<n;i++){
        getline(cin,s);
        grid.pb(s);
    }

    vector<vector<pair<int,int>>> par(n,vector<pair<int,int>> (m));
    vector<vector<int>> sz(n,vector<int>(m,1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            par[i][j]={i,j};
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << sz[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='#' && par[i][j]==make_pair(i,j)){
                bfs(i,j,grid,n,m,par,sz);
            }
            if(grid[i][j]=='.') sz[i][j]=0;
        }
    }
    
    int ans=0;
    for (int j = 0; j < m; j++)
    {
        int rinc=0,oinc=0,prw=0,nrw=0;
        set<pair<int,int>> p;
        for (int i = 0; i < n; i++)
        {
            if(grid[i][j]=='#'){
                if(p.find(par[i][j])==p.end()){
                    auto [tx, ty] = par[i][j];
                    oinc += sz[tx][ty];
                    p.insert(par[i][j]);
                }
            }

            if (grid[i][j] == '.'){
                rinc++;
                if(i-1>=0){
                    if(grid[i-1][j]=='#'){
                        if(p.find(par[i-1][j])==p.end()){
                            p.insert(par[i - 1][j]);
                            auto [tx, ty] = par[i - 1][j];
                            prw += sz[tx][ty];
                        }
                    }
                }
                if(i+1<n){
                    if (grid[i+1][j] == '#')
                    {
                        if (p.find(par[i+1][j]) == p.end()){
                            p.insert(par[i+1][j]);
                            auto [tx, ty] = par[i+1][j];
                            nrw += sz[tx][ty];
                        }
                    }
                }
            }
        }
        ans=max(ans,rinc+prw+nrw+oinc);
    }
    for (int i = 0; i < n; i++)
    {
        int rinc = 0, oinc = 0, prw = 0, nrw = 0;
        set<pair<int, int>> p;
        for (int j = 0; j < m; j++ )
        {
            if (grid[i][j] == '.')
                rinc++;
            else
            {
                if (p.find(par[i][j]) == p.end())
                {
                    auto [tx, ty] = par[i][j];
                    oinc += sz[tx][ty];
                    p.insert(par[i][j]);
                }
            }

            if (grid[i][j] == '.')
            {
                if (j-1>=0)
                {
                    if (grid[i][j-1] == '#')
                    {
                        if (p.find(par[i][j-1]) == p.end())
                        {
                            p.insert(par[i][j-1]);
                            auto [tx, ty] = par[i][j-1];
                            prw += sz[tx][ty];
                        }
                    }
                }
                if (j+1 < m)
                {
                    if (grid[i][j+1] == '#')
                    {
                        if (p.find(par[i][j+1]) == p.end())
                        {
                            p.insert(par[i][j + 1]);
                            auto [tx, ty] = par[i][j + 1];
                            nrw += sz[tx][ty];
                        }
                    }
                }
            }
        }
        ans = max(ans, rinc + prw + nrw + oinc);
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << sz[i][j] << " ";
        }
        cout << endl;
    }
    //cout<<ans;
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