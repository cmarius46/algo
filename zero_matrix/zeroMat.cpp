#include <iostream>
#include <queue>
//#include <fstream>

// using namespace std;

int main() {
	freopen("zeroMat.in", "r", stdin);

	int n, m;
	std::cin >> m >> n;

	// m x n

	std::queue<std::pair<int, int>> q;

	std::vector<std::vector<int>> mat(m, std::vector<int> (n));

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			std::cin >> mat[i][j];
			if(mat[i][j] == 0) {
				q.push(std::pair<int, int> (i, j));
			}
		}
	} 

	while(!q.empty()) {
		std::pair<int, int> p = q.front();
		q.pop();
		for(int i = 0; i < m; ++i) {
			mat[i][p.second] = 0;
		}
		for(int j = 0; j < n; ++j) {
			mat[p.first][j] = 0;
		}
	}

	for(auto i : mat) {
		for(auto j : i) {
			std::cout << j << " ";
		}
		std::cout << '\n';
	}

	return 0;
}