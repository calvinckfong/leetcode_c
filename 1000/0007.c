// 7. Reverse Integer
int reverse(int x){
    long sign = (x>0)?1:-1;
    long result = 0, xx = x*sign;
    while (xx) {
        result = result*10 + (xx%10);
        xx/=10;
    }
    if (result>pow(2L,31)) return 0;
    return result*sign;
}
