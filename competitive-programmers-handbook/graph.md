
# Graph

* node: vertex
* edge: link

## tree : n node, n-1 edge
```
(1)-------(2)-------(5)
 |         |
 |         |
(3)       (4)
```

## directed graph: tek yönlü
```
(3)      (4)----->(5)
 |        ^        ^
 |        |       /
 v        |      /
(1)----->(2)----/
 ^        |
 |        |
 \--------/
```

## weighted graph : edgelerin değerleri var
* edge'lerin weightleri genelde onların uzunlukları olarak alınır.
```
      5
 (1)-----(2)
  |       | \
1 |     6 |  \ 7
  |       |   \
 (3)-----(4)---(5)
      7       3
```
1,2,5   path'inin weighti : 5 + 7 = 12
1,3,4,6 path'inin weighti : 1 + 7 + 3 = 11 : bu bir shortest path!

## adjacents and degrees
* 2 tane node aralarında edge varsa adjacenttir.
* degree of a node : number of adjacents.
* bir graphtaki toplam degree 2m'dir. m = edge sayısı. (her edge 2 tane degree getiriyor)
```
(1)----(2)---(5)
 | \    | 
 |  \   |  
 |   \  |   
 |    \ |
(3)----(4)
```

* regular graph: tüm nodeların degreesi aynı ve constant
* complete graph: tüm nodeların n-1 degresi var. n = node sayısı. (yani her node diğer tüm nodelara bağlanmış)

* indegree of node : bir noda gelen directed edgeler.
* outdegree of node : bir noddan çıkan directed edgeler.

## simplicity
* simple graph:
bir noddan 2 edge çıkmaz.
bir noddan çıkan edge kendine dönmez.

işte simple olmayan bir graph
```
       (2)=======(3) (double edge)
        |         |
        |         |
 (1)   (5)-------(6)
  |    /
  |   /
 (4)-'
 / \
 \_/ (self-loop)
```


# Implementation

## adjacency list
* most popular
* array of vectors oluşturulur.

### directed graph
```
(1) ---------> (2) ---------> (3)
 ^              |              |
 |              |              |
 |              v              v
 +------------ (4) <-----------+
```

```cpp
// N node sayısı
vector<int> adj[N];

// 1'den 2'ye directed
adj[1].push_back(2);

// adj[2] = {3,4}
// 2'nin adjacent'leri vectorde
adj[2].push_back(3);
adj[2].push_back(4);

adj[3].push_back(4);
adj[4].push_back(1);
```

### undirected graph
* tüm adjacentler 2 taraflı eklenir
```cpp
vector<int> adj[N];

adj[1].push_back(2);
adj[2].push_back(1);

adj[2].push_back(3);
adj[3].push_back(2);

adj[2].push_back(4);
adj[4].push_back(2);

adj[3].push_back(4);
adj[4].push_back(3);

adj[4].push_back(1);
adj[1].push_back(4);
```

### weighted graph
```
(1) --- 5 ---> (2) --- 7 ---> (3)
 ^              |              |
 |              |              |
 2              6              5
 |              v              v
 +------------ (4) <-----------+
```

```cpp
vector<pair<int,int>> adj[N];

// node 1, node2'ye bağı, weight = 5
adj[1].push_back({2,5});

// node 2, 2 noda'a bağlı ve weightleri veirlmiş.
adj[2].push_back({3,7});
adj[2].push_back({4,6});

adj[3].push_back({4,5});
adj[4].push_back({1,2});
```



## adjacency matrix
* 2D array.
* `adj[m][n] == 1` : m nod'undan n nod'una adjacency var. (directed)

```
(1) ---------> (2) ---------> (3)
 ^              |              |
 |              |              |
 |              v              v
 +------------ (4) <-----------+
```

```cpp

int adj[5][5] = {0};

adj[1][2] = 1;
adj[2][3] = 1;
adj[2][4] = 1;
adj[3][4] = 1;
adj[4][1] = 1;
```

```
      1   2   3   4
    +---+---+---+---+
 1  | 0 | 1 | 0 | 0 |
    +---+---+---+---+
 2  | 0 | 0 | 1 | 1 |
    +---+---+---+---+
 3  | 0 | 0 | 0 | 1 |
    +---+---+---+---+
 4  | 1 | 0 | 0 | 0 |
    +---+---+---+---+
```

### weighted
```
(1) --- 5 ---> (2) --- 7 ---> (3)
 ^              |              |
 |              |              |
 2              6              5
 |              v              v
 +------------ (4) <-----------+
```

```cpp
int adj[5][5] = {0};

adj[1][2] = 5;
adj[2][3] = 7;
adj[2][4] = 6;
adj[3][4] = 5;
adj[4][1] = 2;
```



## edge list
* hangi nodlar arasında edge olduğu tutulur.

```
(1) ---------> (2) ---------> (3)
 ^              |              |
 |              |              |
 |              v              v
 +------------ (4) <-----------+
```

```cpp
vector<pair<int,int>> edges;

// node 1'den node 2'ye edge var.
edges.push_back({1,2});

edges.push_back({2,3});
edges.push_back({2,4});
edges.push_back({3,4});
edges.push_back({4,1});
```

### weighted
```
(1) --- 5 ---> (2) --- 7 ---> (3)
 ^              |              |
 |              |              |
 2              6              5
 |              v              v
 +------------ (4) <-----------+
```

```cpp
vector<tuple<int,int,int>> edges;

// node 1'den node 2'ye, 5 weightli edge var.
edges.push_back({1,2,5});

edges.push_back({2,3,7});
edges.push_back({2,4,6});
edges.push_back({3,4,5});
edges.push_back({4,1,2});

```

