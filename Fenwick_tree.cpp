#include <bits/stdc++.h>
using namespace std;
template<typename T>class FenwickTree{
private:
    int size;
    vector<int64_t> nums,ans;
    
    void prefix_sum(){
        for(int i=1;i<size;i++)
            nums[i]=nums[i-1]+nums[i];
    }

    void init(){
        for(int i=1;i<size;i++){
            int lsb= i&-i;
            int left= i-lsb;
            int64_t curRangeVal= left>=1? nums[i]-nums[left]:nums[i];
            ans.push_back(curRangeVal);
        }
    }

    int64_t getSum(int i){
        if(i<1) return 0;
        int64_t sum=0;
        while(i>=1){
            sum+=ans[i];
            i-=i&-i;
        }
        return sum;
    }

public:
    FenwickTree(const vector<T>& arr){
        size=arr.size()+1;
        ans.reserve(size);
        nums.reserve(size);
        ans.push_back(0);
        nums.push_back(0);
        for(int i=1;i<size;i++)
            nums.push_back(static_cast<T> (arr[i-1]));
        prefix_sum();
        init();
    }

    void update(int i,int64_t change){  //provide difference newval-oldval
        i++;
        if(i<1||i>=size)
            throw out_of_range("index out of range!");
        while(i<size){
            ans[i]+=change;
            i+=i&-i;
        }
    }

    int64_t rangeSum(int l,int r){  //inclusive range sum [l,r]
        l++;r++;
        if(l<1 || r>=size|| l>r)
            throw out_of_range("Invalid range!");
        return getSum(r) - getSum(l - 1);
    }
};

int main(){
    srand(time(0));
    vector<int> arr(25);
    iota(arr.begin(),arr.end(),1);
    for(int i:arr){
        cout<<i<<"  ";
    }
    cout<<endl;
    FenwickTree F(arr);
    int l,r;
    for(int i=0;i<15;i++){
        cout<<"Enter l r: ";
        cin>>l>>r;
        cout<<F.rangeSum(l,r)<<"  ";
        int64_t s=0;
        for(int i=l;i<=r;i++)
            s+=arr[i];
        cout<<"Got: "<<s<<endl;
        int ind=rand()%25,val=rand()%100;
        cout<<"Updating "<<ind<<" with "<<val<<endl;
        F.update(ind,val-arr[ind]);
        arr[ind]=val;
    }
    
}