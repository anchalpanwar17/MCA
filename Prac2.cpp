#include<bits/stdc++.h>
using namespace std;

bool isSparse(int **mat, int m, int n, int &elem) {
	
    elem = 0; // counts non zeros;
    int total = m*n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0)
                elem++;  
        }
    }
    if(elem < (total/4)){
    	return true;
	}
	else{
		return false;
	} 
}

void SparseMat(int **mat, int nrow, int ncol, int **sparse, int elem) {
	
    sparse[0][0]=nrow;
    sparse[0][1]=ncol;
    sparse[0][2]=elem;
    int rnumber=1;
    for (int i = 0; i<nrow ; i++) {
        for (int j = 0; j<ncol ; j++) {

            if (mat[i][j] != 0) {
                sparse[rnumber][0] = i;
                sparse[rnumber][1] = j;
                sparse[rnumber][2] = mat[i][j];
                rnumber++;
            }
        }
    }
    return;
}

void printSparseMatrix(int **sparse, int elem) {

    cout << "Sparse Matrix:\n\n";
    cout << "Row\tCol\tValue\n";
    
    for (int i = 0; i <= elem; i++) {
        cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << endl;
    }
}

int main() {
	
    int nrow, ncol, elem;   //elem -> counts of non zero elements
    
    	cout << "Enter the number of rows of the matrix: "<<endl;
        cin >> nrow;
        cout << "Enter the number of columns of the matrix: "<<endl;
        cin>> ncol;
    
        int **matrix = new int *[nrow];  // allocating memory for each row.

        for (int i = 0; i < nrow; i++)
        {
            matrix[i] = new int[ncol];  //allocating memory for each column
        }
    	
    	cout <<"Enter the elements of the matrix:\n";
        for (int i = 0; i < nrow; i++) {
           for (int j = 0; j < ncol; j++) {
              cin >> matrix[i][j];
            }
        }
        cout<<"The given Matrix: "<<endl;
        cout <<"\n";
        for (int i = 0; i < nrow; i++) {
           for (int j = 0; j < ncol; j++) {
              cout << matrix[i][j]<<" ";
            }
            cout <<"\n";
        }
        cout<<endl;
       
        if (isSparse(matrix, nrow, ncol, elem)) {
        	
           cout << "The threshold is " << (nrow * ncol) / 4 << ", Number of non-zero elements = " << elem << endl;
           cout << "The matrix is sparse."<<endl;
           cout<< endl;
           
           int **sparse = new int *[elem+1];

           for (int i = 0; i < elem + 1; i++){
               sparse[i] = new int[3]; //the cols in sparse matrix is fix, i.e., 3 //row//col//val
		   }
        

           SparseMat(matrix, nrow, ncol, sparse, elem);
           printSparseMatrix(sparse, elem);
           
        } else {
           cout << "The threshold is " << (nrow * ncol) / 4 << ", Number of non-zero elements = " << elem << endl;
           cout << "The matrix is not sparse."<<endl;     
        }
        
	
    return 0;
}