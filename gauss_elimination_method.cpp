// C++ program to demonstrate working of Gaussian Elimination
// method
#include<iostream>
#include <iomanip>
using namespace std;

#define N 3	 // Number of unknowns

// function to reduce matrix to r.e.f. Returns a value to
// indicate whether matrix is singular or not
int forwardElim(double mat[N][N+1]);

// function to calculate the values of the unknowns
// void backSub(double mat[N][N+1]);
void print(double mat[N][N+1])
{
	for (int i=0; i<N; i++, printf("\n"))
		for (int j=0; j<=N; j++)
			  printf("%lf ", mat[i][j]);
            cout<<fixed<<setprecision(1)<<setw(4)<<mat[i][j]<<" ";

	printf("\n");
}

// // function to get matrix content
// void gaussianElimination(double mat[N][N+1])
// {
// 	/* reduction into r.e.f. */
// 	int singular_flag = forwardElim(mat);

// 	/* if matrix is singular */
// 	if (singular_flag != -1)
// 	{
// 		printf("Singular Matrix.\n");

// 		/* if the RHS of equation corresponding to
// 		zero row is 0, * system has infinitely
// 		many solutions, else inconsistent*/
// 		if (mat[singular_flag][N])
// 			printf("Inconsistent System.");
// 		else
// 			printf("May have infinitely many "
// 				"solutions.");

// 		return;
// 	}

// 	/* get solution to system and print it using
// 	backward substitution */
// 	backSub(mat);
// }

// function for elementary operation of swapping two rows
// void swap_row(double mat[N][N+1], int i, int j)
// {
// 	printf("Swapped rows %d and %d\n", i, j);

// 	for (int k=0; k<=N; k++)
// 	{
// 		double temp = mat[i][k];
// 		mat[i][k] = mat[j][k];
// 		mat[j][k] = temp;
// 	}
//     print(mat);
// }

// // function to print matrix content at any stage


// // function to reduce matrix to r.e.f.
// int forwardElim(double mat[N][N+1])
// {
// 	for (int k=0; k<N; k++)
// 	{
// 		// Initialize maximum value and index for pivot
// 		int i_max = k;
// 		int v_max = mat[i_max][k];

// 		/* find greater amplitude for pivot if any */
// 		for (int i = k+1; i < N; i++)
// 			if (abs(mat[i][k]) > v_max)
// 				v_max = mat[i][k], i_max = i;

// 		/* if a principal diagonal element is zero,
// 		* it denotes that matrix is singular, and
// 		* will lead to a division-by-zero later. */
// 		if (!mat[k][i_max])
// 			return k; // Matrix is singular

// 		/* Swap the greatest value row with current row */
// 		if (i_max != k)
// 			swap_row(mat, k, i_max);


// 		for (int i=k+1; i<N; i++)
// 		{
// 			/* factor f to set current row kth element to 0,
// 			* and subsequently remaining kth column to 0 */
// 			double f = mat[i][k]/mat[k][k];

// 			/* subtract fth multiple of corresponding kth
// 			row element*/
// 			for (int j=k+1; j<=N; j++)
// 				mat[i][j] -= mat[k][j]*f;

// 			/* filling lower triangular matrix with zeros*/
// 			mat[i][k] = 0;
//             print(mat);
// 		}

// 		print(mat);	 //for matrix state
// 	}
// 	print(mat);		 //for matrix state
// 	return -1;
// }

// // function to calculate the values of the unknowns
// void backSub(double mat[N][N+1])
// {
// 	double x[N]; // An array to store solution

// 	/* Start calculating from last equation up to the
// 	first */
// 	for (int i = N-1; i >= 0; i--)
// 	{
// 		/* start with the RHS of the equation */
// 		x[i] = mat[i][N];

// 		/* Initialize j to i+1 since matrix is upper
// 		triangular*/
// 		for (int j=i+1; j<N; j++)
// 		{
// 			/* subtract all the lhs values
// 			* except the coefficient of the variable
// 			* whose value is being calculated */
// 			x[i] -= mat[i][j]*x[j];
// 		}

// 		/* divide the RHS by the coefficient of the
// 		unknown being calculated */
// 		x[i] = x[i]/mat[i][i];
// 	}

// 	printf("\nSolution for the system:\n");
// 	for (int i=0; i<N; i++)
// 		printf("%lf\n", x[i]);
// }

void swap(double mat[N][N+1],int i,int j){
        printf("swap %d th row to %d th row \n",i,j);
        for(int t=0;t<=N;t++){
            double a = mat[i][t];
            mat[i][t]=mat[j][t];
            mat[j][t]=a;
        }

}

int forwardElim(double mat[N][N+1]){
    
    for(int k=0;k<N;k++ ){
    int i_max = k;
    int v_max=mat[i_max][k];

    for(int i=k+1;i<N;i++){
        if(abs(mat[i][k])>v_max){
            v_max=mat[i][k];
            i_max=i;
        }
    }

    if(!mat[i_max][k]) return k;
    if(i_max!=k){
        swap(mat,k,i_max);
    }  
    print(mat);  
    for(int i =k+1;i<N;i++){
       double f = mat[i][k]/mat[k][k];
       for(int a=k+1;a<=N;a++){
        mat[i][a] -=f*mat[k][a];
       } 
       mat[i][k]=0;
    }
    print(mat);
    }
   print(mat);
   return -1; 
}

void backSub (double mat[N][N+1]) { 
    double x[N];
    for(int i = N-1;i>=0;i--){
        x[i]=mat[i][N];

        for(int j=i+1;j<N;j++){
            x[i]-=mat[i][j]*x[j];
        }

        x[i]=x[i]/mat[i][i];
    }
    
    printf("\nSolution for the system:\n");
    for (int i=0; i<N; i++)
        printf("%lf\n", x[i]);
}

void determinate(double mat[N][N+1]){
    double d = 1;
    for(int i =0;i<N;i++){
        d = d*mat[i][i];
    }
    printf("%lf\n",d);
}
// Driver program
int main()
{
	/* input matrix */
	double mat[N][N+1] = {{3.0, 2.0,-4.0, 3.0},
						{2.0, 3.0, 3.0, 15.0},
						{5.0, -3, 1.0, 14.0}
						};
    print(mat);
	// gaussianElimination(mat);
    forwardElim(mat);
    backSub(mat);
    determinate(mat);

	return 0; 
} 
