#include <iostream>
#include <cstdio>
#include <tuple>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
///corect
void sortareSTALIN(vector<int>& arr) 
{
    int n = arr.size();
    int index = 1; 

    for (int i = 1; i < n; ++i) 
    {
  if (arr[index - 1] > arr[i]) { 
          arr.erase(arr.begin() + i); 
          n--; 
         i--; 
        }
         else
          {
            index++; 
        }
    }
}

///gresit

void sortareSTALIN(vector<int>& arr) 
{
    int n = arr.size();
    int index = 3; ///am modificat de la 1
    for (int i = 1; i < n; ++i) 
    {
        if (arr[index - 1] > arr[i]) 
        { 
            arr.erase(arr.begin() + i+1);///aici trebuie fara+1 ca imi sterge urmatorul element 
            n--; 
            i++; ///aici trebuie i--
        } 
        else 
        {
            index--; ///aici indexul trebuie ++ ala corect
        }
    }
}