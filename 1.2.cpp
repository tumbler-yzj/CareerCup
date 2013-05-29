/*CareerCup 1.2 Write code to reverse a C-Style String. 
  (C-String means that ¡°abcd¡± is represented as five characters, including the null character.)*/

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char* reverse(char* str) {
	char temp;
	int i = 0;
	int j = strlen(str)-1;
	while(i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return str;
}

int main() {
	char* str;
	cin >> str;
	str = reverse(str);
	cout << str << endl;
	system("pause");
	return 0;
}
