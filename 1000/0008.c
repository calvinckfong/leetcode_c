// 8. String to Integer (atoi)
int myAtoi(char* s) {
    long result=0;
    int sign=1, numStart=0;
    while (*s) {
        if (*s==' ' && !numStart) {
            s++;
            continue;
        } else if (*s=='+' && !numStart)
            numStart = 1;
        else if (*s=='-' && !numStart) {
            sign = -1;
            numStart = 1;
        } else if (*s>='0' && *s<='9' && result<INT_MAX) {
            result = result*10 + *s - '0';
            numStart = 1;
        } else
            break;
        s++;
    }
    result *= sign;
    if (result>INT_MAX) return INT_MAX;
    else if (result<INT_MIN) return INT_MIN;

    return result;
}
