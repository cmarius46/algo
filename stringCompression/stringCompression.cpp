#include <iostream>
#include <vector>

//using namespace std;

int main() {

	char c[256];
	std::cin.getline(c, 256);
	std::string s(c);
	std::string sol;

	int i = 0;
	while(i < s.length()) {
		char ch = std::tolower(s[i]);
		++i;
		int count = 1;
		while(i < s.length() && s[i] == std::tolower(ch) ) {
			++count;
			++i;
		}
		sol.push_back(ch);
		std::string newS = std::to_string(count);
		sol.insert(sol.length(), newS);
	}
	if(sol.length() >= s.length()) {
		std::cout << "unchanged: " << s << '\n';
	}
	else {
		std::cout << "compressed: " << sol << '\n';
	}

	return 0;
}