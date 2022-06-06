void QSortNoRec (int* array, int array_len){
    stack_pair st;
    stack_p_init(&st);
    int L, R, x, w, i, j;
    pair_int t;
    t.l = 0; t.r = array_len;
    stack_p_push(&st, t);
    do {
        L = stack_p_peek(&st).l;
        R = stack_p_peek(&st).r;
        stack_p_pop(&st);
        do {
            x = array[(L + R) / 2];
            i = L;
            j = R;
            do {
                while (array[i] < x)
                    i++;
                while (array[j] > x)
                    j--;
                if (i <= j){
                    w = array[i];
                    array[i] = array[j];
                    array[j] = w;
                    i++;
                    j--;
                }
            } while (i <= j);
            if (i < R){
                t.l = i;
                t.r = R;
                stack_p_push(&st, t);
            }
            R = j;
        } while (L < R);
    } while (!stack_p_isEmpty(&st));
}