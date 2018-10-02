def find_lcs(arr1, arr2):
    n = len(arr1)
    m = len(arr2)
    tbl = [["" for m_ in range(m+1)] for n_ in range(n+1)]    
    for i in range(1, n+1):
        for j in range(1, m+1):
            if arr1[i-1] == arr2[j-1]:
                tbl[i][j] = tbl[i-1][j-1] + arr1[i-1]
            else:
                if len(tbl[i][j-1]) > len(tbl[i-1][j]):    
                    tbl[i][j] = tbl[i][j-1]
                else:
                    tbl[i][j] = tbl[i-1][j]

    return tbl[n][m]


def find_lcs_length(arr1, arr2):
    n = len(arr1)
    m = len(arr2)
    tbl = [[0 for m_ in range(m+1)] for n_ in range(n+1)]
    for i in range(1, n+1):
        for j in range(1, m+1):
            if arr1[i-1] == arr2[j-1]:
                tbl[i][j] = tbl[i-1][j-1] + 1
            else:
                tbl[i][j] = max(tbl[i][j-1], tbl[i-1][j])

    return tbl[n][m]

if __name__ == "__main__":
    arr1 = "ABCDGH"
    arr2 = "AEDFHR"
    #arr1 = "AGGTAB"
    #arr2 = "GXTXAYB"
    print(find_lcs(arr1, arr2))
