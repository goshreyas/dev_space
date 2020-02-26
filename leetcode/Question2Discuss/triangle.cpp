/*
 *
 *  URL:  https://leetcode.com/problems/triangle/
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define GET_EXEC_TIME 0

#if GET_EXEC_TIME
#include <chrono>
using namespace std::chrono;
#endif

/*
Runtime: 4 ms, faster than 96.36% of C++ online submissions for Triangle.
Memory Usage: 11.1 MB, less than 8.70% of C++ online submissions for Triangle.
*/
class Solution {
	public:
		bool min_path[1000][1000];
		vector<vector<int>> triangle_g; int n;
		int _minimumTotal(int i, int j) {
			if(i == n) return 0;
			if(min_path[i][j] == true) return triangle_g[i][j];
			triangle_g[i][j] += min(_minimumTotal(i+1, j), _minimumTotal(i+1, j+1));
			min_path[i][j] = true;
			return triangle_g[i][j];
		}
		int minimumTotal(vector<vector<int>>& triangle) {
			triangle_g = triangle;
			n = triangle.size();
			memset(min_path, 0, sizeof(min_path));
			return _minimumTotal(0, 0);
		}
};


int main() {
	Solution sol;
	vector<vector<int>> triangle = {
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3} 
	}; // Expected: 11
	vector<vector<int>> triangle1 = {
		{2},
		{3,4}
	}; // Expected : 5

		cout << "The minimum path sum from top to bottom is: " << sol.minimumTotal(triangle) << endl;


#if GET_EXEC_TIME
	auto start = high_resolution_clock::now();
	// Invoke the code API here
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Duration: "<< duration.count() << " microseconds." << endl;
#endif

	return 0;
}




/*
 $> g++ -g sample.cpp -o sample.out
 $> gdb sample.out

 */
