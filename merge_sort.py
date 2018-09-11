def merge_sort(arr):
    n = len(arr)
    if n == 1:
        return arr

    lArr = merge_sort(arr[:n/2])
    rArr = merge_sort(arr[n/2:])
    return merge(lArr, rArr)

def merge(lArr, rArr):
    temp = []
    while len(lArr)>0 and len(rArr)>0:
        if lArr[0] > rArr[0]:
            temp.append(rArr[0])
            rArr.pop(0)
        else:
            temp.append(lArr[0])
            lArr.pop(0)
    while len(lArr)>0:
        temp.append(lArr[0])
        lArr.pop(0)
    while len(rArr)>0:
        temp.append(rArr[0])
        rArr.pop(0)
    return temp
