/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// 2373. Largest Local Values in a Matrix
#define MAX(a,b) ((a)>(b))?(a):(b)
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int n = gridSize-2;
    int** result = malloc(n*sizeof(int*));
    for (int i=0; i<n; i++) 
        result[i] = malloc(n*sizeof(int));

    *returnSize = n;
    (*returnColumnSizes) = malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        returnColumnSizes[0][i] = n;
    }

    // Horizontal max
    for (int i=0; i<gridSize; i++)
    {
        for (int j=0; j<n; j++) {
            int maxV=0;
            for (int k=j; k<j+3; k++)
                maxV = MAX(maxV, grid[i][k]);
            grid[i][j] = maxV;
        }
    }

    // vertical max
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int maxV=0;
            for (int k=j; k<j+3; k++)
                maxV = MAX(maxV, grid[k][i]);
            result[j][i] = maxV;
        }
    }

    return result;
}
