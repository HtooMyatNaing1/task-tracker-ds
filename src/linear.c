#include <stdio.h>
#include <string.h>
#include "linear.h"

#define MAX 100

typedef struct {
    char name[50];
    int score;
    int tasksCompleted;
    int free;
} LinearMember;

LinearMember memberRoster[MAX];
int memberCount = 0;

void insertMemberLinearly(char* name) {
    if (memberCount >= MAX) {
        printf("Member roster full!\n");
        return;
    }

    strcpy(memberRoster[memberCount].name, name);
    memberRoster[memberCount].score = 0;
    memberRoster[memberCount].tasksCompleted = 0;
    memberRoster[memberCount].free = 1;

    memberCount++;
}

int searchMemberLinearly(char* name) {
    for (int i = 0; i < memberCount; i++) {
        if (strcmp(memberRoster[i].name, name) == 0)
            return i;
    }

    return -1;
}

int getLinearSearchComparisons(char* name) {
    int comparisons = 0;

    for (int i = 0; i < memberCount; i++) {
        comparisons++;

        if (strcmp(memberRoster[i].name, name) == 0)
            return comparisons;
    }

    return comparisons;
}