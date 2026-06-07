// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int c = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++c;
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
            int left_val = arr[l];
            int right_val = arr[r];
            
            if (left_val == right_val) {
                int count = r - l + 1;
                c += count * (count - 1) / 2;
                break;
            }
            
            int left_count = 0, right_count = 0;
            while (l < r && arr[l] == left_val) {
                left_count++;
                l++;
            }
            while (l <= r && arr[r] == right_val) {
                right_count++;
                r--;
            }
            c += left_count * right_count;
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
                int j = m + 1;
                while (j < len && arr[j] == need) {
                    ++c;
                    j++;
                }
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
