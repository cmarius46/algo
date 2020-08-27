#include <iostream>
#include <unordered_map>

//using namespace std;

int main() {

	char c1[257];
	char c2[257];
	std::cin.getline(c1, 256);
	std::cin.getline(c2, 256);

	std::string s1(c1);
	std::string s2(c2);

	if(abs(s1.length() - s2.length()) > 1) {
		std::cout << "No; case: length difference is too big";
	}
	else {
		if(s1.length() < s2.length()) {
			std::string aux = s2;
			s2 = s1;
			s1 = aux;
		}
		// s1 is longer or equal than s2

		std::unordered_map<char, int> freq;
			bool ok = true;
			for(auto i : s1) {
				++freq[i];
			}

		if(s1.length() == s2.length()) {
			int count = 0;
			for(auto i : s2) {
				if(freq[i] == 0) {
					++count;
				}
				--freq[i];
			}
			if(count == 1) {
				std::cout << "Yes; case: equal lengths";
			}
			else {
				std::cout << "No; case: equal lengths";
			}
		}
		else {
			// s1 is longer

			for(auto i : s2) {
				if(freq[i] == 0) {
					ok = false;
				}
				--freq[i];
			}

			if(ok) {
				std::cout << "Yes; case: s1 is longer";
			}
			else {
				std::cout << "No; case: s1 is longer";
			}
		}
	}

	return 0;
}