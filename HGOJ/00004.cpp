#include <climits>
#include <iostream>
using namespace std;

#define MAX 1005

struct Node {
    int data = 0;
    int pos = 0;
    Node *left = nullptr;
    Node *right = nullptr;
};

int preorder[MAX] = {0}, inorder[MAX] = {0}, pos[MAX][2];
bool ifvisited[MAX] = {false};

void build_tree(Node *, int, int);
void postorder(Node *);

int main() {
    int amount = 0, i = 0, j = 0;
    cin >> amount;

    for (i = 1; i <= amount; i++) {
        cin >> preorder[i];
    }
    for (j = 1; j <= amount; j++) {
        cin >> inorder[j];
    }

    for (i = 1; i <= amount; i++) {
        for (j = 1; j <= amount; j++) {
            if (preorder[i] == inorder[j]) {
                pos[i][1] = j;
                pos[j][0] = i;
                break;
            }
        }
    }

    Node *root = new (Node);
    root->data = preorder[1];
    root->pos = pos[1][1];

    build_tree(root, 1, pos[1][1] - 1);
    build_tree(root, pos[1][1] + 1, amount);

    postorder(root);

    return 0;
}

void build_tree(Node *cur, int low, int right) {
    int next = INT_MAX, i = 0;
    if (right - low < 0) return;

    Node *save = new (Node);

    for (i = low; i <= right; i++) {
        next = min(next, pos[i][0]);
    }
    save->data = preorder[next];
    save->pos = pos[next][1];

    if (cur->pos > save->pos) {
        cur->left = save;
        build_tree(cur->left, low, save->pos - 1);
        build_tree(cur->left, save->pos + 1, right);
    } else {
        cur->right = save;
        build_tree(cur->right, low, save->pos - 1);
        build_tree(cur->right, save->pos + 1, right);
    }
}

void postorder(Node *cur) {
    if (cur->left != nullptr) postorder(cur->left);
    if (cur->right != nullptr) postorder(cur->right);

    cout << cur->data << " ";
}
