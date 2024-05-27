#include <iostream>
#include <exception>
#include <algorithm>
using namespace std;


class OutException : public exception 
{
    virtual const char* what() const throw() 
    {
        return "Indexul afara";
}
};

class CapacityException : public exception
 {
    virtual const char* what() const throw()
      {
        return "Capacitatea depasita";
    }
};

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator {
   private:
    int Current; 
    T** List;
    int Size;
   public:
    ArrayIterator(T** list, int size) : List(list), Size(size), Current(0) {}

    ArrayIterator& operator++() 
     {
        if (Current < Size) Current++;
        return *this;
    }

    ArrayIterator& operator--() {
        if (Current > 0) Current--;
        return *this;
    }

    bool operator=(ArrayIterator<T>& other) 
    
    {
        return (List == other.List && Current == other.Current);
    }

    bool operator!=(ArrayIterator<T>& other) 
    
    {
        return !(*this == other);
    }

    T* GetElement() {
        if (Current < Size)
            return List[Current];
        return nullptr;
    }
};

template<class T>
class Array {
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    ~Array() {
        for (int i = 0; i < Size; ++i)
         {
            delete List[i];
        }
        delete[] List;
              }

    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T*[Capacity];
    }

    Array(const Array<T>& otherArray) : Capacity(otherArray.Capacity), Size(otherArray.Size)
     {
             List = new T*[Capacity];
        for (int i = 0; i < Size; ++i) {
            List[i] = new T(*otherArray.List[i]);
        }
    }

    T& operator[](int index)
     {
        if (index < 0 || index >= Size)
         {
            throw OutException();
        }
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) 
    {
             if (Size >= Capacity) {
            throw CapacityException();
        }
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size)
         {
            throw OutException();
        }
             if (Size >= Capacity) {
            throw CapacityException();
        }
        for (int i = Size; i > index; --i) {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) 
    {
        if (index < 0 || index > Size) {
            throw OutException();
        }
            if (Size + otherArray.Size > Capacity) {
            throw CapacityException();
        }
        for (int i = Size - 1; i >= index; --i) {
            List[i + otherArray.Size] = List[i];
          } 
        for (int i = 0; i < otherArray.Size; ++i) {
            List[index + i] = new T(*otherArray.List[i]);
        }
        Size += otherArray.Size;
        return *this;
 }

    const Array<T>& Delete(int index)
     {
        if (index < 0 || index >= Size) {
            throw OutException();
        }
        delete List[index];
        for (int i = index; i < Size - 1; ++i) {
            List[i] = List[i + 1];
        }
        Size--;
        return *this;
 }

    bool operator=(const Array<T>& otherArray) 
    {
        if (this == &otherArray) return true;
        for (int i = 0; i < Size; ++i) {
            delete List[i];
        }
        delete[] List;
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T*[Capacity];
        for (int i = 0; i < Size; ++i) {
            List[i] = new T(*otherArray.List[i]);
        }
        return true;
    }

    void Sort() {
        sort(List, List + Size, [](T* a, T* b) { return *a < *b; });
        }

    void Sort(int(*compare)(const T&, const T&)) {
        sort(List, List + Size, [compare](T* a, T* b) { return compare(*a, *b) < 0; });
    }

    void Sort(Compare* comparator) {
        sort(List, List + Size, [comparator](T* a, T* b) { return comparator->CompareElements(a, b) < 0; });
}

    int BinarySearch(const T& elem) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (*List[mid] == elem) return mid;
            if (*List[mid] < elem) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (compare(*List[mid], elem) == 0) return mid;
            if (compare(*List[mid], elem) < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) 
    {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
              if (comparator->CompareElements(List[mid], (void*)&elem) == 0) return mid;
            if (comparator->CompareElements(List[mid], (void*)&elem) < 0) left = mid + 1;
             else right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem) 
      {
            for (int i = 0; i < Size; ++i) {
            if (*List[i] == elem) return i;
        }
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; ++i) {
            if (compare(*List[i], elem) == 0) return i;
        }
        return -1;
    }

    int Find(const T& elem, Compare* comparator)
     {
         for (int i = 0; i < Size; ++i) {
              if (comparator->CompareElements(List[i], (void*)&elem) == 0) return i;
        }
         return -1;
  }

    int GetSize() 
    {
         return Size;
    }

    int GetCapacity()
     {
         return Capacity;
    }

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(List, Size);
 }

    ArrayIterator<T> GetEndIterator() {
           ArrayIterator<T> it(List, Size);
        it += Size;
        return it;
     }
};


int main() {
    Array<int> arr(10);
    arr += 2;
    arr += 3;
    arr += 9;
    arr.Insert(4, 6);

    try {
        arr.Delete(10); 
    } catch (const exception& e)
     {
        cout << "Exceptie: " << e.what() << endl;
    }

    for (int i = 0; i < arr.GetSize(); ++i) 
     {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
