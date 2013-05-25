/*1.7 Write an algorithm such that if an element in an MxN matrix is 0, 
  its entire row and column is set to 0.*/

#include <iostream>
#include <cstdlib>

using namespace std;

void setZero(int** mat, const int row, const int col) {
	int i, j;
	int rows[row];// = new int[row];
	int cols[col];// = new int[col];
	
	for(i = 0; i < row; i++)
		for(j = 0; j < col; j++) {
			if(*((int*)mat + col*i + j) == 0) {
					rows[i] = 1;
					cols[j] = 1;
			}
		}
	for(i = 0; i < row; i++)
		for(j = 0; j < col; j++) {
			if(rows[i] == 1 || cols[j] == 1) {
				*((int*)mat + col*i + j) = 0;
			}
		}
}

int main() {
	const int row = 4;
	const int col = 4;

	int mat[row][col] = {{0,1,2,3},
						 {4,5,6,7},
						 {8,9,10,11},
						 {12,13,14,15}};
	
	setZero((int**)mat, row, col);
	
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}
