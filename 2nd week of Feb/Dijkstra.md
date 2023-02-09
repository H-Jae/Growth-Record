# Algorithm : Dijkstra

#### Base Setting

```cpp

if ( connect(v,w) ) {
    distance[v][w] = 
}
else{
    distance[v][w] = INF;
}


```

#### How to do?

1. Set the starting node.
2. Store minimum cost of each node based on the starting node.
3. Select the least cost node from the unvisited nodes.
4. Update the minimum cost in consideration of going through that node to a specific node.
5. Repeat 3-4

