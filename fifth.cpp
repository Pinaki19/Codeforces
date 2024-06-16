#include <bits/stdc++.h>
using namespace std;
void helper(char * val){
    cout<<1<<'\n';
    int lim=80000;
    cout<<lim<<endl;
    for(int i=0;i<lim;i++){
        cout<<val<<' ';
    }
    cout<<endl;
    for (int i = 0; i < lim; i++)
    {
        cout << val << ' ';
    }
    cout << endl;
    cout << lim << endl;
    for (int i = 0; i < lim; i++)
    {
        cout << val << ' ';
    }
    cout << endl;
}

int main(int argc,char** argv)
{
    helper(argv[1]);
}