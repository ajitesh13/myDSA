#include <limits.h>
#include <stdio.h>
#include <string.h>
#define lli long long

const lli max_value = 2000000000000;
const lli max_n = 2000000000000;
const lli max_k = 2000000000000;
const int k = 3;
int deps[50];

lli max(lli x, lli y)
{
    return x > y ? x : y;
}

lli min(lli x, lli y)
{
    return x < y ? x : y;
}

lli sum(lli a[], lli start, lli end)
{
    lli res = 0;

    for (lli i = start; i <= end; ++i)
        res += a[i];

    return res;
}

lli k_partitioning(lli k, lli n, lli deps[])
{
    lli res = max_value;
    for (lli offset = 0; offset < n; ++offset)
    {
        lli l_min = 0;
        for (lli r_min = l_min; r_min < n; ++r_min)
        {
            lli min_sum = sum(deps, l_min, r_min);

            lli dp[k][n];
            for (lli s = 0; s < k; ++s)
            {
                for (lli q = 0; q < n; ++q)
                {
                    dp[s][q] = max_value;
                }
            }

            dp[0][r_min - l_min] = min_sum;

            for (lli p = 1; p < k; ++p)
            {
                for (lli l_max = r_min; l_max < n; ++l_max)
                {
                    for (lli r_max = l_max; r_max < n; ++r_max)
                    {
                        lli max_sum = sum(deps, l_max + 1, r_max);

                        if (max_sum >= min_sum)
                        {
                            dp[p][r_max] = min(dp[p][r_max], max(dp[p - 1][l_max], max_sum));
                        }
                    }
                }
            }

            if (dp[k - 1][n - 1] == max_value)
                continue;

            res = min(res, dp[k - 1][n - 1] - min_sum);
        }
        lli tmp[n];
        for (lli i = 0; i < n; ++i)
        {
            lli new_idx = i + n - 1;

            tmp[new_idx % n] = deps[i];
        }

        for (lli i = 0; i < n; ++i)
            deps[i] = tmp[i];
    }
    return res;
}

int main()
{

    lli n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &deps[i]);
    }

    printf("%d\n", k_partitioning(k, n, deps));

    return 0;
}