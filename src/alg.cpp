// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int n = 0;
  for (int i = 0; i < len; i++) {
    if (i == 0 || arr[i] != arr[i - 1]) {
      for (int j = i + 1; j < len; j++) {
        if (arr[i] + arr[j] == value) {
          n++;
          while (j + 1 < len && arr[j] == arr[j + 1]) {
            j++;
          }
        }
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
      if (arr[leftIndex] == arr[rightIndex]) {
        int cnt = rightIndex - leftIndex + 1;
        k += cnt * (cnt - 1) / 2;
        break;
      }
      int leftCnt = 1, rightCnt = 1;
      while (leftIndex+1 < rightIndex && arr[leftIndex] == arr[leftIndex+1]) {
        leftCnt++;
        leftIndex++;
      }
      while (rightIndex-1 > leftIndex && arr[rightIndex] == arr[rightIndex-1]) {
        rightCnt++;
        rightIndex--;
      }
      k += leftCnt * rightCnt;
      leftIndex++;
      rightIndex--;
    }
    else if (sum < value) {
      leftIndex++;
    }
    else {
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
