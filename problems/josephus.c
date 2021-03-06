// File: josephus.c
// Created by hengxin on 17-10-10.
// Solving the Josephus problem

#include <stdio.h>

#define KILLED 0

int josephus(int n);
int next_alive(int soldier[], int num, int pos);
void test_josephus(int limit);

int main() {
//    int n = 0;
//    puts("Enter the number of soldiers:");
//    scanf("%d", &n);
//
//    int survivor = josephus(n);
//    printf("The survivor is: %d", survivor + 1);

    int limit = 0;
    puts("Enter the number of soldiers:");
    scanf("%d", &limit);

    test_josephus(limit);
}

/**
 * Return the array index of the survivor.
 */
int josephus(int n) {
    int soldier[n];
    for (int i = 0; i < n; ++i)
        soldier[i] = i + 1;

    int killed_count = 0;

    int killer = 0;
    while (killed_count < n - 1) {
        // Note: killed will never be the killer
        int killed = next_alive(soldier, n, killer);
//        printf("%p", &killed);

        soldier[killed] = KILLED;
        killed_count++;

        // Note: killer may be the one to be killed;
        // the condition `killed_count < n - 1` ensures no suicide.
        killer = next_alive(soldier, n, killed);
    }

    return killer;
}

/**
 * Return the array index of the next soldier
 * who is still alive, starting from @param pos.
 *
 * If no other alive soldiers (except soldier[pos]) exist,
 * pos will be returned.
 *
 * Precondition: soldier[pos] != KILLED
 */
int next_alive(int soldier[], int num, int pos) {
    do {
        pos = (pos + 1) % num;
    } while (soldier[pos] == KILLED);

    return pos;
}

/**
 * Test the function `josephus` with 1 .. limit
 * as the numbers of soldiers.
 */
void test_josephus(int limit) {
    for (int i = 1; i <= limit; ++i)
        printf("%d: %d\n", i, josephus(i) + 1);
}
