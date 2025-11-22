

void swap(int* v1, int* v2)
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

int partition(int low, int high, int values[])
{
    int pivot = values[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (values[j] < pivot) {
            i++;
            swap(&values[i], &values[j]);
        }
    }
    swap(&values[i + 1], &values[high]);
    return i + 1;
}

void quickSort(int values[], int low, int high)
{
    if (low < high) {
        int pi = partition(low, high, values);
        quickSort(values, pi + 1, high);
        quickSort(values, low, pi - 1);
    }
}
