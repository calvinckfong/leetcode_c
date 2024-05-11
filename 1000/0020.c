// 20. Valid Parentheses
bool isValid(char* s) {
    char stack[10000];
    int top = -1;

    while (*s) {
        if (*s=='(' || *s=='[' || *s=='{') {
            stack[++top] = *s;
        }
        else if (top<0) return false;
        else if (*s == ')' ) {
            if (stack[top] != '(') return false;
            else top--;
        }
        else if (*s == ']') {
            if (stack[top] != '[') return false;
            else top--;
        }
        else if (*s == '}') {
            if (stack[top] != '{') return false;
            else top--;
        }
        s++;
    }
    return (top==-1);
}
