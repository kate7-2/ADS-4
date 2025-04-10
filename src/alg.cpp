// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
   for (int j = i + 1; j < len; ++j) {
     if (arr[i] + arr[j] == value) {            
       count++;
     } else if (arr[i] + arr[j] > value){
       break; 
     }
   }
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  int left = 0, right = len - 1;
  int count = 0;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int cnt = right - left + 1;
        count += cnt * (cnt - 1) / 2;
        break;
      }
    int leftCount = 1;
    while (left + 1 < right && arr[left] == arr[left + 1]) {
      leftCount++;
      left++;
    }
    int rightCount = 1;
    while (right - 1 > left && arr[right] == arr[right - 1]) {
      rightCount++;
      right--;
    }
    count += leftCount * rightCount;
    left++;
    right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
  int result = 0;
  for (int i = 0; i < len - 1; ++i) {
    int needed = value - arr[i];
    if (needed < 0) {
      break;
    }
    int low = i + 1;
    int high = len - 1;
    int firstMatch = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (arr[mid] == needed) {
        firstMatch = mid;
        high = mid - 1;
      } else if (arr[mid] < needed) {
          low = mid + 1;
      } else {
          high = mid - 1;
      }
    }
    if (firstMatch != -1) {
      int count = 0;
      int idx = firstMatch;
      while (idx < len && arr[idx] == needed) {
        count++;
        idx++;
      }
      result += count;
    }
  }
  return result;
}
