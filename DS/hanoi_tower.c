#include <stdio.h>

void hanoi(int n, char from, char middle, char to);
int main() {
    int n;
    printf("원판의 개수를 입력하시오:");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    printf("총 이동 횟수: %d\n", (1 << n) - 1);
    return 0;
}
void hanoi(int n, char from, char middle, char to) {
    if(n == 0) return;
    hanoi(n - 1, from, to, middle);
    printf("%d번 원판을 %c에서 %c로 이동\n", n, from, to);
    hanoi(n - 1, middle, from, to);
}