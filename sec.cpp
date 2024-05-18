#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <set>
#include <vector>
// Uncomment below line to send network request if needed.
// #include <curl/curl.h>
using namespace std;
void getAll(auto &v, auto &st, int i, int n, string t)
{
    if (i >= n )
    {
        if(t.size()==n)
        st.insert(t);
        return;
    }
    for (char c : v[i])
    {
        getAll(v, st, i + 1, n, t + c);
    }
}
std::string your_code_goes_here()
{
    
    int n,m;
    cin>>n>>m;
    cin.ignore();
    vector<string> v;
    string s;
    for (int i = 0; i < n; i++)
    {
        getline(cin,s);
        v.push_back(s);
    }
    set<string> st;
    getAll(v, st, 0, n, "");
    string ans = "";
    vector<string> v2(st.begin(), st.end());
    for(auto s:v2){
        cout<<s<<' ';
    }
    return "";
}

int main()
{
    
    your_code_goes_here();
    return 0;
}