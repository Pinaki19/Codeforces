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
using namespace std;
#define ll long long

void helper()
{
    int n;
    cin >> n;
    int arr[n];
    for (int &i : arr)
        cin >> i;
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            int Gcd = 0;
            for (int j = 0; j < n - i; j++)
            {
                Gcd = gcd(Gcd, abs(arr[j] - arr[j + i]));
            }
            if (Gcd!=1)
                total++;
        }
    }
    cout << total;
}

int main()
{
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