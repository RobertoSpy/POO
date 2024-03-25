class Masina
{
    char* firma = nullptr;
    float litriComb;
    long long kilometraj;
    float consum;

public:
    void SetFirma(char* firma);
    char* GetFirma();

    float GetLitriComb();
    float GetConsum();
    long long GetKilometraj();

    bool SetLitriComb(float litri);
    bool SetConsum(float consumul);
    bool SetKilometraj(long long km);

    void bisnitar();
    void cursa(int km);

};