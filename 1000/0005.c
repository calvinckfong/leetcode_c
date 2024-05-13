// 5. Longest Palindromic Substring
char* longestPalindrome(char* s) {
    int n=0, maxlen=0, l, r;
    int bestL, bestR;
    char* c = s;
    while (*c) {n++; c++;} // get the length of s

    for (int i=0; i<n; i++) {
        // palindrome string of odd len
        l=r=i;
        while (l>=0 && r<n && s[l]==s[r]) {
            if (r-l+1 > maxlen) {
                maxlen = r-l+1;
                bestR=r;
                bestL=l;
            }
            l--; r++;
        }

        // palindrome string of even len
        l=i; r=i+1;
        while (l>=0 && r<n && s[l]==s[r]) {
            if (r-l+1 > maxlen) {
                maxlen = r-l+1;
                bestR=r;
                bestL=l;
            }
            l--; r++;
        }
    }

    s[bestR+1] = 0;
    return s+bestL;
}
