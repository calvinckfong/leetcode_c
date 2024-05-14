// 1219. Path with Maximum Gold
int getGold(int** grid, int i, int j, int m, int n, int amount) {
    if (grid[i][j]==0) return amount;
    int lastAmount = grid[i][j];
    grid[i][j]=0;

    int tmp, maxAmount = amount;
    if (i>0) {
        tmp = getGold(grid, i-1, j, m, n, amount+lastAmount);
        if (tmp>maxAmount) maxAmount=tmp;
    }
    if (i<m-1) {
        tmp = getGold(grid, i+1, j, m, n, amount+lastAmount);
        if (tmp>maxAmount) maxAmount=tmp;
    }
    if (j>0) {
        tmp = getGold(grid, i, j-1, m, n, amount+lastAmount);
        if (tmp>maxAmount) maxAmount=tmp;
    }
    if (j<n-1) {
        tmp = getGold(grid, i, j+1, m, n, amount+lastAmount);
        if (tmp>maxAmount) maxAmount=tmp;
    }
    grid[i][j]=lastAmount;
    return maxAmount;
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize) {
    int result = 0;

    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridColSize[0]; j++) {
            int amount = getGold(grid, i, j, gridSize, gridColSize[0], 0);
            if (amount>result) result = amount;
        }
    }

    return result;
}
