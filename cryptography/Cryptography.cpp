#include "Cryptography.h"

Cryptography::Cryptography()
{
	privateKey = 7;
}

Cryptography::~Cryptography()
{
}

void Cryptography::CreateKey()
{
	int p = Helper::nearPrime(privateKey);
	int q = Helper::nearPrime(p + 2);
	n = p * q; //public
	int phi = (p - 1)*(q - 1);
	publicKey = Helper::Coprime(n, phi); //public
	privateKey = CalculateDecryptionKey(publicKey, phi);
}

// x*a=1 mod(b)
int Cryptography::CalculateDecryptionKey(int publicKey, int phi)
{
	int x, y;
	Helper::__xgcd(publicKey, phi, x, y);
	if (x >= 0)
		return x;
	else
		return phi + x;
}

string Cryptography::Cesar(string message)
{
	return Cesar(message, privateKey);
}

string Cryptography::Cesar(string message, int privateKey)
{
	this->privateKey = privateKey;
	for (auto& a : message) {
		a = a + privateKey;
	}
	return message;
}

string Cryptography::_Cesar(string message)
{
	return _Cesar(message, privateKey);
}

string Cryptography::_Cesar(string message, int privateKey)
{
	this->privateKey = privateKey;
	for (auto& a : message) {
		a = a - privateKey;
	}
	return message;
}

string Cryptography::RSA(string message)
{
	CreateKey();
	for (auto&a : message) {
		a= Helper::cdn(a-97, publicKey, n);
	}
	return message;
}

string Cryptography::_RSA(string message)
{
	for (auto&a : message) {
		a = 97+Helper::cdn(a, privateKey, n);
	}
	return message;
}
