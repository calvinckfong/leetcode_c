// 12. Integer to Roman
char* intToRoman(int num) {
    const char lut[34][5] = {
        "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
        "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
        "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
        "", "M", "MM", "MMM"
    };

    char *result = calloc(20, 1);
    int offset=30, base=1000, d;
    while (base) {
        if (num>=base) {
            d = num/base;
            strcat(result, lut[offset+d]);
            num -= d*base;
        }
        offset-=10;
        base/=10;
    }

    return result;
}
