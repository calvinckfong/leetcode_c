// 861. Score After Flipping Matrix
int matrixScore(int** grid, int gridSize, int* gridColSize) {
    int result = 0, i, j, num, cntOne;
    
    for (i=0; i<gridSize; i++) {
        if (grid[i][0] == 0) {
            for (j=0; j<gridColSize[i]; j++) {
                grid[i][j] = 1-grid[i][j];
            }
        }
    }

    for (j=0; j<gridColSize[0]; j++) {
        cntOne = 0;
        for (i=0; i<gridSize; i++) {
            cntOne += grid[i][j];
        }
        if (cntOne*2 < gridSize) {
            for (i=0; i<gridSize; i++)
                grid[i][j] = 1-grid[i][j];
        }
    }

    for (i=0; i<gridSize; i++) {
        num = 0;
        for (j=0; j<gridColSize[i]; j++) {
            num = num*2 + grid[i][j];
        }
        result += num;
    }

    return result;
}
