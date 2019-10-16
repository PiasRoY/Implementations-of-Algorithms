//Matrix Expo
class matrix {
public:
	int mat[2][2];
	int row, col;

	//constructors
	matrix() {
		memset(mat, 0, sizeof mat);
	}
	matrix(int r, int c) {
		row = r, col = c;
		memset(mat, 0, sizeof mat);
	}

	//functions
	matrix operator* (matrix &p) { //Complexity: O(N^3)
		matrix temp;

		temp.row = row;
		temp.col = p.col;

		int sum;
		for(int i = 0; i < temp.row; i++) {
			for(int j = 0; j < temp.col; j++) {

				sum = 0;
				for(int k = 0; k < col; k++) {
					sum += mat[i][k] * p.mat[k][j];
//					sum = (sum + (((ll) mat[i][k] * p.mat[k][j]) % mod)) % mod;
				}

				temp.mat[i][j] = sum;
			}
		}

		return temp;
	}

	matrix operator+ (matrix &p) { //Complexity: O(N^2)
		matrix temp;

		temp.row = row;
		temp.col = col;

		for(int i = 0; i < temp.row; i++) {
			for(int j = 0; j < temp.col; j++) {
				temp.mat[i][j] = mat[i][j] + p.mat[i][j];
			}
		}

		return temp;
	}

	matrix identity() { //square matrix with 1s in LR-diagonal
		matrix temp;

		temp.row = row;
		temp.col = col;

		for(int i = 0; i < row; i++)
			temp.mat[i][i] = 1;

		return temp;
	}

	matrix pow(int pow) { //Complexity: O(logPow) * O(N^3) = O(N^3 * logPow)
		matrix temp = (*this);
		matrix ret = (*this).identity();

		while(pow > 0) {
			if(pow%2 == 1)
				ret = ret * temp;

			temp = temp * temp;
			pow /= 2;
		}

		return ret;
	}

	void show()
	{
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				printf("%d ", mat[i][j]);
			}
			printf("\n");
		}
	}
};
