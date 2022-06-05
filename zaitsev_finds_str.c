static int str_size (const char* str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

static void prefix (const char* sub, int *prefix, int sub_size){
    prefix[0] = 0;
    int i = 1, j = 0;
    while (i != sub_size){
        if (sub[i] != sub[j]){
            if (j == 0){
                prefix[i] = 0;
                i++;
            } else {
                j = prefix[j - 1];
            }
        } else {
            prefix[i] = j + 1;
            i++;
            j++;
        }
    }
}
int KMP (const char* str, const char* sub){
    int strSize = str_size(str);
    int subSize = str_size(sub);
    int p[512];
    prefix(sub, p, subSize);
    int j = 0, i = 0;
    while (i != strSize){

        if (str[i] == sub[j]){
            i++;
            j++;
        }
        if (j == subSize){
            return i - subSize;
        }
        else if (str[i] != sub[j] && j != 0){
            j = p[j - 1];
        } else if (str[i] != sub[j] && j == 0){
            i++;
        }
    }
    return -1;
}

static void sheet (const char* sub, int *d, int sub_size){
    for(int i = 2; i <= sub_size; i++){
        if(d[sub[sub_size - i]] > i - 1)
            d[sub[sub_size - i]] = i - 1;
    }
}
int BMH (const char* str, const char* sub){
    int subSize = str_size(sub);
    int strSize = str_size(str);
    int d[256];
    for (int ii = 0; ii < 256; ii++){
        d[ii] = subSize;
    }
    sheet(sub, d, subSize);
    int i = subSize - 1, j = subSize - 1, c = 0;
    while (i < strSize){
        printf("%d %d\n", i, j);
        if(str[i] == sub[j]){
            if(j == 0)
                return i;
            i--;
            j--;
            c++;
        }
        else {
            i += d[sub[j - 1]] + c;
            j = subSize - 1;
            c = 0;
        }
    }
    return -1;
}

static int hashing (const char* str, int begin, int end){
    int hash = str[1 + begin] + 10*str[0 + begin];
    for(int i = 2 + begin; i < end; i++){
        hash += str[i] + 10*hash;
    }
    return hash;
}
int RK (const char* str, const char* sub){
    int strSize = str_size(str);
    int subSize = str_size(sub);
    int subHash = hashing(sub, 0, subSize);
    for(int i = 0; i < strSize - subSize + 1; i++){
        if (subHash == hashing(str, i, i + subSize)){
            bool isComp = true;
            for (int j = 1; j < subSize; j++){
                if (sub[j] != str[j + i]){
                    isComp = false;
                }
            }
            if (isComp)
                return i;
        }
    }
    return -1;
}
