class RandomizedCollection {
public:
    vector<int>arr;
    unordered_map<int, unordered_set<int>>mp;

    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()){
            arr.push_back(val);
            mp[val].insert(arr.size() - 1);
            return false;
        }
        arr.push_back(val);
        mp[val].insert(arr.size() - 1);
        return true;
    }
    
    bool remove(int val) {
        
        auto it = mp.find(val);
        if (it == mp.end()) return false;

        int idxNo = *it->second.begin();
        int lastIdx = arr.size() - 1;
        int last = arr[lastIdx];

        it->second.erase(idxNo);

        if (idxNo != lastIdx) {
            arr[idxNo] = last;
            mp[last].erase(lastIdx);
            mp[last].insert(idxNo);
        }

        arr.pop_back();

        if (it->second.empty()) mp.erase(it);
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */