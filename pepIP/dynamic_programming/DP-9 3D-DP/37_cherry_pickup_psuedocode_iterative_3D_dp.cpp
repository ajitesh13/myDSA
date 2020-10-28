for (int r1=0; r1<arr.size(); r++) {
    for (int c1=0; c1<arr[0].size(); c1++) {
        for (int r2 = 0; r2 < arr.size(); r2++) {
            int c2 = r1 + c1 - r2;
            if (arr[r1][c1] == -1 || arr[r2][c2] == -1) {
                continue;
            }
            int temp = max(dp[r1-1][c1][r2], dp[r1-1][c1][r2], dp[r1][c1-1][r2], dp[r1][c1-1][r2]);
            int cherry;
            if (r1 == r2 && c1 == c2) {
                cherry = arr[r1][c1];
            } else {
                cherry = arr[r1][c1] + arr[r2][c2];
            }
            if (temp > 0) {
                cherry += temp;
            }
            dp[r1][c1][r2] = cherry;
        }
    }
}