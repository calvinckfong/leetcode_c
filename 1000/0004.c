// 4. Median of Two Sorted Arrays
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int c = (nums1Size+nums2Size)/2+1;
    int prev, result;
    int p1=0, p2=0;

    for (int i=0; i<c; i++)
    {
        if (p1<nums1Size && (p2>=nums2Size || nums1[p1] < nums2[p2]))
        {
            prev = result;
            result = nums1[p1++];
        }
        else
        {
            prev = result;
            result = nums2[p2++];
        }
    }

    if ((nums1Size+nums2Size)%2)
        return (1.0*result);
    else
        return 0.5*(prev+result);
}
