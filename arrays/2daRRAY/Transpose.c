int main(){
    int a[10][10], transpose[10][10], r, c, i, j;

    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) {
            transpose[j][i] = a[i][j];
        }
}