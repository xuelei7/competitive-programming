# ABC254 B - Practical Computing

[solution](b.cpp)

素直に実装します．

Implement as it described in the problem.

まず，$N \times N$ の配列を用意する．

Make a $N \times N$ array. And calculate the array according to the definitions.

次に，説明した通りのように配列の中身を計算し，出力する．
- $j = 0$ または $j = i$ のとき，$a_{i, j} = 1$
- それ以外の時，$a_{i, j} = a_{i-1, j} + a_{i-1, j}$
