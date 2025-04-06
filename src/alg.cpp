// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int n = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        n++;
      }
    }
  }
  return n;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0;
  int leftIndex = 0;
  int rightIndex = len - 1;
  while (leftIndex < rightIndex) {
      int sum = arr[leftIndex] + arr[rightIndex];
      if (sum == value) {
          k++;
          leftIndex++;
      } else if (sum < value) {
          leftIndex++;
        } else {
          rightIndex--;
      }
  }
  return k;
}
int countPairs3(int *arr, int len, int value) {
  int result = 0;
  for (int i = 0; i < len - 1; i++) {
    if (i > 0 && arr[i] == arr[i-1]) {
        continue;
    }
    int x = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] == x) {
        result++;
        int j = mid - 1;
        while (j >= left && arr[j] == x) {
          result++;
          j--;
        }
        j = mid + 1;
        while (j <= right && arr[j] == x) {
          result++;
          j++;
        }
        break;
      } else if (arr[mid] < x) {
          left = mid + 1;
      } else {
          right = mid - 1;
      }
    }
  }
  return result;
}
