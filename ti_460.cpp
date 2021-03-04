/**
 * @file ti_460.cpp
 * @author zhuchuang (zhuchuang526@qq.com)
 * @brief   LFU 缓存 ，删除使用频率最少的，若频率相同。删除最久未使用的。
 * @version 0.1
 * @date 2021-01-07
 *
 * @copyright Copyright (c) 2021
 *
 */
 /**
  *
  *请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。

 实现 LFUCache 类：

 LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
 int get(int key) - 如果键存在于缓存中，则获取键的值，否则返回 -1。
 void put(int key, int value) - 如果键已存在，则变更其值；如果键不存在，请插入键值对。
 当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最久未使用 的键。
 注意「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。

  

 进阶：

 你是否可以在 O(1) 时间复杂度内执行两项操作？
  

 示例：

 输入：
 ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
 [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
 输出：
 [null, null, null, 1, null, -1, 3, null, -1, 3, 4]

 解释：
 LFUCache lFUCache = new LFUCache(2);
 lFUCache.put(1, 1);
 lFUCache.put(2, 2);
 lFUCache.get(1);      // 返回 1
 lFUCache.put(3, 3);   // 去除键 2
 lFUCache.get(2);      // 返回 -1（未找到）
 lFUCache.get(3);      // 返回 3
 lFUCache.put(4, 4);   // 去除键 1
 lFUCache.get(1);      // 返回 -1（未找到）
 lFUCache.get(3);      // 返回 3
 lFUCache.get(4);      // 返回 4
  

 提示：

 0 <= capacity, key, value <= 104
 最多调用 105 次 get 和 put 方法

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/lfu-cache
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
  */


  /**
   * @brief 使用两个hash表，一个数_dataHash <key ,value> key是 使用频率freq, value则是相同 freq 的数据记录构成的双向链表。选择链表可以在常数时间内移动、插入、删除。
   * 因为最新访问的记录  要对应新的freq，且放在list的头部。
   * 另一个是快速索引的hashtable ，value 指向 _dataHash 数据记录的地址 list<key,value,freq>::iterator
   * 保存一个最小频率 minFreq. 而最久未使用的特性为list最后一个数
   */


#include"stand.h"
class LFUCache {
private:
    size_t _capacity;
    size_t _minFreq;
    using KVF = tuple<int, int, size_t>;
    unordered_map<size_t, list<KVF>> _dataHash; // freq,KVF
    unordered_map<int, list<KVF>::iterator> _keyTable;



public:
    LFUCache(int capacity) :_capacity(capacity), _minFreq(0) {
        _keyTable.reserve(2 * _capacity);
        _dataHash.reserve(2 * _capacity);
    }

    int get(int key) {
        if (_capacity == 0) return -1;
        auto keyIter = _keyTable.find(key);
        if (keyIter == _keyTable.end()) return -1; // 不存在这个记录，返回-1;
        auto [tempKey, val, tempFreq] = *(keyIter->second);
        _dataHash[tempFreq].erase(keyIter->second); // 删掉该条记录，更新到新的freq和list
        //如果当前freq 的list为空，删除 该freq ,并可能更新minFreq
        if (_dataHash[tempFreq].empty())
        {
            _dataHash.erase(tempFreq);
            if (_minFreq == tempFreq)
                _minFreq++; // 更新minFreq;
        }
        _dataHash[tempFreq + 1].emplace_front(tempKey, val, tempFreq + 1);
        _keyTable[key] = _dataHash[tempFreq + 1].begin();
        return val;
    }

    void put(int key, int value) {
        if (_capacity == 0) return;
        auto keyIter = _keyTable.find(key);
        // 如果不存在需要添加
        if (keyIter == _keyTable.end())
        {
            if (_keyTable.size() >= _capacity)
            { // 需要删除频率最低的，且最久未使用的，注意因为添加了一个不存在的值，则minFreq为 1
                auto [erasedKey, erasedValue, tempFreq] = _dataHash[_minFreq].back();
                _dataHash[_minFreq].pop_back();
                if (_dataHash[_minFreq].empty()) _dataHash.erase(_minFreq);
                _keyTable.erase(erasedKey); // keyTable 里也要删除key

            }
            // 新插入的频率为1
            _dataHash[1].emplace_front(key, value, 1);
            _keyTable[key] = _dataHash[1].begin();
            _minFreq = 1;

        }
        // 如果已存在该值和  get操作类似
        else {
            auto [tempKey, preVal, tempFreq] = *(keyIter->second);
            _dataHash[tempFreq].erase(keyIter->second); // 删掉该条记录，更新到新的freq和list
            //如果当前freq 的list为空，删除 该freq ,并可能更新minFreq
            if (_dataHash[tempFreq].empty())
            {
                _dataHash.erase(tempFreq);
                if (_minFreq == tempFreq)
                    _minFreq++; // 更新minFreq;
            }
            _dataHash[tempFreq + 1].emplace_front(key, value, tempFreq + 1);
            _keyTable[key] = _dataHash[tempFreq + 1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
