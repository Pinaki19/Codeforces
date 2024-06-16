#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a;
        vector<int> b;

        for (int i = 0; i < n; i++)
        {
            int e1;
            cin >> e1;
            a.push_back(e1);
        }

        unordered_map<int, int> check;

        for (int i = 0; i < n; i++)
        {
            int e2;
            cin >> e2;
            check[e2] = 1;
            b.push_back(e2);
        }

        int m;
        cin >> m;

        vector<int> d;

        for (int i = 1; i <= m; i++)
        {
            int e3;
            cin >> e3;
            d.push_back(e3);
        }

        unordered_map<int, int> ump;
        int mod = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
            {
                continue;
            }
            else
            {
                ump[b[i]]++;
                mod++;
            }
        }

        int f = 1;

        for (int i = 0; i < m; i++)
        {
            if (mod == 0)
            {

                if (check[d[i]] == 1)
                {
                    f = 1;
                }
                else
                {
                    f = 0;
                }
            }
            else
            {

                if (ump[d[i]] == 0)
                {
                    continue;
                }
                else
                {
                    ump[d[i]]--;
                    mod--;
                }
            }
        }

        if (f == 1)
        {
            if (mod != 0)
            {
                f = 0;
            }
            else
            {
                f = 1;
            }
        }

        if (f == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}