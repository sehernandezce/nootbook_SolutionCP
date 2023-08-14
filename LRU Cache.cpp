/*
Problem name: 146. LRU Cache
Algorithm or Logic: 
Complexity: O(1) Query
Link: https://leetcode.com/problems/lru-cache/description/
More info:
*/

class LRUCache {
private:
    static const int mxSize = 10005;
    int currCapacity = 0, myCapacity = 0;
    int myCache[mxSize], lNei[mxSize], rNei[mxSize];
    int first = 0, last = mxSize - 1;
    

public:
    LRUCache(int capacity) {
        memset(myCache, -1, sizeof myCache);
        for(int i = 0; i < mxSize; i++) {lNei[i] = -2; rNei[i] = -2;}
        myCapacity = capacity;
        currCapacity = 0;
    }
    
    void updatePriority(int key){
        
        if(key == last) return;
        if(currCapacity == 1){
            first = last = key;
            lNei[key] = 0;
            rNei[key] = mxSize - 1;
            return;
        }
        if(myCache[key] != -1){
            int l = lNei[key], r = rNei[key];
            lNei[r] = l;
            rNei[l] = r;
        }

        if(key == first){
            int r = rNei[first];
            lNei[r] = 0;
            first = r;
        }
        rNei[key] = mxSize - 1;
        lNei[key] = last;
        rNei[last] = key;
        last = key;
        return;
    }

    int get(int key) {
        key++;
        if(myCache[key] != -1) updatePriority(key);
        return myCache[key];  
    }
    
    void put(int key, int value) {
        key++;
        if(myCache[key] != -1){
            updatePriority(key);
            myCache[key] = value;
            return;
        }
        if(currCapacity + 1 > myCapacity){
            int r = rNei[first];
            
            lNei[first] = -2;
            rNei[first] = -2;
            myCache[first] = -1;
            currCapacity--;

            if(currCapacity >= 1){
                lNei[r] = 0;
                first = r;
            }
        }
        currCapacity++;
        updatePriority(key);
        myCache[key] = value;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */