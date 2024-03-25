#include<iostream>
using namespace std;

#include "masina.h"

void Masina::SetFirma(char* firma)
{
    if (this->firma == 0)
        this->firma = new char[100];
    int sz = strlen(firma);
    for(int i=0;i<sz;i++)
    {
        this->firma[i] = firma[i];
    }
}
char* Masina::GetFirma()
{
    return this->firma;
}
float Masina::GetLitriComb()
{
    return this->litriComb;
}
long long  Masina::GetKilometraj()
{
    return this->kilometraj;
}
float Masina::GetConsum()
{
    return this->consum;
}

bool Masina::SetConsum(float consumul)
{
    if (consumul < 0 ||consumul>100)return false;
    this->consum = consumul;
    return true;
}
bool Masina::SetLitriComb(float litri)
{
    if (litri < 0||litri>600)return false;
    this->litriComb = litri;
    return true;
}
bool Masina::SetKilometraj(long long km)
{
    if (km < 0)return false;
    this->kilometraj = km;
    return true;
}


void Masina::bisnitar()
{
     this->kilometraj = this->kilometraj - 1000;
}
void Masina::cursa(int km)
{
    if (km > 0)
    {
        this->kilometraj = this->kilometraj + km;
        this->litriComb = this->litriComb - km * this->consum / 100;
    }
}