def bubble_sort(arr):
    n = len(arr)
    for j in xrange(n-1):
        for i in xrange(1, n-j):
            if arr[i]<arr[i-1]:
                temp = arr[i]
                arr[i] = arr[i-1]
                arr[i-1] = temp
    return
