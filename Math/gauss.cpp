const double EPS = 1e-9;
const int INF = 2; // it does not have to be infinity or a big number
/* - this function return the number of
solutions of the system (0, 1, or infinity).
if at least one solution exists, then it is
returned in the vector Ans.
- The function uses two pointers - the current
column "col" and the current
row "row"
- For each variable xi, the value where(i) is
the line where this column is not
zero. This vector is needed because some
variables can be independent.
- In this implementation, the current ith line
is not divided by aii as
described above, so in the end the matrix is
not identity matrix (though
apparently dividing the ith line can help
reducing errors)
- After finding solution, it is inserted back
into the matrix - to check
whether the system has at least one solution or
not. if the test solution is
successful then the function returns 1 or inf,
depending on whether there is
at least one independent variable.
*/
int GaussianElimination (vector <vector <double> > A,vector <double>& Ans) {
    int n = (int) A.size();
    int m = (int) A[0].size() - 1; //ignore the last column which is the vector of B;
    vector <int> where (m, -1);
    for (int col = 0, row = 0; col < m && row < n; col++) {
        int sel = row;
        for (int i = row; i < n; i++)
            if (abs (A[i][col]) > abs (A[sel][col]))sel = i;
        if (abs (A[sel][col]) < EPS) continue;
        for (int i = col; i <= m; i++)
            swap (A[sel][i], A[row][i]);
        where[col] = row;
        for (int i = 0; i < n; i++) {
            if (i != row) {
                double c = A[i][col] / A[row][col];
                for (int j = col; j <= m; j++)
                    A[i][j] -= A[row][j] * c;
            }
        }
        row++;
    }
    Ans.assign (m, 0);
    for (int i = 0; i < m; i++) {
        if (where[i] != -1)
            Ans[i] = A[where[i]][m] / A[where[i]][i];
    }
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++)
            sum += Ans[j] * A[i][j];
        if (abs (sum - A[i][m]) > EPS)
            return 0;
    }
    return 1;
}
