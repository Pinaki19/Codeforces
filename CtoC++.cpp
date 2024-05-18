
#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
private:
    int timestamp, capacity;
    unordered_map<int, pair<int, int>> mapping;
    static bool compare(const int &k1, const int &k2, unordered_map<int, pair<int, int>> &m)
    {
        return m[k1].second > m[k2].second;
    }
    set<int, function<bool(int, int)>> s{bind(LRUCache::compare, placeholders::_1, placeholders::_2, this->mapping)};

public:
    LRUCache(int capacity) : capacity(capacity), timestamp(1)
    {
        
    }

    int get(int key)
    {
        if (mapping.find(key) == mapping.end())
            return -1;
        int val = mapping[key].first;
        s.erase(key);
        mapping[key] = {val, timestamp++};
        s.insert(key);
        return val;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
        {
            int oldest = *s.begin();
            s.erase(s.begin());
            mapping.erase(oldest);
            capacity++;
        }
        capacity--;
        mapping[key] = {value, timestamp++};
        s.insert(key);
        print(s);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LRUCache L(2);
    L.put(1,1);
    L.put(2,2);
    cout<<L.get(1);

}
