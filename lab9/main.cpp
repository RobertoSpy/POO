#include<iostream>

using namespace std;

template<typename K, typename V, long long N>
class Map
{
  private:
  struct pair
  {
    K key;
    V value;
  };
  pair pairs[N];
  long long size=0;


public:

 void Set(K &key, V &value)
 {
  auto i;
  for( i=0;i<size;i++)
  
    if(pairs[i].key==key)
    {
     pairs[i].value=value;
     return;
    }
      pairs[size].key = key;
        pairs[size].value = value;
        size++;
  
 }

bool Get( K &key, V &value, size)
  {
    for(auto i=0;i<size;i++)
    {
      if(pairs[i].key==key)
       value=pairs[i].value;
       return true;
    }

       return false;
  }

  long long Count()
  {
    return size;

  }

  void Clear()
  {
    size=0;
  }

  bool Delete(K &key, V &value)
  {
    for(auto i=0;i<size;i++)
    if(pairs[i].key==key)
    {
       for(auto j=i;j< size-1;j++)
        pairs[j]=pairs[j+1];
        size--;
        return true;
    }
    return false;
  }

  bool Include(Map<K, V, size> &altamapa)
  {
    for(auto i=0;i<altamapa.Count();i++)
      {
        auto da=false;
        for(auto j=0;j<size;j++)
        {
          if(pairs[j].key==altamapa[i].key)
            da=true;
        }
      if (da==false)
      return false;
      }
      return true;
  }

   V& operator[](K &key)
    {
        for (auto i = 0; i <size; i++) {
            if (pairs[i].key == key) {
                return pairs[i].value;
            }
        }
        /
        pairs[size].key = key;
        size++;
        return pairs[size - 1].value;
    }
};

  

  int main()
{
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto[key, value, index] : m)
    
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    
    return 0;
}
