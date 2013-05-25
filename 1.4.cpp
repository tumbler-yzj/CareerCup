/*1.4 Write a method to decide if two strings are anagrams or not.*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

//use sort
bool anagrams(string str1, string str2) {
	if(str1.length() != str2.length()) return false;
	sort(&str1[0], &str1[0] + str1.length());
	sort(&str2[0], &str2[0] + str2.length());
	if(str1 == str2)
		return true;
	else
		return false;
}

//check if the two strings have identical counts for each uinque char.
bool anagrams2(string str1, string str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	if(len1 != len2) return false;
	int* letters = new int[256];
	int num_unique_chars = 0;
	int num_completed_t = 0;
	int i, j;
	for(i = 0; i < len1; i++) {
		if(letters[str1[i]] == 0) ++num_unique_chars;
		++letters[str1[i]];
	}
	
	for(j = 0; j < len2; j++) {
		if(letters[str2[j]] == 0) return false;
		--letters[str2[j]];
		if(letters[str2[j]] == 0) {
			++num_completed_t;
			if(num_completed_t == num_unique_chars) {
				// it¡¯s a match if t has been processed completely
				return j == len2-1;
			}
		}
	}
	return false;
}

int main() {
	string str1, str2;
	cin >> str1;
	cin >> str2;
	if(anagrams2(str1, str2))
		cout << "anagrams" << endl;
	else
		cout << "not anagrams" << endl;
		
	system("pause");
	return 0;
}
