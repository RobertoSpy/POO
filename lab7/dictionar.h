
#include <string>
#include <crc32>

using namespace std;

template<typename Key, typename Value>

class Dictionar
 {
     private:
    const int TABLE_SIZE = 100; 

    pair<Key, Value> table[TABLE_SIZE]; 

    long long hash(const Key& key) const 
    {
        return crc32(key.c_str(), key.length()) % TABLE_SIZE;
      }

public:
    
    Value& operator[](const Key& key)
     {
        long long index = hash(key);
        return table[index].second;
    }

    
};
