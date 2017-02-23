void insertSort(int* array, int size) {
    int temp,j,i;
    for(i = 1;i < size;i++) {
        temp = array[i];
        for(j = i-1;i >= 0;j--) {
            if(array[j] > temp) {
                array[j+1] = array[j];
            }else {
                break;
            }
        }
        array[j+1] = temp;
    }
}
