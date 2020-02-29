/*
 *
 *  URL: https://leetcode.com/problems/shortest-palindrome/
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
		string shortestPalindrome(string s) {
			string rev = s, n_str, res_str;
			int n_len, n = s.size();
			reverse(rev.begin(), rev.end());
			n_str = s + "#" + rev;
			n_len = n_str.size();
			vector<int> KMP(n_len, 0);
			for(int j=1, i=0; j<n_len; j++) {
				i = KMP[j-1];
				while(i>0 && n_str[i] != n_str[j]) i = KMP[i-1];
				if(n_str[i] == n_str[j]) i++;
				KMP[j] = i;
			}
			res_str = rev.substr(0, n-KMP[n_len-1]) + s;
			return res_str;
		}
};


int main() {
	Solution sol;
	string in1 = "aacecaaa", out1;
	out1 = sol.shortestPalindrome(in1);
	cout << "Res String: " << out1 << endl;
	if (out1 == "aaacecaaa") cout << "PASS" << endl;
	else cout << "FAIL" << endl;


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
