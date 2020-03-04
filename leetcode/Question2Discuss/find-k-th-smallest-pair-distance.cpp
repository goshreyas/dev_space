/*
 *
 *  URL: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define GET_EXEC_TIME 0

#if GET_EXEC_TIME
#include <chrono>
using namespace std::chrono;
#endif

// TLE
class Solution1 {
	public:
		int smallestDistancePair(vector<int>& nums, int k) {
			priority_queue<int, vector<int>, greater<int>> pq;
			sort(nums.begin(), nums.end());
			for(int i=0; i<nums.size(); i++) {
				for(int j=i+1; j<n && (j-i)<=k; j++)
					pq.push(abs(nums[i]-nums[j]));
			}
			int res;
			for(int i=0; i<k && !pq.empty(); i++) {
				res = pq.top();
				pq.pop();
			}
			return res;
		}
};

class Solution {
    public:
        int smallestDistancePair(vector<int>& nums, int k) {
            int n = nums.size(), N = 1000000;
            vector<int> cnt(N, 0);
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) 
                    cnt[abs(nums[i]-nums[j])]++;
            }
            for (int i = 0; i < N; i++) {
                if (cnt[i] >= k) return i;
                k -= cnt[i];
            }
            return 0;
        }
};


int main() {
	Solution sol;
	vector<int> nums1 = {1,3,1}; int k1 = 1;
	cout << "Smallest Pair Distance: " << sol.smallestDistancePair(nums1, k1) << endl;



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
