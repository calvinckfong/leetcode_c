// 11. Container With Most Water
inline int MAX(int a, int b) {
    return (a>b)?a:b;
}
inline int MIN(int a, int b) {
    return (a<b)?a:b;
}
int maxArea(int* height, int heightSize) {
    int l=0, r=heightSize-1;
    int area, result=0;//(r-l)*MIN(height[l], height[r]);
    while (r>l) {
        area = (r-l)*MIN(height[l], height[r]);
        result = MAX(result, area);
        if (height[l]>height[r])
            r--;
        else
            l++;
    }
    return result;
}
