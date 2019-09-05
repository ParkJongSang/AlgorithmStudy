
#include <cstdio>
#include <cstring>

struct air {
    int x, y;
};

int r, c, t, s1=-1, s2, ans;
int a[50][50];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void diffuse() {
    int b[50][50] = {0};
    memcpy(b, a, sizeof(a));
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (a[i][j] >= 5) {
                int d = a[i][j]/5;
                for (int k=0; k<4; k++) {
                    int ni = i+dx[k], nj = j+dy[k];
                    if (0 <= ni && ni < r && 0 <= nj && nj < c && a[ni][nj] != -1) {
                        b[ni][nj] += d;
                        b[i][j] -= d;
                    }
                }
            }
        }
    }
    memcpy(a, b, sizeof(b));
}

void purify() {
    // Top purifier
    for (int i=s1-2; i>=0; i--) a[i+1][0] = a[i][0];  // ↓
    for (int i=0; i<c-1; i++) a[0][i] = a[0][i+1];    // ←
    for (int i=0; i<s1; i++) a[i][c-1] = a[i+1][c-1]; // ↑
    for (int i=c-2; i>=0; i--) a[s1][i+1] = a[s1][i]; // →
    a[s1][1] = 0;
    // Bottom purifier
    for (int i=s2+1; i<r-1; i++) a[i][0] = a[i+1][0];   // ↑
    for (int i=0; i<c-1; i++) a[r-1][i] = a[r-1][i+1];  // ←
    for (int i=r-2; i>=s2; i--) a[i+1][c-1] = a[i][c-1];// ↓
    for (int i=c-2; i>=0; i--) a[s2][i+1] = a[s2][i];   // →
    a[s2][1] = 0;
}

void solve() {
    while (t--) {
        diffuse();
        purify();
    }
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (a[i][j] > 0) {
                ans += a[i][j];
            }
        }
    }
    printf("%d\n", ans);
}


int main() {
    scanf("%d %d %d", &r, &c, &t);
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == -1) {
                // s1 (top), s2 (bottom)
                if (s1 == -1) s1 = i;
                else s2 = i;
            }
        }
    }
    solve();
    return 0;
}