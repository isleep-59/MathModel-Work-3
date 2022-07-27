# Routine

1. 设dij为ij两点间直线距离，mdij为在矩阵上从i走到j的最短距离，kdij为ij两点在最小生成树上最短距离
2. 对所有的点执行：`if(mdij <= dij)`则直接`merge(i, j)`，否则不管
3. 再执行kruskal，因为kruskal采用了并查集，而在上一步中，ij两点间比最小生成树上距离更优的解已经被选出来并且执行了合并，所以剩下的点直接执行kruskal得到的便是最优解