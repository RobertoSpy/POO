#include "Math.h"
#include<iostream>
#include "Canvas.h"

using namespace std;

int main()
{
   
    cout  << Math::Add(2, 3) << endl;
    cout  << Math::Add(2, 3, 4) << endl;
    cout  << Math::Add(2.5, 3.5) << endl;
    cout  << Math::Add(2.5, 3.5, 4.5) << endl;
    cout  << Math::Mul(2, 3) << endl;
    cout  << Math::Mul(2, 3, 4) << endl;
    cout  << Math::Mul(2.5, 3.5) << endl;
    cout  << Math::Mul(2.5, 3.5, 4.5) << endl;
    cout  << Math::Add(5, 1, 2, 3, 4, 5) << endl;
   char* v = Math::Add("Buna", "Ceai");
   if (v != nullptr)
   {
       cout << v;
       delete[] v;
   }
   else cout << "Nu se poate boss";


   Canvas canvas(30,20);
    canvas.DrawCircle(15, 10, 5, '*');
    canvas.FillCircle(25, 15, 3, '#');
    canvas.DrawRect(5, 5, 15, 10, '+');
    canvas.FillRect(20, 5, 25, 15, '-');
    canvas.DrawLine(2, 2, 27, 17, '.');

    canvas.Print();
    
   return 0;
}