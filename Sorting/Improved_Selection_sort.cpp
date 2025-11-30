void improvedSelectionSort(vector<int> &a) {
    int left = 0;
    int right = a.size() - 1;

    while(left < right) {
        int minIndex = left;
        int maxIndex = right;

        // Important: if the left element is > right element swap roles
        if(a[minIndex] > a[maxIndex])
            swap(minIndex, maxIndex);

        // scan between left and right
        for(int i = left + 1; i <= right - 1; i++) {
            if(a[i] < a[minIndex])
                minIndex = i;
            else if(a[i] > a[maxIndex])
                maxIndex = i;
        }

        // place minimum at left
        swap(a[left], a[minIndex]);

        // if max element was at left, it moved to minIndex after the previous swap
        if(maxIndex == left)
            maxIndex = minIndex;

        // place maximum at right
        swap(a[right], a[maxIndex]);

        left++;
        right--;
    }
}
