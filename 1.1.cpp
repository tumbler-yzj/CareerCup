#include <iostream>
#include <string.h>
#include <bitset>
#include <algorithm>
#define NIL -1
#define M 256

using namespace std;

int h(char key) {
	return key % M;
}

int increment(int i) {
	return i;
}

int hash(char key, int i) {
	return (h(key) + increment(i)) % M;
}

int hashSearch(char* hashtable, char key, int* pos) {
	int i = 0;
	do {
		*pos = hash(key, i);
		if(hashtable[*pos] == key) return 1;
		if(hashtable[*pos] == NIL) return 0;
	} while(++i < M);
	return -1;
}

int hashInsert(char* hashtable, char w) {
	int pos, sign;
	sign = hashSearch(hashtable, w, &pos);
	if(!sign) hashtable[pos] = w;
	return sign;
}

//use hash table
bool isUnique(char* hashtable, const char* string) {
	int i;
	for(i = 0; i < M; i++)
		hashtable[i] = NIL;
	for(i = 0; i < strlen(string); i++) {
		if(hashInsert(hashtable, string[i]) > 0)
			return true;
	}
		
}

//We will assume, in the below code, that the string is only lower case ¡®a¡¯ through ¡®z¡¯. 
//This will allow us to use just a single int
bool isUnique2(const char* string) {
	int checker = 0;
	for(int i = 0; i < strlen(string); i++) {
		int val = string[i] - 'a';
		if((checker & (1 << val)) > 0)
			return false;
		checker |= (1 << val);
	}
	return true;
}

//use bitset
bool isUnique3(bitset<M> bSet, const char* string) {
	int i;
	for(i = 0; i < strlen(string); i++) {
		if(bSet[string[i]])
			return true;
		else
			bSet[string[i]] = 1;
    }
	return false;
}

//sort string
bool isUnique4(string str) {
	sort(&str[0], &str[0] + str.length());
	for(int i = 1; i < str.length(); i++)
		if(str[i] == str[i-1])
			return true;
	return false;
}

int main() {
	char hashtable[M];
	bitset<M> bSet;
	const char* string1 = "abcdefg";
	const char* str = "adbc";
	string strr;
	cin >> strr;
	if(isUnique3(bSet, str))
		cout << "not unique" << endl;
	if(isUnique4(strr))
		cout<< "duplicate key!" << endl;
	else
		cout<< "unique string!" << endl;
	return 0;
}
