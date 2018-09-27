def make_link(G, node1, node2, edge_value):
    if node1 not in G:
        G[node1] = {}
    (G[node1])[node2] = edge_value
    if node2 not in G:
        G[node2] = {}
    (G[node2])[node1] = edge_value
    return G

def bfs(G, start):
    marked = {}
    for node in G:
        marked[node] = False
    pipe = [start]
    marked[start] = True
    while pipe:
        nextNode = pipe.pop(0)
        for neighbor in G[nextNode]:
            if marked[neighbor]:
                continue
            else:
                pipe.append(neighbor)
                print(neighbor)
                marked[neighbor] = True
    

if __name__ == "__main__":
    test_edges = [(0, 1), (0, 2), (1, 2), (2, 0), (2, 3), (3, 3)]
    G = {}
    for n1, n2 in test_edges:
        make_link(G, n1, n2, 1)
    
    bfs(G, 2)


