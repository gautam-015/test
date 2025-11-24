#include<stdio.h>

void toh(int n, char source, char dest, char aux) {
    if(n == 1) {
        printf("Move disk 1 from %c -> %c\n", source, dest);
        return;
    }
    toh(n - 1, source, aux, dest);   // move n-1 disks to aux
    printf("Move disk %d from %c -> %c\n", n, source, dest); // move nth disk
    toh(n - 1, aux, dest, source);   // move n-1 disks to dest
}

int main() {
    int n = ;
    toh(n, 'A', 'B', 'C');
    return 0;
}