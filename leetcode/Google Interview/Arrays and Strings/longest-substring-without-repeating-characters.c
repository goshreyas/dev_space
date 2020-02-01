

/*
 *
 * Longest Substring Without Repeating Characters
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 */


#include <bits/stdc++.h>
using namespace std;

#if 0
int lengthOfLongestSubstring(string str) {
	int max_len = 0;
	if(str.size() < 0) return max_len;

	int index[26];
	fill_n (index, 26, -1);
	int s = 0, e = 1;

	index[str[0]-'a'] = 0;

	for(e; e<str.size(); e++) {
		if(index[str[e]-'a'] >= 0) {
			// charcter already seen in the past.
			max_len = ((e-s) > max_len)? (e-s) : max_len;

			for(int i=s; i<index[str[e]-'a']; i++) {
				index[str[i]-'a'] = -1;
			}
			s = index[str[e]-'a'] + 1;
		}
		index[str[e]-'a'] = e;
	}
	max_len = ((e-s) > max_len)? (e-s) : max_len;
	return max_len;
}
#endif

int lengthOfLongestSubstring(string str) {
	int max_len = 0;
	if(str.size() == 0) return max_len;

	int index[256];
	fill_n (index, 256, -1);
	int s = 0, e = 1;

	index[str[0]] = 0;

	for(e; e<str.size(); e++) {
		if(index[str[e]] >= 0) {
			// charcter already seen in the past.
			max_len = ((e-s) > max_len)? (e-s) : max_len;

			for(int i=s; i<index[str[e]]; i++) {
				index[str[i]] = -1;
			}
			s = index[str[e]] + 1;
		}
		index[str[e]] = e;
	}
	max_len = ((e-s) > max_len)? (e-s) : max_len;
	return max_len;
}

int main() {
	//string str = "aabc";
	//string str = "abcabcbb";
	string str = "";
	int max_len = lengthOfLongestSubstring(str);
	cout << "Longest Substring Without Repeating Characters(length): " << max_len << endl;
        return 0;
}




/*
$> g++ longest_substring_without_repeating_characters.cpp -o longest_substring_without_repeating_characters.o
$> chmod +x longest_substring_without_repeating_characters.o
$> ./longest_substring_without_repeating_characters.o

 */

