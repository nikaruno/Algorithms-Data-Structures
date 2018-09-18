def make_link(G, node1, node2, edge_value):
    if node1 not in G:
        G[node1] = {}
    (G[node1])[node2] = edge_value
    if node2 not in G:
        G[node2] = {}
    (G[node2])[node1] = edge_value
    return G

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
 
if __name__ == "__main__":
           
    edges1 = [(0, 1, 5), (1, 2, 9), (0, 2, 16), (2, 3, 7)]
    edges2 = [(0, 1, 5), (1, 2, 9), (2, 3, 7)]
    edges3 = [(0, 1, 4), (0, 7, 8),
              (1, 7, 11), (1, 2, 8),
              (7, 8, 7), (7, 6, 1),
              (2, 8, 2), (2, 3, 7), (2, 5, 4),
              (6, 8, 6), (6, 5, 2),
              (3, 5, 14), (3, 4, 9),
              (5, 4, 10)]
    edges4 = [(3, 1, 2), (5, 2, 1), (2, 0, 7), (0, 1, 3), (4, 1, 10), (2, 6, 5), (5, 6, 1)]
    
    
    G = {}
    for n1, n2, w in edges4:
        make_link(G, n1, n2, w)

    print(is_cyclic(G, edges4))
