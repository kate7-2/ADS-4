// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
     if (arr[i] + arr[j] == value) {
       count++;
     }
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
   int k = 0;
  int topline = len - 1;
  while (topline > 0) {
    if (arr[topline] > value) {
      topline--;
    } else {
      break;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = topline; j > i; j--) {
      if (arr[i] + arr[j] == value)
        k++;
    }
  }
  return k;
}
int countPairs3(int* arr, int len, int value) {
  int result = 0;
  for (int i = 0; i < len - 1; ++i) {
    int target = value - arr[i];
    if (target < 0) break;
    int l = i + 1, r = len - 1;
    int left = -1, right = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (arr[m] < target) {
        l = m + 1;
      } else if (arr[m] == target) {
          left = m;
          r = m - 1;
        } else break;
    }
    l = i + 1;
    r = len - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (arr[m] > target) {
        r = m - 1;
      } else if (arr[m] == target) {
          right = m;
          l = m + 1;
      } else break;
    }
    if (left != -1 && right != -1 && right >= left) {
      result += (right - left + 1);
    }
  }
  return result;
}
