// bool bf()
// {
//     // h[i]=0,建了0号源点
//     bool flag = false;
//     for (int i = 1; i <= n; i++) // 如果有负环，一定会一直松弛，所以在第n轮一定有松弛操作
//     {                            // 然而第i轮不一定能够对应到第i次松弛，除非使用边数限制的bellmanford
//         // 或者开个数组记录边数
//         flag = false;
//         for (auto e : edges)
//         {
//             auto [u, v, w] = e;
//             if (dist[u] == inf)
//                 continue;
//             if (h[v] > h[u] + w)
//             {
//                 h[v] = h[u] + w;
//                 flag = true;
//             }
//         }
//         if (!flag)
//         {
//             return false;
//         }
//     }
//     return flag;
// }