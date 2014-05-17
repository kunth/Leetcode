class LRUCache{
private:
    list<int>lrulist;
    unordered_map<int, int>dm;
    unordered_map<int, list<int>::iterator>list_it_map;
    unordered_map<int, int>::iterator dmit;
    unordered_map<int, list<int>::iterator>::iterator mapit;
    int capacity;
public:
    LRUCache(int capacity) {
        lrulist.clear();
        dm.clear();
        this->capacity = capacity;
    }
    
    int get(int key) {
        dmit = dm.find(key);
        mapit = list_it_map.find(key);
        if(dmit!=dm.end())
        {
            lrulist.splice(lrulist.begin(), lrulist, mapit->second);
            return dmit->second;
        }
        return -1;
    }
    
    void set(int key, int value) {
        dmit = dm.find(key);
        mapit = list_it_map.find(key);
        if(dmit == dm.end())
        {
            if(lrulist.size()==capacity)
            {
                dmit = dm.find(lrulist.back());
                dm.erase(dmit);
                mapit = list_it_map.find(lrulist.back());
                list_it_map.erase(mapit);
                lrulist.pop_back();
            }
            dm[key] = value;
            lrulist.push_front(key);
            list_it_map[key] = lrulist.begin();
            
        }
        else
        {
            dm[key] = value;
            lrulist.splice(lrulist.begin(), lrulist, mapit->second);
        }
    }
};
