/*
 *
 *  URL: https://leetcode.com/problems/sentence-similarity-ii/
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define GET_EXEC_TIME 0

#if GET_EXEC_TIME
#include <chrono>
using namespace std::chrono;
#endif

class Solution1 {
public:
	unordered_map<string, set<string>> dict;

	void showq(queue <string> gq) {
		queue <string> g = gq;
		cout << "Queue: ";
		while (!g.empty()) {
			cout << " " << g.front();
			g.pop();
		}
		cout << '\n';
	}

	void show_set(set<string> myset) {
		cout << "Visited: ";
		for (auto it=myset.begin(); it != myset.end(); ++it)
			cout << " " << *it;
		cout << '\n';
	}

	void show_adj(string str, set<string> myset) {
		cout << "Adjacent of " << str << " are: ";
		for (auto it=myset.begin(); it != myset.end(); ++it)
			cout << " " << *it;
		cout << '\n';
	}

	bool matching(string s1, string s2) {
		set<string> visited;
		if(s1 == s2) return true;

		// BFS on dictionary
		queue<string> q_words;
		visited.insert(s1); //show_set(visited);
		q_words.push(s1); //showq(q_words);
		while(!q_words.empty()) {
			string str = q_words.front(); q_words.pop(); //showq(q_words);
			//show_adj(str, dict[str]);
			for(string adj_str : dict[str]) {
				if(adj_str == s2) return true;
				if(visited.find(adj_str) == visited.end()) {
				//if(visited.count(adj_str) == 0) {
					visited.insert(adj_str); //show_set(visited);
					q_words.push(adj_str); //showq(q_words);
				}
			}	
		}
		return false;	
	}

    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
       	dict.clear();
		if(words1.size() != words2.size()) return false;
		if(words1.size() == 0) return true;
		// Construct DIctionary
		for(int i=0; i<pairs.size(); i++) {
			if(pairs[i][0] != pairs[i][1]) {
				dict[pairs[i][0]].insert(pairs[i][1]);
				dict[pairs[i][1]].insert(pairs[i][0]);
			}
		}
		for(int i=0; i<words1.size(); i++) {
			if(matching(words1[i], words2[i]) == false) return false;	
		}
		return true;
    }
};


class Solution {
public:
	unordered_map<string, set<string>> dict;

	void show_adj(string str, set<string> myset) {
		cout << "Adjacent of " << str << " are: ";
		for (auto it=myset.begin(); it != myset.end(); ++it)
			cout << " " << *it;
		cout << '\n';
	}

	bool matching(string s1, string s2) {
		set<string> visited;
		if(s1 == s2) return true;

		// BFS on dictionary
		queue<string> q_words;
		visited.insert(s1);
		q_words.push(s1);
		while(!q_words.empty()) {
			string str = q_words.front(); q_words.pop();
			for(string adj_str : dict[str]) {
				if(adj_str == s2) return true;
				if(visited.find(adj_str) == visited.end()) {
				//if(visited.count(adj_str) == 0) {
					visited.insert(adj_str);
					q_words.push(adj_str);
				}
			}	
		}
		return false;	
	}

    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
       	dict.clear();
		if(words1.size() != words2.size()) return false;
		if(words1.size() == 0) return true;
		// Construct DIctionary
		for(int i=0; i<pairs.size(); i++) {
			if(pairs[i][0] != pairs[i][1]) {
				dict[pairs[i][0]].insert(pairs[i][1]);
				dict[pairs[i][1]].insert(pairs[i][0]);
			}
		}
		for(int i=0; i<words1.size(); i++) {
			if(matching(words1[i], words2[i]) == false) return false;	
		}
		return true;
    }
};



int main() {
	Solution s1;
	/*
	   vector<string> words1 = {"great", "acting", "skills"};
	   vector<string> words2 = {"fine", "drama", "talent"};
	   vector<vector<string>> pairs = {{"great", "good"}, {"fine", "good"}, {"acting","drama"}, {"skills","talent"}};
	 */
	vector<string> words1 = {"an","extraordinary","meal"};
	vector<string> words2 = {"one","delicious","dinner"};
	vector<vector<string>> pairs = {{"great","good"},{"extraordinary","good"},{"well","good"},{"wonderful","good"},{"excellent","good"},{"fine","good"},{"nice","good"},{"any","one"},{"some","one"},{"unique","one"},{"the","one"},{"an","one"},{"single","one"},{"a","one"},{"truck","car"},{"wagon","car"},{"automobile","car"},{"auto","car"},{"vehicle","car"},{"entertain","have"},{"drink","have"},{"eat","have"},{"take","have"},{"fruits","meal"},{"brunch","meal"},{"breakfast","meal"},{"food","meal"},{"dinner","meal"},{"super","meal"},{"lunch","meal"},{"possess","own"},{"keep","own"},{"have","own"},{"extremely","very"},{"actually","very"},{"really","very"},{"super","very"}};
	cout << "SentencesSimilar: " << s1.areSentencesSimilarTwo(words1, words2, pairs) << endl;

	/* TLE
	   ["an","extraordinary","meal"]
	   ["one","delicious","dinner"]
[["great","good"],["extraordinary","good"],["well","good"],["wonderful","good"],["excellent","good"],["fine","good"],["nice","good"],["any","one"],["some","one"],["unique","one"],["the","one"],["an","one"],["single","one"],["a","one"],["truck","car"],["wagon","car"],["automobile","car"],["auto","car"],["vehicle","car"],["entertain","have"],["drink","have"],["eat","have"],["take","have"],["fruits","meal"],["brunch","meal"],["breakfast","meal"],["food","meal"],["dinner","meal"],["super","meal"],["lunch","meal"],["possess","own"],["keep","own"],["have","own"],["extremely","very"],["actually","very"],["really","very"],["super","very"]]

*/

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
https://leetcode.com/problems/sentence-similarity-ii/submissions/
Runtime: 476 ms, faster than 13.30% of C++ online submissions for Sentence Similarity II.
Memory Usage: 107.8 MB, less than 33.33% of C++ online submissions for Sentence Similarity II.
*/

/*
 $> g++ -g sample.cpp -o sample.out
 $> gdb sample.out

 */
