// 3. Longest Substring Without Repeating Characters
#define MAX(a,b) ((a)>(b))?(a):(b)
int lengthOfLongestSubstring(char* s) {
    int hist[32*3], result=0;
    for (int i=0; i<3*32; i++) hist[i] = 0;

    int l=0, r=0;
    while (s[r] != 0) {
        char c = s[r++];
        hist[c-' ']++;
        while (hist[c-' ']>1) {
            hist[s[l++]-' ']--;
        }
        result = MAX(result, r-l);
    }

    return result;
}
