#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#define p pair<char, int>

template <class K, class V>
class pair {
public:
    K key;
    V value;
    pair(const K kinit, const V vinit){
        this->key = kinit;
        this->value = vinit;
    }
};

template <class K, class V>
class table {
public:
    std::vector <pair<K,V>> internal;
    std::vector <K> keys;
    std::vector <V> values;
    std::vector <pair<K,V>> get_pairs(){ return internal; }
    std::vector <K> get_keys(){ return keys; }
    std::vector <V> get_values(){ return values; }
    int size(){ return internal.size(); }
    
    template <class arg>
    void append(arg a){ this->internal.push_back(a); }
    
    template <class arg, class...args>
    void append(arg a, args...as){
        append(a);
        append(as...);
        keys = {};
        values = {};
        for (auto const &g : internal){
            keys.push_back(g.key);
            values.push_back(g.value);
        }
    }
    
    pair<K, V> operator[](int index){
        return this->internal[index];
    }
    V operator()(K index){
        return this->internal[std::distance(this->keys.begin(), std::find(this->keys.begin(), this->keys.end(), index))].value;
    }
    
    table(){
        for (auto &e : this->internal){ std::cout << e.key << "\n"; }
    }
    
    ~table(){}
};

int main(){
    table <char, int> myTable;
    myTable.append(
        p('a', 1),
        p('b', 2),
        p('c', 3)
    );
    std::cout << myTable[2].key << "\n";
    std::cout << myTable('b') << "\n";
}