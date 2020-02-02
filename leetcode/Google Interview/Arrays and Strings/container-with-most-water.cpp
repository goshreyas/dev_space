/*
 *
 *  URL:  https://leetcode.com/problems/container-with-most-water/
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define GET_EXEC_TIME 0

#if GET_EXEC_TIME
#include <chrono>
using namespace std::chrono;
#endif

// TLE: Time Limit Exceeded
class Solution1 {
public:
    int maxArea(vector<int>& height) {
       	int n = height.size(), max_size = 0;
		for(int l=0; l<n-1; l++)
			for(int r=l+1; r<n; r++)
				max_size = max(max_size, min(height[l], height[r])*(r-l));
		return max_size;
    }
};

// Approach: find two number whose sum is x in a sorted array.
class Solution2 {
	public:
		int maxArea(vector<int>& height) {
			int l=0, r=height.size()-1, max_size = 0;
			while(l<r) {
				max_size = max(max_size, min(height[l], height[r])*(r-l));
				if(height[l] < height[r]) l++;
				else r--;
			}
			return max_size; 
		}
};


int main() {
	vector<int> height{1,8,6,2,5,4,8,3,7};
	Solution1 s1;
	cout << "container size: " << s1.maxArea(height) << endl;
	Solution1 s2;
	cout << "container size: " << s2.maxArea(height) << endl;


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
