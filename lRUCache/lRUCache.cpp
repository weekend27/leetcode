// Source : https://leetcode.com/problems/lru-cache/
// Author : weekend27
// Date   : 2016-01-04

/**********************************************************************************

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

**********************************************************************************/

// How to do it:
// ref: http://fisherlei.blogspot.com/2013/11/leetcode-lru-cache-solution.html
/*
首先，对于cache，如果希望有O(1)的查找复杂度，肯定要用hashmap来保存key和对象的映射。对于LRU而言，问题在于如何用O(1)解决cache entry的替换问题。

简单的说，cache的存储是一个链表的话，那么只要保证从头到尾的顺序就是cache从新到旧的顺序就好了，对于任何一个节点，如果被访问了，那么就将该节点移至头部。如果cache已满，那么就把尾部的删掉，从头部插入新节点。

所以，需要用到两个数据结构

1. hashmap， 保存key和对象位置的映射

2. list，保存对象新旧程度的序列。不一定是list，也可以用vector，不过list的好处是已经实现了头尾操作的api，vector的话，还要自己写，麻烦。
*/

class LRUCache{
public:
    struct CacheEntry
    {
    public:
        int key;
        int value;
        CacheEntry(int k, int v): key(k), value(v) {}
    };

    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        if (m_map.find(key) == m_map.end()) {
            return -1;
        }

        MoveToHead(key);
        return m_map[key]->value;
    }

    void set(int key, int value) {
        if (m_map.find(key) == m_map.end()) {
            CacheEntry newItem(key, value);
            if (m_LRU_cache.size() >= m_capacity) {
                // remove from tail
                m_map.erase(m_LRU_cache.back().key);
                m_LRU_cache.pop_back();
            }

            // insert in head
            m_LRU_cache.push_front(newItem);
            m_map[key] = m_LRU_cache.begin();
            return;
        }

        m_map[key]->value = value;
        MoveToHead(key);
    }

private:
    unordered_map<int, list<CacheEntry>::iterator> m_map;
    list<CacheEntry> m_LRU_cache;
    int m_capacity;

    void MoveToHead(int key) {
        // Move key from current position to head
        auto updateEntry = *m_map[key];
        m_LRU_cache.erase(m_map[key]);
        m_LRU_cache.push_front(updateEntry);
        m_map[key] = m_LRU_cache.begin();
    }
};
