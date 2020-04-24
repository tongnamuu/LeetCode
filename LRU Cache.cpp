class LRUCache {
   public:
    list<int> keys;
    map<int, int> m;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        keys = list<int>();
        m = map<int, int>();
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            keys.remove(key);
            keys.push_back(key);
            return m[key];
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            m.erase(key);
            keys.remove(key);
        }
        if (keys.size() == cap) {
            m.erase(keys.front());
            keys.pop_front();
        }
        m[key] = value;
        keys.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */