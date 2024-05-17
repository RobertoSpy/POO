#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<fstream>

using namespace std;

bool comparareWord(pair<string, int>&a, pair<string, int>&b)
{
    if(a.second==b.second)
    return a.first > b.first;
    else 
     return a.second<b.second;

}

int main()
{
    ifstream fisier("fraza.txt");
    if(!fisier.is_open())
    {
     cerr << "EROARE"<<endl;
     return 1;
    }

     string fraza;
     stringstream buffer;
     buffer << fisier.rdbuf();
     fraza = buffer.str();


     map<string, int> word_map;
     fisier.close();
     string separator=" ,.";
     string currentWord;
     int currentPos;

     while(!fraza.empty())
     {
        int posnotsep = fraza.find_first_not_of(separator);
        if(posnotsep == string::npos)
          return 0;

        fraza = fraza.substr(posnotsep);
        currentPos = fraza.find_first_of(separator);
        currentWord = fraza.substr(0, currentPos);

        if(currentPos == string::npos)
        {
            fraza.clear();
        }
        else
         fraza=fraza.substr(currentPos + 1);

         transform(currentWord.begin(), currentWord.end(), currentWord.begin(),[](char c){return tolower(c);});
         word_map[currentWord]++;
     }

      priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(&comparareWord)> pq(comparareWord);
      
     for( const auto &entry : word_map)
     {
        pq.push({entry.first, entry.second});
     }
     while(!pq.empty())
     {
        auto &i = pq.top();
        cout<<i.first<<"=>" << i.second<<endl;
        pq.pop();
     }
     return 0;








}