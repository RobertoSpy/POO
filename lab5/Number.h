class Number
{
	int nr;
	int* ar;
	int b;
public:
	Number();
	~Number();
	Number(const char* value, int base); // where base is between 2 and 16
	int operator+ (Number a);
	int operator- (Number a);
	int operator> (Number a);
	int operator< (Number a);
	void operator= (int x); 
	void operator-- ();
	void operator-- (int);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};