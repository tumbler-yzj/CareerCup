/*Design an algorithm and write code to remove the duplicate 
  characters in a string without using any additional buffer. 
  NOTE: One or two additional variables are fine. An extra copy of the array is not.*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char* remove(char* str) {
	int i, j;
	sort(str, str + strlen(str));
//	cout << "after sort\n";
	
	for(i = 1; i < strlen(str); i++) {
		if(str[i] == str[i-1]) {
			for(j = i; j <= strlen(str); j++) {
				str[j-1] = str[j];
			}
			i--;
//			cout << "i=" << i << " (" << str << ")\n";
		}
	}
	return str;
}

string remove2(char* str) {
	int i, j;
	bool flg = false;
	string temp;
	temp += str[0];
	for(i = 1; i < strlen(str); i++) {
		for(j = 0; j < i; j++) {
			if(str[j] == str[i]) {
				flg = true;
				break;	
			}
		}
		if(!flg)
			temp += str[i];
		else
			flg = false;
	}
	temp += '\0';
	return temp;
}

int main() {
	char str[] ="abbccccccccd";
	
	cout << remove2(str) << endl;
	system("pause");
	return 0;
}
