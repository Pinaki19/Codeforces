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
#define sort_r(a) sort(a.begin(), a.end(), grreater<int>())
#define push(x) push_back(x)
#define find_v(a, x) find(a.begin(), a.end(), x)
#define erase_v(a, x) erase(find_v(a, x))
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
#define lb(a,x) lower_bound(a.begin(),a.end(),x)
#define ub(a,x) upper_bound(a.begin(),a.end(),x)
#define lbi(a,x) (lower_bound(a.begin(),a.end(),x)-a.begin())
#define ubi(a,x) (upper_bound(a.begin(),a.end(),x)-a.begin())
#define isclose(a,b) (abs((a)-(b))<1e-9)
#define sum(a,start) accumulate(a.begin(),a.end(),start)
#define psum(a,i,start) accumulate(a.begin(),a.begin()+i,start)
#define sum_ap(a) (a.size()/2 *(a[0]+a.back()))
#define sum_gp(a) ((a.back()*(a[1]/a[0])-a[0])/((a[1]/a[0])-1))
#define ndigs(a,b) floor(log((long double)a)/log((long double)b)+1)

struct phash{
    template<typename T1,typename T2>
    size_t operator() (const pair<T1,T2> &p) const{
        size_t h1=hash<T1> {} (p.F);
        size_t h2=hash<T2> {} (p.S);
        return h1^h2<<3;
    }
};

class Dll{
public:
    int atk,def;
    Dll* next,*prev;
    Dll(int a,int d,Dll* prev): atk(a),def(d),prev(prev),next(nullptr) {}
};

void helper(){
    int n;
    cin>>n;
    vi atk(n),def(n);
    scan(atk);scan(def);
    Dll* head=new Dll(atk[0],def[0],nullptr);
    Dll* t=head;
    for(int i=1;i<n;i++){
        t->next=new Dll(atk[i],def[i],t);
        t=t->next;
    }
    int c=0,prevd;
    bool flag=0;
    int i=0;
    for(;i<n;i++){
        t = head;
        flag=0;
        prevd=0;
        c=0;
        while(t){
            int t2= t->next? t->next->atk:0;
            int total=prevd+t2;
            prevd=t->atk;
            if(total>t->def){
                if(!fd)
                flag=1;
                c++;
                if(t->prev)
                    t->prev->next=t->next;
                else
                    head=t->next;
                if(t->next)
                    t->next->prev=t->prev;
            }
            t=t->next;
        }
        if(!flag)
            break;
        cout<<c<<" ";
    }
    for(;i<n;i++)
        cout<<0<<" ";
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