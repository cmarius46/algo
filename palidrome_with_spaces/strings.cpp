#include <iostream>

//using namespace std;

int main() {
	char c[256];
	std::cin.getline(c, 256);
	std::string s(c);	
	std::cout << s << '\n';

	char value = 0;

	for(auto i : s) {
		if(i != ' ') {
			value = value ^ i;
		}
	}
	
	if((value <= 'z' && value >= 'a') || value == 0) {
		std::cout << "is palindrome\n";
		std::cout << value;
	}
	else {
		std::cout << "Is not palindrome\n";
	}


	return 0;
}