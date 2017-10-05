//从组合数的定义可以知道。C(n, m) = C(n-1, m) + C(n-1, m-1);
//所以，根据这个公式可以递归的求得组合数，代码如下：

long long C(int n, int m) {
    if(m == 0 || n == 0 || n == 1 || m == n)     return 1;
    if(aug[n][m] != 0)     return aug[n][m];

    aug[n-1][m] = C(n-1, m);
    aug[n-1][m-1] = C(n-1, m-1);

    return aug[n-1][m] + aug[n-1][m-1];
}
