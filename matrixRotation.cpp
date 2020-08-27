#include <iostream>
#include <fstream>
#include <vector>
//using namespace std;

int main() {

	//	1
	//2   4
	//	3
	//
	//	4
	//1   3
	//	2
	freopen("matrixRotation.in", "r", stdin);

	int n;
	std::cin >> n;

	std::vector<std::vector<int>> mat(n, std::vector<int> (n, 0));

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			std::cin >> mat[i][j];
		}
	}

	// 1 2 3
	// 4 5 6
	// 7 8 9

	// 3 -> 9 in up-right corner -> 7 down-right corner -> 1 down-left corner -> 3 up-left corner

	// mat[start][start]
	// mat[stop][start]
	// mat[stop][stop]
	// mat[start][stop]

	// mat[start+i][start]
	// mat[stop][start+i]
	// mat[stop-i][stop]
	// mat[start][stop-i]

	int start = 0;
	int stop = n-1;

	while(start < stop) {
		// flip smth

		for(int i = 0; i < stop-start; ++i) {
			int aux = mat[start][stop-i];
			mat[start][stop-i] = mat[stop-i][stop];
			mat[stop-i][stop] = mat[stop][start+i];
			mat[stop][start+i] = mat[start+i][start];
			mat[start+i][start] = aux;
		}
		++start;
		--stop;
	}

	for(auto i : mat) {
		for(auto j : i) {
			std::cout << j << " ";
		}
		std::cout << '\n';
	}


	return 0;
}