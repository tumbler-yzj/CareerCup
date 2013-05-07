/*Write a method to replace all spaces in a string with ¡®%20¡¯.*/

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void replace(char* str, int length) {
	if(str == NULL || length < 0) return;
	
	int i = 0, numOfBlank = 0;
	while(str[i] != '\0') {
		if(str[i] == ' ') {
			++numOfBlank;
		}
		++i;
	}
	
	int lenOfOriginal = i;
	int lenOfNew = lenOfOriginal + numOfBlank * 2;
	if(lenOfNew > length)
		return;
	
	int indexOfOriginal = lenOfOriginal;
	int indexOfNew = lenOfNew;
	while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
		if(str[indexOfOriginal] != ' ') {
			str[indexOfNew--] = str[indexOfOriginal]; 
		}
		else {
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';	
		}
		--indexOfOriginal;
	}
}

int main() {
	const int length = 100;
	char str[length] = " we are happy. ";
	//cin >> str;
	replace(str, length);
	cout << str << endl;
	system("pause");
	return 0;	
}
