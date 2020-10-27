// recursive pseudocode for cherry pickup in 4d dp

int cherry(vector<vector<int>> arr, int r1, int c1, int r2, int c2) {
    // as we are taking out the max then taking negetive infinity will 
    // make them ignore
    if (
        r1 >= arr.size() || 
        r2 >= arr.size() ||
        c1 >= arr.size() ||
        c2 >= arr.size() ||
        arr[r1][c1] == -1 ||
        arr[r2][c2] == -1
    ) {
        return negetive-infinity;
    }

    if (dp[r1][c1][r2][c2] != NULL) {
        return dp[r1][c1][r2][c2];
    }

    // when reach the last box return whatever there in the last box, no need for
    // more calls from there
    if (r1 == arr.size()-1 && c1 == arr.size()-1) {
        return arr[r1][c1];
    }
    if (r2 == arr.size()-1 && c2 == arr.size()-1) {
        return arr[r2][c2];
    }

    int cherry = 0;
    if (r1 == r2 && c1 == c2) {
        cherry += arr[r1][c1];
    } else {
        cherry += arr[r1][c1] + arr[r2][c2];
    }

    // recursive calls for the movement of both the players
    int temp1 = cherry(arr, r1+1, c1, r2 + 1, c2);
    int temp2 = cherry(arr, r1+1, c1, r2, c2+1);
    int temp3 = cherry(arr, r1, c1+1, r2+1, c2);
    int temp4 = cherry(arr, r1, c1+1, r2, c2+1);

    cherry += max(temp1, temp2, temp3, temp4);
    dp[x1][c1][r2][c2] = cherry;
    return cherry;
}