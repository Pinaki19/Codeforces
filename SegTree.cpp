#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int ans[(int)1e1+10];
void build(auto& arr,int i,int l,int r){
    if(l>r)
        return;
    if(l==r){
        ans[i]=arr[l];
        return;
    }
    int mid=l+(r-l)/2;
    build(arr,2*i+1,l,mid);
    build(arr,2*i+2,mid+1,r);
    ans[i]=ans[2*i+1]+ans[2*i+2];
}

long getSum(int i,int left,int right,int l,int r){
    if(left>right || left==right && (left<l ||left>r))
        return 0;
    if(left>=l && right<=r || left==right)
        return ans[i]*1L;
    else if(left>r || right<l)
        return 0;
    int mid=left+(right-left)/2;
    long leftSum=getSum(2*i+1,left,mid,l,r);
    long rightSum=getSum(2*i+2,mid+1,right,l,r);
    return leftSum+rightSum;
}

void increase(int ind,int i,int left,int right,int change){
    if (i < left || i > right || left > right)
        return;
    else if(left==right){
        if (i == left)
            ans[ind] = ans[ind] + change;
        return;
    }
    if(i>=left && i<=right){
        ans[ind]=ans[ind]+change;
    }
    int mid=left+(right-left)/2;
    increase(2*ind+1,i,left,mid,change);
    increase(2*ind+2,i,mid+1,right,change);
}

int main(){
    fill(ans,ans+110,0);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int &i:arr)
        cin>>i;
    build(arr,0,0,n-1);
    for(int &i:ans){
        cout<<i<<"   ";
    }
    cout<<endl;
    int k;
    cout<<"Give K: ";
    cin>>k;
    for(int i=0;i<k;i++){
        int x;
        cout<<"Give choice: ";
        cin>>x;
        if(x==0){
            int l,r;
            cout<<"Give l,r: ";
            cin>>l>>r;
            cout<<getSum(0,0,n-1,l,r)<<endl;
        }else{
            int i,c;
            cout<<"Give i,c : ";
            cin>>i>>c;
            int change=(c-arr[i]);
            cout<<change<<endl;
            arr[i]=c;
            for (int &i : arr)
            {
                cout << i << "   ";
            }
            cout<<endl;
            increase(0,i,0,n-1,change);
            for (int &i : ans)
            {
                cout << i << "   ";
            }
            cout << endl;
        }
    }
    return 0;
}