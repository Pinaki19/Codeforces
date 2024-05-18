#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long long double
#define sort_n(a) (sort(a.begin(), a.end()))
#define sort_r(a) (sort(a.begin(), a.end(), grreater<int>()))
#define push(x) (push_back(x))
#define find(a, x) (find(a.begin(), a.end(), x))
#define erase(a, x) (erase(find(a, x)))
#define max3(a, b, c) (max(a, max(b, c)))
#define max4(a, b, c, d) (max(a, max3(b, c, d)))
#define min3(a, b, c) (min(a, min(b, c)))
#define min4(a, b, c, d) (min(a, min3(b, c, d)))
#define scan(v, n) ({for(auto&i:v) {cin>>i;} })

void helper()
{
    int h, x, y1, y2, k;
    cin >> h >> x >> y1 >> y2 >> k;
    int t1 = ceil(h / x), t2;
    if ((h - y1 * k) < 0)
        t2 = ceil(floh / y1);
    else
        t2 = k + ceil((h - y1 * k) / y2);
    cout << min(t1, t2);
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