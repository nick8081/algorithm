void quickSort(int* a, int size) {
    if (a == NULL || size <= 1) {
        return;
    }

    int key = 0;
    int last = size - 1;
    for (int i = 1; i <= last;) {
        if (a[i] < a[key]) {
            int t = a[key];
            a[key] = a[i];
            a[i] = t;
            key = i;
            i++;
        }
        else {
            int t = a[i];
            a[i] = a[last];
            a[last] = t;
            last--;
        }
    }

    quickSort(a, key);
    quickSort(a + key + 1, size - key - 1);
}