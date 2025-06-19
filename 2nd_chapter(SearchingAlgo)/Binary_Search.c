#include <stdio.h>
int binary_s(int a[], int x, int l, int r) {
  if (l > r) {
    return -1;
  }
  int mid = (l + r) / 2;
  if (a[mid] == x) {
    return mid;
  }
  return (x > a[mid]) ? binary_s(a, x, mid + 1, r)
                      : binary_s(a, x, l, mid - 1);
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("%d\n", binary_s(arr, x, 0, n - 1));
  return 0;
}