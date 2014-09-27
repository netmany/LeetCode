/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations:
get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present.
When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/


class LRUCache{
    map<int, int> m;
    list<int> q;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        map<int, int>::iterator i = m.find(key);
        if(i == m.end()) return -1;
        else {
            q.erase(find(q.begin(), q.end(), key));
            q.push_front(key);
            return i->second;
        }
    }
    
    void set(int key, int value) {
        map<int,int>::iterator i = m.find(key);
        if(i == m.end()){
            if(q.size() == cap && q.size() != 0){
                m.erase(m.find(q.back()));
                q.pop_back();
            }
            m.insert(map<int, int>::value_type(key, value));
        } else {
            i->second = value;
            q.erase(find(q.begin(), q.end(), key));
        }
        q.push_front(key);
    }
};
