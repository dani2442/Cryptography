#pragma once
#include "Helper.h"

#include <math.h>
#include <vector>
#include <string>
using namespace std;

class Cryptography
{
public:
	Cryptography();
	~Cryptography();

	void CreateKey();
	int CalculateDecryptionKey(int publicKey, int phi);

	// Cesar
	string Cesar(string message);
	string Cesar(string message,int privateKey);

	string _Cesar(string message);
	string _Cesar(string message,int privateKey);

	// RSA
	string RSA(string message);

	string _RSA(string message);

	int publicKey;
	int n;

private:
	int privateKey;
};

