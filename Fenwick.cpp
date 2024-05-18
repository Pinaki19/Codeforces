#include <bits/stdc++.h>
using namespace std;

vector<int> ans(10000);
vector<int> psum(10000);
void shift_one(auto& arr){
    arr.push_back(0);
    for(int i=arr.size()-1;i>0;i--){
        arr[i]=arr[i-1];
    }
}

void prefix_sum(auto& arr){
    shift_one(arr);
    psum[1]=arr[1];
    for(int i=2;i<arr.size();i++)
        psum[i]=psum[i-1]+arr[i];
}

void init(int n){
    for (int i = 1; i <=n; i++)
    {
        int pk = i & -i;
        int l= i-pk+1;
        ans[i] = l>1 ? psum[i] - psum[l-1] : psum[i];
    }
}


void increase(int i,int change,int n){  // delta of change at index i
    while(i<=n){
        ans[i]+=change;
        i+= i&-i;
    }
}

long sum(int i,int n){  //sum of 1 to i
    long sum=0L;
    while(i>=1){
        sum+=ans[i];
        i-= i&-i;
    }
    cout<<" Sum : "<<sum<<endl;
    return sum;
}


int main(){
    vector<int> arr={1,3,4,5,7,9,2,4};
    prefix_sum(arr);
    int k;
    cin>>k;
    int n=arr.size();
    init(n);
    for(int i=0;i<k;i++){
        cout<<"Choice: ";
        int c;
        cin>>c;
        if(!c){
            int l,r;
            cin>>l>>r;
            long leftsum=0,rightsum=0;
            leftsum= l==1? 0: sum(l-1,n);
            rightsum=sum(r,n);
            cout<<rightsum-leftsum<<endl;
        }else{
            int i,c;
            cout<<"Index new val: ";
            cin>>i>>c;
            int change=(c-arr[i]);
            arr[i]=c;
            increase(i,change,n);
            for(int &i:arr){
                cout<<i<<"  ";
            }
            cout<<endl;
        }
    }
    return 0;
}



 