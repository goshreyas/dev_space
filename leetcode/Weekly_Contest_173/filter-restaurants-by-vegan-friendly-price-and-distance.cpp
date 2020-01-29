/*
 *
 *  URL:
 *  https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
 *  https://leetcode.com/contest/weekly-contest-173/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
 */

#include <bits/stdc++.h>
using namespace std;

#define GET_EXEC_TIME 0

#if GET_EXEC_TIME
#include <chrono>
using namespace std::chrono;
#endif

bool sort2D( const vector<int>& v1, 
			const vector<int>& v2 ) { 
  	if(v1[1] == v2[1])
		return v1[0] > v2[0];
	else return v1[1] > v2[1];
}

void print(vector<vector<int>> board) {
	int r = board.size(), c = board[0].size();
	cout << endl;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

/*
Runtime: 76 ms, faster than 97.26% of C++ online submissions for Filter Restaurants by Vegan-Friendly, Price and Distance.
Memory Usage: 21.3 MB, less than 100.00% of C++ online submissions for Filter Restaurants by Vegan-Friendly, Price and Distance.
*/
class Solution1 {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
 		vector<vector<int>> res_restaurants;
		vector<int> res;
		int res_idx = 0;
		// Filter Resturant
		for(int i=0; i<restaurants.size(); i++) {
			if(restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance && \
			   (veganFriendly == 0 || restaurants[i][2] == veganFriendly)) {
				res_restaurants.push_back({restaurants[i][0], restaurants[i][1]});	
			} //if
		} // for
		// Sort Restutant
		sort(res_restaurants.begin(), res_restaurants.end(), sort2D);
		//print(res_restaurants);
		for(int i=0; i<res_restaurants.size(); i++) res.push_back(res_restaurants[i][0]);
		return res;
    }
};


/*
Runtime: 92 ms, faster than 74.66% of C++ online submissions for Filter Restaurants by Vegan-Friendly, Price and Distance.
Memory Usage: 20.6 MB, less than 100.00% of C++ online submissions for Filter Restaurants by Vegan-Friendly, Price and Distance.
*/
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
		vector<int> res;
		// Sort Restutants
		sort(restaurants.begin(), restaurants.end(), sort2D);
		// Filter Resturant
		for(int i=0; i<restaurants.size(); i++) {
			if(restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance && \
			   (veganFriendly == 0 || restaurants[i][2] == veganFriendly)) {
				res.push_back(restaurants[i][0]);	
			} //if
		} // for
		return res;
    }
};


int main() {
	Solution s1;
	vector<vector<int>> restaurants = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
	int veganFriendly = 1, maxPrice = 50, maxDistance = 10;
	// Output: [3,1,5]
	
	//vector<vector<int>> restaurants = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
	//int veganFriendly = 0, maxPrice = 50, maxDistance = 10;
	// Output: [4,3,2,1,5]

	//vector<vector<int>> restaurants = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
	//int veganFriendly = 0, maxPrice = 30, maxDistance = 3;
	// Output: [4,5]
	
	vector<int> res = s1.filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance);

	for(int i=0; i<res.size(); i++) cout << res[i] << ", ";
	cout << endl;

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
