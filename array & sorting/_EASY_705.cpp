#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
private:
    std::vector<bool> mp;

public:
    MyHashSet() {
        mp.resize(1000001, false);
    }

    void add(int key) {
        mp[key] = true;
    }

    void remove(int key) {
        mp[key] = false;
    }

    bool contains(int key) {
        return mp[key];
    }
};

int main(){
    MyHashSet hashSet;
    hashSet.add(1);
    hashSet.add(2);
    cout<<hashSet.contains(1)<<endl;
    cout<<hashSet.contains(3)<<endl;
    hashSet.remove(2);
    cout<<hashSet.contains(2)<<endl;
    return 0;
}