// 9. Palindrome Number
bool isPalindrome(int x) {
    long reverse=0, xx=x;
    if (x<0) return false;

    while (xx) {
        reverse = reverse*10 + (xx%10);
        xx/=10;
    }

    return (reverse==x);
}
