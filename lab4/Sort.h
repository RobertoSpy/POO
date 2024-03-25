class Sort
{
    int* elemente;
    int nrElemente;
public:
    Sort(int n, int min, int max);
    Sort();
    Sort(int* v, int n);
    Sort(int n, ...);
    Sort(char* text);

    ~Sort();

    void InsertSort(bool ascendent);

    int Pivotare(int st, int dr, bool ascendent);
    void QS(int st, int dr, bool ascendent);
    void QuickSort(bool ascendent);

    void BubbleSort(bool ascendent);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};