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
#define fdiv(a, b) ((double)(a) / (b))
#define fceil(a, b) (ceil(fdiv(a, b)))
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
#define scan(v)           \
    {                     \
        for (auto &i : v) \
        {                 \
            cin >> i;     \
        }                 \
    }
#define print(v)              \
    {                         \
        cout << endl;         \
        for (auto &i : v)     \
        {                     \
            cout << i << " "; \
        }                     \
        cout << endl;         \
    }
#define contains(M, k) M.find(k) != M.end()
#define initdp(dp) memset(dp, -1, sizeof(dp))
#define init_v(arr, start) iota(arr.begin(), arr.end(), start)
#define isodd(x) (x & 1)
#define iseven(x) (!isodd(x))
#define b_search(a, x) binary_search(a.begin(), a.end(), x)
#define _strcmp(s1, s2) strcmp(s1.data(), s2.data())
#define lb(a, x) lower_bound(a.begin(), a.end(), x)
#define ub(a, x) upper_bound(a.begin(), a.end(), x)
#define lbi(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define ubi(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
#define isclose(a, b) (abs((a) - (b)) < 1e-9)
#define sum(a, start) accumulate(a.begin(), a.end(), start)
#define psum(a, i, start) accumulate(a.begin(), a.begin() + i, start)
#define sum_ap(a) (a.size() / 2 * (a[0] + a.back()))
#define sum_gp(a) ((a.back() * (a[1] / a[0]) - a[0]) / ((a[1] / a[0]) - 1))
#define ndigs(a, b) floor(log((long double)a) / log((long double)b) + 1)
#define elz(s) (s.erase(s.begin(), find_v(s, '1')))
template <typename T1, typename T2>
void pxsum(vector<T1> &v, vector<T2> &arr)
{
    v[0] = arr[0];
    for (int k = 1; k < arr.size(); k++)
    {
        v[k] = v[k - 1] + arr[k];
    }
}
string binary(auto &a)
{
    assert(a >= 0);
    string s = bitset<128>(a).to_string();
    elz(s);
    return s;
}
struct phash
{
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        size_t h1 = hash<T1>{}(p.F);
        size_t h2 = hash<T2>{}(p.S);
        return h1 ^ h2 << 3;
    }
};

struct vhash
{
    template <typename T>
    size_t operator()(const vector<T> &v) const
    {
        size_t x = 0;
        for (int i = 0; i < v.size(); i++)
        {
            x ^= (std::hash<T>{}(v[i]) << i);
        }
        return x;
    }
};

class TreeNode
{
public:
    int val;
    vector<TreeNode *> children;
    TreeNode(int v) : val(v) { children.push_back(nullptr); }
    TreeNode *construct(auto &arr, int i)
    {
        if (arr[i].size() == 0)
            return new TreeNode(i);
        TreeNode *node = new TreeNode(i);
        for (int &x : arr[i])
        {
            auto p = node->construct(arr, x);
            if (p)
            {
                node->children.push_back(p);
                if (node->children.front() == nullptr)
                {
                    node->children.erase(node->children.begin());
                }
            }
        }
        return node;
    }
};

int getlen(TreeNode *root, int k, int lvl)
{
    if (!root)
        return -1;
    vll t;
    ll M = LONG_MIN;
    for (auto &x : root->children)
    {
        ll temp = 1ll + getlen(x, k, lvl + 1);
        t.push_back(temp);
        M = max(M, temp);
    }
    if (k && lvl == 0)
    {
        sort_r(t);
        ll s = 0, i = 0;
        while (k && i < t.size())
        {
            s += t[i++];
            k--;
        }
        if (i < t.size())
            s += t[i++];
        for (; i < t.size(); i++)
            s += t[i] * 2;

        return s;
    }
    else
    {
        M = M == LONG_MIN ? 0 : M;
        return sum(t, 0ll) * 2 - M;
    }
}

void helper()
{
    ll n, k;
    cin >> n >> k;
    vll arr(n - 1);
    scan(arr);
    vector<vector<int>> v(n);
    for (int i = 0; i < n - 1; i++)
    {
        int ansc = arr[i] - 1;
        v[ansc].push_back(i + 1);
    }
    TreeNode *t = new TreeNode(-1);
    TreeNode *root = t->construct(v, 0);
    cout << getlen(root, k, 0);
}

signed main()
{

    int t = 1;
    while (t--)
    {
        helper();
        cout << endl;
    }
    return 0;
}