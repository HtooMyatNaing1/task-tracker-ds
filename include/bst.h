#ifndef BST_H
#define BST_H

typedef struct Member {
    char name[50];
    int score;
    int tasksCompleted;
    int free; // 1 = available, 0 = busy
    struct Member* left;
    struct Member* right;
} Member;

void insertMemberBST(char* name);
Member* searchMemberBST(char* name);
void searchTaskBST();
void updateMemberBST(char* name, int points);
void displayMemberBST(Member* root);
void freeBST();

#endif