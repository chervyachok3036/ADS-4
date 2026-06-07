// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int c = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            int s = arr[i] + arr[j];
            if (s == value) {
                ++c;
            } else if (s > value) {
                break;
            }
        }
    }
    return c;
}

int countPairs2(int *arr, int len, int value) {
    int c = 0;
    int l = 0;
    int r = len - 1;
    while (l < r) {
        int s = arr[l] + arr[r];
        if (s == value) {
            ++c;
            ++l;
            --r;
        } else if (s < value) {
            ++l;
        } else {
            --r;
        }
    }
    return c;
}

int countPairs3(int *arr, int len, int value) {
    int c = 0;
    for (int i = 0; i < len; ++i) {
        int need = value - arr[i];
        int l = i + 1;
        int r = len - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] == need) {
                ++c;
                break;
            } else if (arr[m] < need) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }
    return c;
}
