#include <iostream>
#include <cstring>
// using namespace std;

int main() {
	char c1[256];
	std::cin.getline(c1, 256);
	std::string s1(c1);

	char c2[256];
	std::cin.getline(c2, 256);
	std::string s2(c2);

	std::string s3 = s2 + s2;

	if(s3.find(s1) != std::string::npos) {
		std::cout << "Yes";
	}
	else {
		std::cout << "No";
	}

	return 0;
}