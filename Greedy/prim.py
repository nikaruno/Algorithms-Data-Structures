
def get_min_key(G):
    min_ = float('inf')
    for node in G:
        if G[node] < min_:
            min_ = G[node]
            minKey = node
    del G[minKey]
    return (minKey, min_)
    

def prim(G):
    H = {}
    i = 0
    for node in G:
        if i == 0:
            H[node] = 0
        else:
            H[node] = float('inf')
        i += 1
    n = len(G)
    mstSet = {}
    while len(mstSet)<n:
        (key, value) = get_min_key(H)
        mstSet[key] = value
        for neighbor in G[key]:
            if neighbor not in mstSet:
                if G[key][neighbor] < H[neighbor]:
                    H[neighbor] = G[key][neighbor]
    return mstSet

def make_link(G, node1, node2, edge_value):
    if node1 not in G:
        G[node1] = {}
    (G[node1])[node2] = edge_value
    if node2 not in G:
        G[node2] = {}
    (G[node2])[node1] = edge_value
    return G

test_edges = [(0, 1, 4), (0, 7, 8),
              (1, 7, 11), (1, 2, 8),
              (7, 8, 7), (7, 6, 1),
              (2, 8, 2), (2, 3, 7), (2, 5, 4),
              (6, 8, 6), (6, 5, 2),
              (3, 5, 14), (3, 4, 9),
              (5, 4, 10)]

if __name__ == "__main__":
    G = {}
    for n1, n2, w in test_edges:
        make_link(G, n1, n2, w)
    
    print(prim(G))
