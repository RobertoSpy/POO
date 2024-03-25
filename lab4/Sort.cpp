
#include "Sort.h"
#include <cstring>
#include <cstdarg>
#include <iostream>
using namespace std;

Sort::Sort(int n, int min, int max)
{
    nrElemente=n;
    elemente = new int[nrElemente];
    for(int i=0;i<nrElemente;i++)
        elemente[i]=min+rand()%(min-max+1); 
}

Sort::Sort() : elemente(new int[6] {1,2,3,4,5,6}) {
    nrElemente=6;
}

Sort::Sort(int* v, int n)
{
    nrElemente=n;
    elemente = new int[nrElemente];
    for(int i=0;i<nrElemente;i++)
        elemente[i]=v[i];
}

Sort::Sort(int n, ...)
{
    nrElemente=n;
    elemente = new int[nrElemente];
    va_list args;
    va_start(args,nrElemente);
    for(int i=0;i<nrElemente;i++)
        elemente[i]= va_arg(args,int);
}

Sort::Sort(char* text)
{
    char* p,sep[]=",";
    int ct=0,n=0;
    for(int i=0;text[i];i++)
        if(text[i]==',') ct++;
    nrElemente=ct+1;
    elemente = new int[nrElemente];
    p=strtok(text,sep);
    while(p)
    {
        int nr=0;
        for(int i=0;p[i];i++)
            nr=nr*10+(p[i]-'0');
        elemente[n]=nr;
        n++;
        p=strtok(nullptr,sep);
    }
}

Sort::~Sort() {
    delete[] elemente;
}

void Sort::InsertSort(bool ascendent)
{
    for(int i=1;i<nrElemente;i++)
    {
        int p=i;
        if(ascendent==true) {
            while(p>0 && elemente[p]<elemente[p-1])
            {
                int aux=elemente[p];
                elemente[p]=elemente[p-1];
                elemente[p-1]=aux;
                p--;
            }
        }
        else {
            while(p>0 && elemente[p]>elemente[p-1])
            {
                int aux=elemente[p];
                elemente[p]=elemente[p-1];
                elemente[p-1]=aux;
                p--;
            }
        }
    }
}

int Sort::Pivotare(int st, int dr, bool ascendent)
{
    int i=st,j=dr,pasi=0,pasj=1;
    if(ascendent==true) {
        while(i<j)
        {
            if(elemente[i]>elemente[j])
            {
                int aux;
                aux=elemente[i]; elemente[i]=elemente[j]; elemente[j]=aux;
                aux=pasi; pasi=pasj; pasj=aux;
            }
            i+=pasi;
            j-=pasj;
        }
    }
    else {
        while(i<j)
        {
            if(elemente[i]<elemente[j])
            {
                int aux;
                aux=elemente[i]; elemente[i]=elemente[j]; elemente[j]=aux;
                aux=pasi; pasi=pasj; pasj=aux;
            }
            i+=pasi;
            j-=pasj;
        }
    }
    return i;
}

void Sort::QS(int st, int dr, bool ascendent) {
    if(st<dr)
    {
        int p=Pivotare(st,dr,ascendent);
        QS(st,p-1,ascendent);
        QS(p+1,dr,ascendent);
    }
}

void Sort::QuickSort(bool ascendent) {
    if(ascendent==true)
        QS(0,nrElemente-1,true);
    else
        QS(0,nrElemente-1,false);
}

void Sort::BubbleSort(bool ascendent) {
    bool ok=0;
    while(!ok)
    {
        ok=1;
        for(int i=0;i<nrElemente-1;i++)
            if(ascendent==true) {
                if(elemente[i]>elemente[i+1])
                {
                    int aux=elemente[i];
                    elemente[i]=elemente[i+1];
                    elemente[i+1]=aux;
                    ok=0;
                }
            }
            else {
                if(elemente[i]<elemente[i+1])
                {
                    int aux=elemente[i];
                    elemente[i]=elemente[i+1];
                    elemente[i+1]=aux;
                    ok=0;
                }
            }

    }
}

void Sort::Print() {
    for(int i=0;i<nrElemente;i++)
        cout<<elemente[i]<<" ";
    cout<<endl;
}

int Sort::GetElementsCount() {
    return nrElemente;
}

int Sort::GetElementFromIndex(int index) {
    return elemente[index];
}
