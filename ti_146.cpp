/**
 * @file ti_146.cpp
 * @author zhuchuang (zhuchuang526@qq.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief 
 * 146. LRU 缓存机制
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

 

示例：

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
 
 * 
 */

/**
 * @brief 
 * 缓存删除最久未使用的数据。为了实现删除、插入等操作为常数时间，使用双向链表 list 。 
 * 同时为了随机访问数据，实现get的常数时间操作，使用 hashtable ，key 为索引，value 则为链表节点的地址。 从而能在常数时间内访问到链表节点。
 */

#include"stand.h"


class LRUCache {
private:
    size_t _capacity;
    list<pair<int,int>> _dataList;
   // unordered_map<int,
    unordered_map<int,list<pair<int,int>>::iterator> _keyTable; // 
public:
    LRUCache(int capacity): _capacity(capacity){
        _keyTable.reserve(2*_capacity); // 减少reallocate
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