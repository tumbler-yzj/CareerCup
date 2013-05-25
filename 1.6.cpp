/*Given an image represented by an NxN matrix, where each pixel 
 in the image is 4 bytes, write a method to rotate the image by 
 90 degrees. Can you do this in place?
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;


/**/
void rotate(int** mat, int n, int direction) {
	int layer, j;
	if(direction == 0) {
		for(layer = 0; layer < n/2; ++layer) {
			int first = layer;
			int last = n - 1 - layer;
			for(j = first; j < last; ++j) {
				int offset = j - first;
				//save top
				int top = *((int*)mat + first*n + j);
				//int top = mat[first][j];
				
				//left -> top
				*((int*)mat + first*n + j) = *((int*)mat + (last-offset)*n + first);
				//mat[first][j] = mat[last-offset][first];
				
				//bottom -> left
				*((int*)mat + (last-offset)*n + (first)) = *((int*)mat + last*n + last-offset); 
				//mat[last-offset][first] = mat[j][last];
				
				//right -> bottom
				*((int*)mat + last*n + (last-offset)) = *((int*)mat + j*n + last);
				//mat[last][last]
				//top -> right
				*((int*)mat + j*n + last) = top;
				
			}		
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

	rotate((int**)mat, row, 0);

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
} 
