// //segtree 单点更新 区间查询 例子:最大值 -> arr = max
// //l  -> 当前区间    左端点逻辑下标
// //r  -> 当前区间    右端点逻辑下标
// //rt -> 在线段树里  存储下标
// #include <memory.h>
// #define mid ((l + r) >> 1)
// #define ls (rt << 1)
// #define rs (rt << 1 | 1)
// #define lson l, mid, ls
// #define rson mid + 1, r, rs
// const int maxn = 2e5 + 5;
// int arr[maxn << 2], n;
// void pushup(int rt)
// { //向上更新区间节点的统计信息
//     arr[rt] = arr[ls] > arr[rs] ? arr[ls] : arr[rs];
// }
// void build(int l, int r, int rt)
// {
//     if (l == r)
//     { //到达叶节点
//         return;
//     }
//     build(lson), build(rson);
//     pushup(rt);
// }
// void update(int node, int val, int l, int r, int rt)
// {
//     if (l == r && l == node)
//     { //到达目标节点
//         arr[rt] = val;
//         return;
//     }
//     if (node <= mid)
//         update(node, val, lson);
//     else
//         update(node, val, rson);
//     pushup(rt);
// }
// int query(int L, int R, int l, int r, int rt)
// {
//     if (L <= l && r <= R)
//         return arr[rt];
//     int ans = -1, ret;
//     if (L <= mid)
//         ret = query(L, R, lson), ans = ans > ret ? ans : ret;
//     if (mid < R)
//         ret = query(L, R, rson), ans = ans > ret ? ans : ret;
//     return ans;
// }
// #define Build() build(1, n, 1)
// #define Update(node, val) update(node, val, 1, n, 1)
// #define Query(L, R) query(L, R, 1, n, 1)
// //segtree

//-------------------------------------------------------------

// //segtree 区间更新 区间查询 和 -> arr = sum  lazy = add
// #include <memory.h>
// #define mid ((l + r) >> 1)
// #define ls (rt << 1)
// #define rs (rt << 1 | 1)
// #define lson l, mid, ls
// #define rson mid + 1, r, rs
// const int maxn = 1e5 + 5;
// int arr[maxn << 2], lazy[maxn << 2], n, m;
// void inline pushup(int rt)
// {
//     arr[rt] = arr[ls] + arr[rs];
// }
// void inline poshdown(int l, int r, int rt)
// {
//     if (lazy[rt])
//     {
//         lazy[ls] = lazy[rs] = lazy[rt];
//         arr[ls] = (mid - l + 1) * lazy[ls];
//         arr[rs] = (r - mid) * lazy[rs];
//         lazy[rt] = 0;
//     }
// }
// void build(int l, int r, int rt)
// {
//     if (l == r)
//     {
//         //到达叶节点
//         return;
//     }
//     lazy[rt]=0;
//     build(lson), build(rson);
//     pushup(rt);
// }
// void update(int L, int R, int val, int l, int r, int rt)
// {
//     if (L <= l && r <= R)
//     {
//         arr[rt] += val * (r - l + 1);
//         lazy[rt] += val;
//         return;
//     }
//     //poshdown(l, r, rt);//推不推看情况
//     if (R <= mid)
//         update(L, R, val, lson);
//     else if (L > mid)
//         update(L, R, val, rson);
//     else
//         update(L, mid, val, lson),
//         update(mid + 1, R, val, rson);
//     pushup(rt);
// }
// int query(int L, int R, int l, int r, int rt)
// {
//     if (L <= l && r <= R)
//         return arr[rt];
//     int ans = 0;
//     poshdown(l, r, rt);
//     if (L <= mid)
//         ans += query(L, R, lson);
//     if (mid < R)
//         ans += query(L, R, rson);
//     return ans;
// }
// #define Build() build(1, n, 1)
// #define Update(L, R, val) update(L, R, val, 1, n, 1)
// #define Query(L, R) query(L, R, 1, n, 1)
// //segtree

//-------------------------------------------------------------

