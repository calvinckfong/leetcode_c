/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 1. Two Sum
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int i, j;
    int *result = malloc(2*sizeof(int));
    
    for (i=0; i<numsSize; i++) {
        for (j=i+1; j<numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return result;
}
