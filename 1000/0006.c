// 6. Zigzag Conversion
char* convert(char* s, int numRows) {
    if (numRows==1) return s;
    int* ptr = calloc(numRows, sizeof(int));
    char* ss = s;
    char** temp = malloc(numRows * sizeof(char*));
    for (int i=0; i<numRows; i++) {
        temp[i] = (char*)calloc(1000, sizeof(char));
    }
    int n=0, l=0, dir=1;

    while (*ss) {
        // printf("%c ptr[%d]=%d\n", *ss, l, ptr[l]);
        temp[l][ptr[l]++] = *ss;
        ss++;
        l+=dir;
        if (l==0) dir=1;
        else if (l==numRows-1) dir=-1;
    }

    // concat all rows to result
    s[0] = 0;
    for (int i=0; i<numRows; i++) {
        strcat(s, temp[i]);
    }
    // clean up
    free(ptr);
    for (int i=0; i<numRows; i++)
        free(temp[i]);
    free(temp);

    return s;
}
