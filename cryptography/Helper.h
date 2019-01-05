#pragma once
#include <stdlib.h> 
#include <vector>
using namespace std;
class Helper
{
public:
	Helper();
	~Helper();

	static int nearPrime(int a);
	static bool isPrime(int a);
	static int Coprime(int a, int b);
	static int __xgcd(int a, int b, int &x, int &y);
	static int cdn(int c, int d, int n);
private:
	
	static bool __gcd(int a, int b);
};

inline Helper::Helper()
{
}

inline Helper::~Helper()
{
}

inline int Helper::nearPrime(int a)
{
	do {
		if (isPrime(a))return a;
		a++;
	} while (true);
}

inline bool Helper::isPrime(int a)
{
	for (int i = a-1; i > 1; i--) {
		if (a%i == 0) {
			return false;
		}
	}
	return true;
}

// Choose a random coprime between 1 and b
inline int Helper::Coprime(int a, int b)
{
	vector<int> coprimes;
	for (int i = 2; i < b; i++) {
		if (__gcd(i, a) && __gcd(i, b))
			coprimes.push_back(i);
	}
	return coprimes[rand()%coprimes.size()];
}

inline int Helper::__xgcd(int a, int b, int & x, int & y)
{
    if(b == 0) {
       x = 1;
       y = 0;
       return a;
    }

    int x1, y1, gcd =__xgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

inline int Helper::cdn(int c, int d, int n)
{
	int value = 1;
   while( d > 0 )
   {
      value *= c;
      value %= n;
      d--;
   }
   return value;
}

inline bool Helper::__gcd(int a, int b)
{          
	if (a == 0) {
		if (b > 1)
			return false;
		else
			return true;
	 }
    return __gcd(b % a, a); 
}
