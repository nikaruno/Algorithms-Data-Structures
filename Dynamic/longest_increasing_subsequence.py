def find_longest_inc_subsequence(arr):
    n = len(arr)
    d_arr    = [0 for x in range(n)]
    d_arr[0] = 1
    sub      = [[arr[x]] for x in range(n)]
    maxi = 0
    max_index = 0
    for i in range(1, n):
        for j in range(i-1, -1, -1):
            if arr[j] < arr[i]:
                if d_arr[i]<=d_arr[j]:
                    d_arr[i] = d_arr[j]+1
                    sub[i] = sub[j] + [arr[i]]
                if d_arr[i] > maxi:
                    maxi = d_arr[i]
                    max_index = i
    return sub[max_index]

arr = [10, 22, 9, 33, 21, 50, 41, 60 ,80]
#arr = [3, 10, 2, 1, 20]
#arr = [3, 2]
#arr = [50, 3, 10, 7, 40, 80]
if __name__ == "__main__":
    print(find_longest_inc_subsequence(arr))
