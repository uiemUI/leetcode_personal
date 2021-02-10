
class LRUCache {
private:
    size_t _capacity;
    list<pair<int,int>> _dataList;
   // unordered_map<int,
    unordered_map<int,list<pair<int,int>>::iterator> _keyTable; // 
public:
    LRUCache(int capacity): _capacity(capacity){
        _keyTable.reserve(_capacity); // 减少reallocate
    }
    
    int get(int key) {
        auto it = _keyTable.find(key);
        if(it!=_keyTable.end()){
            auto val = (it->second)->second; // list里的pair的 value  list<key,value>
            // 更新 _dataList，把 get的key 那一条数据移到最前面，最新访问的数据放在最前面
            _dataList.erase(it->second); // 先删除
            _dataList.emplace_front(key, val); // 再在list最前端插入该条记录
            _keyTable[key]=_dataList.begin(); // 更新索引的 value
            return val;

        }
        return -1;


    }
    
    void put(int key, int value) {
        auto it= _keyTable.find(key);
        if(it!= _keyTable.end()){  // 如果已存在该键 ，与get类似
            _dataList.erase(it->second);
            _dataList.emplace_front(key,value);
            _keyTable[key]=_dataList.begin();

        }
        else{
            //如果key不存在需要插入一条记录
            if(_dataList.size()>=_capacity) // 如果超出预计容量，则删除最久未使用的记录
            {
                auto erasedKey = _dataList.back().first;
                _keyTable.erase(erasedKey); // 删除最久未使用的记录
                _dataList.pop_back();
            }
            _dataList.emplace_front(key,value); // 放在最前面
            _keyTable.emplace(key,_dataList.begin());

        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
