def subsets(arr, num):
    if len(arr) == 1:
        return [[arr[0]], []]
    else:
        temp = subsets(arr[1:], num)
        n_arr = []
        for list_ in temp:
            n_arr.append([x_ for x_ in list_]+[arr[0]])
        for list_ in temp:
            n_arr.append([x_ for x_ in list_])
        return n_arr

def subset_sums(arr, num):
    n_arr = []
    for e in arr:
        if e == num:
            return [e]
        elif e>num:
            continue
        else:
            n_arr.append(e)
    subsets_ = subsets(n_arr, num)
    for subset in subsets_:
        if sum(subset) == num:
            return subset
    return False

if __name__ == "__main__":
    set_ = [3, 34, 4, 12, 5, 2]
    print(subset_sums(set_, 9))
