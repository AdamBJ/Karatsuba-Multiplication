#include <iostream>
#include <sstream>

int kMult(int a, int b);

int main() {
	int x, y;

	std::cin >> x >> y;
	int rslt = kMult(x, y);
	std::cout << rslt;

	return 0;


}

int kMult(int x, int y) {
	int nDigits;
	
	if (x == 0) nDigits = 1;
	else nDigits = floor(log10(abs(x))) + 1;
	
	if (nDigits == 1) {
		//basecase
		return x*y;
	}
	else {
		//prepare to recurse again
		
		std::string xString = std::to_string(x);
		std::string yString = std::to_string(y);

		int a, b, c, d;

		a = stoi(xString.substr(0, nDigits / 2));
		b = stoi(xString.substr(nDigits / 2, xString.length()));
		c = stoi(yString.substr(0, nDigits / 2));
		d = stoi(yString.substr(nDigits / 2, yString.length()));

		return pow(10, nDigits)*kMult(a,c) + pow(10,nDigits/2)*(kMult (a,d)+kMult(b,c)) + kMult(b,d);
	}
}