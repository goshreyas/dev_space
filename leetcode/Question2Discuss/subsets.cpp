/*
 *
 *  URL: https://leetcode.com/problems/subsets/
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define GET_EXEC_TIME 0

#if GET_EXEC_TIME
#include <chrono>
using namespace std::chrono;
#endif

class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			vector<vector<int>> all_sets;
			all_sets.push_back({});
			for(int a : nums) {
				int s = all_sets.size();
				for(int i=0; i<s; i++) {
					vector<int> ts = all_sets[i];
					ts.push_back(a);
					all_sets.push_back(ts);
				}
			}
			return all_sets;
		}
};

void print_2D_vector(vector<vector<int>> matrix_2d) {
	int r = matrix_2d.size();
	cout << endl;
	for(int i=0; i<r; i++) {
		cout << "{";
		for(int j=0; j<matrix_2d[i].size(); j++)
			cout << matrix_2d[i][j] << ", ";
		cout << "}" << endl;
	}
}


int main() {
	Solution sol;
	vector<int> nums = {1,2,3};
	vector<vector<int>> res_sets = sol.subsets(nums);
	print_2D_vector(res_sets);

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
