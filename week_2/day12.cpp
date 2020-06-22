class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> m1; // storing pair as <val,index of that val in vector(1 based)>
    int s; // current size
    vector<int> v; // for storing elements
    RandomizedSet() {
        m1.clear();
        v.clear();
        s=0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m1[val]==0) // if not present
        {
            m1[val]=s+1; // here index is stored as 1 based
            s++;
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m1[val]!=0) // if present
        {   
            m1[v[s-1]]=m1[val];// new index for swapped element
            swap(v[m1[val]-1],v[s-1]);// swap with last indexed element
            s--;
            v.pop_back();// as last element is now 'val' we poped it from vector
            m1[val]=0;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r=rand()%s;
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */