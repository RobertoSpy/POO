#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{
    Sort cons1(5, 10, 50);
    cons1.Print();
    cout<<"Acest vector are "<<cons1.GetElementsCount()<<" elemente."<<endl;
    cout<<"Elementul din vector cu indicele 2 este "<<cons1.GetElementFromIndex(2)<<endl;
    cout<<"Vectorul sortat crescator cu InsertSort: ";
    cons1.InsertSort(true);
    cons1.Print();

    cout<<endl;

    Sort* cons2 = new Sort();
    cons2->Print();
    cout<<"Acest vector are "<<cons2->GetElementsCount()<<" elemente."<<endl;
    cout<<"Elementul din vector cu indicele 2 este "<<cons2->GetElementFromIndex(2)<<endl;
    cout<<"Vectorul sortat crescator cu QuickSort: ";
    cons2->QuickSort(true);
    cons2->Print();

    cout<<endl;

    int v[5]={6,1,3,12,17};
    Sort cons3(v, 5);
    cons3.Print();
    cout<<"Acest vector are "<<cons3.GetElementsCount()<<" elemente."<<endl;
    cout<<"Elementul din vector cu indicele 2 este "<<cons3.GetElementFromIndex(2)<<endl;
    cout<<"Vectorul sortat crescator cu BubbleSort: ";
    cons3.BubbleSort(true);
    cons3.Print();

    cout<<endl;

    Sort cons4(5, 2, 3, 12, 17, 1);
    cons4.Print();
    cout<<"Acest vector are "<<cons4.GetElementsCount()<<" elemente."<<endl;
    cout<<"Elementul din vector cu indicele 2 este "<<cons4.GetElementFromIndex(2)<<endl;
    cout<<"Vectorul sortat descrescator cu InsertSort: ";
    cons4.InsertSort(false);
    cons4.Print();

    cout<<endl;

    char a[]="5,2,3,12,67";
    Sort cons5(a);
    cons5.Print();
    cout<<"Acest vector are "<<cons5.GetElementsCount()<<" elemente."<<endl;
    cout<<"Elementul din vector cu indicele 2 este "<<cons5.GetElementFromIndex(2)<<endl;
    cout<<"Vectorul sortat descrescator cu QuickSort: ";
    cons5.QuickSort(false);
    cons5.Print();
    return 0;
}