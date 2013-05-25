/*Assume you have a method isSubstring which checks if one word
 is a substring of another. Given two strings, s1 and s2, write 
 code to check if s2 is a rotation of s1 using only one call to isSubstring 
(i.e., ¡°waterbottle¡± is a rotation of ¡°erbottlewat¡±).
*/
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

bool isSubString(char* str1, char* str2) {
	if(strstr(str1, str2))
		return true;
	else
		return false;
}

bool isRotation(string str1, string str2) {
	if(str1.length() != str2.length()) return false;
	string temp = str1 + str1;
	if(isSubString(&temp[0], &str2[0]))
		return true;
	else
		return false;
}

int main() {
	string str1, str2;
	cin >> str1;
	cin >> str2;

	if(isRotation(str1, str2))
		cout << str2 << " is the rotation of " << str1 << endl;
	else
		cout << str2 << " is not the rotation of " << str1 << endl;
	system("pause");
	return 0;
}
