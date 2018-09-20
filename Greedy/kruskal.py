def find_parent(parent, i):
    while parent[i] != i:
        temp = i
        i = parent[i]
        parent[temp] = parent[i]
    return i

def union(parent, rank, i, j):
    p_i = find_parent(parent, i)
    p_j = find_parent(parent, j)
    if rank[p_i] < rank[p_j]:
        parent[p_i] = p_j
    elif rank[p_i] > rank[p_j]:
        parent[p_j] = p_i
    else:
        parent[p_j] = p_i
        rank[p_i] += 1

def is_cyclic(G, edges):
    parent = {}
    rank = {}
    for node in G:
        parent[node] = node
        rank[node]   = 0
    for node1, node2, weight in edges:
        pNode1 = find_parent(parent, node1)
        pNode2 = find_parent(parent, node2)
        if pNode1 == pNode2:
            return True
        union(parent, rank, node1, node2)
    return False

def make_link(G, node1, node2, edge_value):
    if node1 not in G:
        G[node1] = {}
    (G[node1])[node2] = edge_value
    if node2 not in G:
        G[node2] = {}
    (G[node2])[node1] = edge_value
    return G

def remove_link(G, node1, node2, edge_value):
    del G[node1][node2]
    if len(G[node1]) == 0:
        del G[node1]
    del G[node2][node1]
    if len(G[node2]) == 0:
        del G[node2]

def kruskal(G, edges):
    n = len(G)-1 #number of edges for MST
    edges.sort(key=lambda x:x[2])
    m = len(edges)
    H = {}
    make_link(H, edges[0][0], edges[0][1], edges[0][2])
    mstEdges = []
    mstEdges.append(edges[0])
    i = 1
    while len(mstEdges)<n:
        make_link(H, edges[i][0], edges[i][1], edges[i][2])
        mstEdges.append(edges[i])
        if is_cyclic(H, mstEdges):
            remove_link(H, edges[i][0], edges[i][1], edges[i][2])
            mstEdges.pop()
        i += 1
    return H

        
if __name__ == "__main__":
    
    edges = [(0, 1, 4), (0, 7, 8),
              (1, 7, 11), (1, 2, 8),
              (7, 8, 7), (7, 6, 1),
              (2, 8, 2), (2, 3, 7), (2, 5, 4),
              (6, 8, 6), (6, 5, 2),
              (3, 5, 14), (3, 4, 9),
              (5, 4, 10)]
    
    G = {}
    for n1, n2, w in edges:
        make_link(G, n1, n2, w)
    
    print (kruskal(G, edges))
