def find_path_(mtx, i, j, n, m, i_, j_, marked):
    lPath = []
    rPath = []
    marked[i][j] = True
    if i>0:
        if abs(mtx[i][j]-mtx[i-1][j]) == 1 and not (i-1 == i_ and j == j_):
            if mtx[i][j]-mtx[i-1][j]<0:
                rPath = find_path_(mtx, i-1, j, n, m, i, j, marked)
            else:
                lPath = find_path_(mtx, i-1, j, n, m, i, j, marked)
    if j>0:
        if abs(mtx[i][j]-mtx[i][j-1]) == 1 and not (i == i_ and j-1 == j_):
            if mtx[i][j]-mtx[i][j-1]<0:
                rPath = find_path_(mtx, i, j-1, n, m, i, j, marked)
            else:
                lPath = find_path_(mtx, i, j-1, n, m, i, j, marked)        
    if i<n-1:
        if abs(mtx[i][j]-mtx[i+1][j]) == 1 and not (i+1 == i_ and j == j_):
            if mtx[i][j]-mtx[i+1][j]<0:
                rPath = find_path_(mtx, i+1, j, n, m, i, j, marked)
            else:
                lPath = find_path_(mtx, i+1, j, n, m, i, j, marked)
    if j<m-1:
        if abs(mtx[i][j]-mtx[i][j+1]) == 1 and not (i == i_ and j+1 == j_):
            if mtx[i][j]-mtx[i][j+1]<0:
                rPath = find_path_(mtx, i, j+1, n, m, i, j, marked)
            else:
                lPath = find_path_(mtx, i, j+1, n, m, i, j, marked)
    return lPath + [mtx[i][j]] + rPath

def find_path(mtx, i, j, n, m, marked):
    lPath = []
    rPath = []
    marked[i][j] = True
    if i>0:
        if abs(mtx[i][j]-mtx[i-1][j]) == 1:
            if mtx[i][j]-mtx[i-1][j]<0:
                rPath = find_path_(mtx, i-1, j, n, m, i, j, marked)
            else:
                lPath = find_path_(mtx, i-1, j, n, m, i, j, marked)
    if j>0:
        if abs(mtx[i][j]-mtx[i][j-1]) == 1:
            if mtx[i][j]-mtx[i][j-1]<0:
                rPath = find_path_(mtx, i, j-1, n, m, i, j, marked)
            else:
                lPath = find_path_(mtx, i, j-1, n, m, i, j, marked)        
    if i<n-1:
        if abs(mtx[i][j]-mtx[i+1][j]) == 1:
            if mtx[i][j]-mtx[i+1][j]<0:
                rPath = find_path_(mtx, i+1, j, n, m, i, j, marked)
            else:
                lPath = find_path_(mtx, i+1, j, n, m, i, j, marked)
    if j<m-1:
        if abs(mtx[i][j]-mtx[i][j+1]) == 1:
            if mtx[i][j]-mtx[i][j+1]<0:
                rPath = find_path_(mtx, i, j+1, n, m, i, j, marked)
            else:
                lPath = find_path_(mtx, i, j+1, n, m, i, j, marked)
    return lPath + [mtx[i][j]] + rPath

def longest_path(mtx):
    n = len(matrix)
    m = len(matrix[0])
    paths = [[[matrix[x_][y_]] for y_ in range(m)] for x_ in range(n)]
    marked = [[False for y_ in range(m)] for x_ in range(n)] 
    for i in range(n):
        for j in range(m):
            if not marked[i][j]:
                paths[i][j] = find_path(matrix, i, j, n, m, marked)
    print(paths)

if __name__ == "__main__":
    matrix = [[1, 2, 9], [5, 3, 8], [4, 6, 7]]
    longest_path(matrix)
