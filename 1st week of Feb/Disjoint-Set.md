# 자료 구조 : Disjoint-Set

Disjoint Set / Union - Find

Disjoint Set (분리 집합) 이란?

분리 집합은 서로소 집합이라고도 한다.
- 따라서 서로 중복되지 않는 부분 집합들로 이루어진 원소들에 대한 정보를 저장하고 조작한다.

이 자료 구조를 언제 사용하면 좋을까?

음하하 세계에는 A라는 속성을 가진 사람과 B라는 속성을 가진 사람이 있다. 
그 사람이 A라는 속성을 띄는지, B라는 속성을 띄는지 빠르게 판별해야한다.

이럴 때 그룹을 통해 표현한다면, 소요되는 시간을 대폭 단축 시킬 수 있을 것이다 !

Union - Find 알고리즘

-> 이러한 분리 집합을 구현하는 알고리즘으로, 각 그룹을 트리의 형태로 표현해준다.


부모 - 자식 형태 (부모를 체크하는 방식으로 무슨 그룹인지 파악한다.)

- 두 트리를 병합하는 작업 (Union)

- root 노드를 찾는 작업 (Find)

최적화 방법

1. Union by Rank

- Find의 시간 복잡도는 트리의 높이에 비례한다.
  -> 높이가 낮은 트리를 높이가 높은 트리에 붙인다.

2. Path Compression

- 그룹을 표현할 때 한 부모 - 다수의 자식으로 표현해준다.
(1 - 2 - 3 - 4 와 같은 일직선 구조보다, 1-2, 1-3, 1-4로 표현된 문어발 구조가 효율적이다.)

```cpp

void init(){
    for(int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}

int find(int x){

    if(x == parent[x]) return x; // 재귀적으로 탐색
    return parent[x] = find(parent[x]); // 그 노드의 부모노드를 항상 root 노드로 바꿔준다.
}

void union(int x, int y){

    x = find(x);
    y = find(y);

    if(x == y) return; // union 조건 (root가 같으면 합쳐줄 필요가 없다)

    parent[x] = y
}

```
