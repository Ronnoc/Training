struct KMP {//调用init(s(待匹配串),t(模式串));适用多次KMP
    char S[MXN], T[MXN];
    int next[MXN], is[MXN];
    int LT, LS;
    void init(char s[], char t[]) {
        int i;
        LT = strlen(t);
        LS = strlen(s);
        for(i = 0; i <= LT; i++) T[i] = t[i];
        for(i = 0; i <= LS; i++) S[i] = s[i];
    }
    void getnext() {
        int i, j;
        next[0]=-1; next[1] = 0;
        for (i = 1, j = 0; i < LT; ) {
            while (j != -1 && T[i] != T[j]) j = next[j];
            i++; j++;
            next[i] = j;
        }
    }
    void kmp() {
        int i, j;
        for(i = 0; i < LS; i++) is[i] = 0;
        for (i = 0, j = 0; i < LS; i++) {
            while (j != -1 && S[i] != T[j]) j = next[j];
            j++;
            if (j == LT) {
                is[i - LT + 1] = 1;
                j = next[j];
            }
        }
    }
}kmp;