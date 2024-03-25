#include "NumberList.h"
#include <iostream>
using namespace std;

void NumberList::Init()
{
    this->length = 10;
    this->count = 0;
    this->numbers = new int[length];
}
bool NumberList::Add(int x)
{
    if (this->count >= this->length)
    {
        int* sec = new int[this->length];
        for (int i = 0; i < this->count; i++)
            sec[i] = this->numbers[i];
        delete this->numbers;
        this->length = this->length * 2;
        this->numbers = new int[this->length];
        for (int i = 0; i < this->count; i++)
            this->numbers[i] = sec[i];
        delete sec;
    }
    this->numbers[this->count] = x;
    this->count++;

    return true;
}
void NumberList::Sort()
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < this->count - 1; i++)
        {
            if (this->numbers[i] > this->numbers[i + 1])
            {
                int aux = this->numbers[i];
                this->numbers[i] = this->numbers[i + 1];
                this->numbers[i + 1] = aux;
                sorted = false;
            }
        }
    }
}

void NumberList::Print()
{
    for (int i = 0; i < this->count; i++)
        printf("%d ", this->numbers[i]);
    printf("\n");
}