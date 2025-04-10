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
    while (l<=r) {
      int m = l + (r - l)/2;
      if (arr[m] < target) {
        l = m + 1;
      } else if (arr[m]>target) {
          r = m - 1;
      } else {
          result++;
          int left = m - 1;
          int right = m + 1;  
          while (left > i && arr[left] == target) {
            result++;
            left--;
          }
          while (right < len && arr[right] == target) {
            result++;
            right++;
          }
          break;
      }
    }
  }
  return result;
}
