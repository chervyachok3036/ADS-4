// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    for (int j = i + 1; j < len; ++j) {
      if (j > i + 1 && arr[j] == arr[j - 1]) continue;
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      ++count;
      while (left < right && arr[left] == arr[left + 1]) ++left;
      while (left < right && arr[right] == arr[right - 1]) --right;
      ++left;
      --right;
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    int target = value - arr[i];
    int lo = i + 1;
    int hi = len - 1;
    int found = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (arr[mid] == target) {
        found = mid;
        break;
      } else if (arr[mid] < target) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    if (found != -1) {
      ++count;
    }
  }
  return count;
}
