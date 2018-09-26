def floyd_warshall(n, edges):
    G = [[float('inf') for j_ in range(n)] for i_ in range(n)]
    for i in range(n):
        G[i][i] = 0
    for a, b, w in edges:
        G[a][b] = w
    for k in range(n):
        for i in range(n):
            for j in range(n):
                G[i][j] = min(G[i][j], G[i][k]+G[k][j])

    return G


edges = [(0, 1, 4), (0, 7, 8),
          (1, 7, 11), (1, 2, 8),
          (7, 8, 7), (7, 6, 1),
          (2, 8, 2), (2, 3, 7), (2, 5, 4),
          (6, 8, 6), (6, 5, 2),
          (3, 5, 14), (3, 4, 9),
          (5, 4, 10)]

if __name__ == "__main__":
    n = 9
    G = floyd_warshall(n, edges)
    for i in range(n):
        print(G[i])
