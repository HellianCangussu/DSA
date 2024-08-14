void swap(int *left, int *right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

int bubble(int array[], int size) {
  int unsorted_until_index = size - 1;
  int sorted = 0;
  while (sorted == 0) {
    sorted = 1;
    for (int i = 0; i < unsorted_until_index; i++) {
      if ((array)[i] > (array)[i + 1]) {
        swap(&(array[i]), &(array[i+1]));
        sorted = 0;
      }
    }
    unsorted_until_index -= 1;
  }
  return 1;
}

int selection(int array[], int size) {
  for (int i = 0; i < size - 1; i++)
  {
    int lowest_number_index = i;
    for (int j = i + 1; j < size; j++)
    {
      if (array[j] < array[lowest_number_index]) {
        lowest_number_index = j;
      }
    }
    if (lowest_number_index != i) {
      swap(&(array[i]), &(array[lowest_number_index]));
    }
  }
  return 1;
}

int main() {
    int arr[6] = {2,6,1,10,8, 4};
    selection(&arr, 6);
    int** l = arr;
}