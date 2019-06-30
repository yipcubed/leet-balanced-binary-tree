#include <cstring>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>


using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 // print it by level
ostream& operator<<(ostream& os, TreeNode* tr) {
  queue<TreeNode*> q;
  bool first = true;
  os << "[";
  if (tr) q.push(tr);
  while (!q.empty()) {
    int nodeCount = q.size();
    while (nodeCount > 0) {
      TreeNode* tp = q.front();
      q.pop();
      if (first) {
        os << tp->val;
        first = false;
      } else {
        os << "," << tp->val;
      }
      if (tp->left) q.push(tp->left);
      if (tp->right) q.push(tp->right);
      --nodeCount;
    }
  }
  os << "]";
  return os;
}

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:

    int depth(TreeNode* root, bool& balanced) {
      if (!root) return 0;
      int rt = depth(root->right, balanced);
      int lt = depth(root->left, balanced);
      if (abs(rt -lt) > 1) {
        balanced = false;
      }
      return 1 + max(rt, lt);
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool balanced = true;
        int dp = depth(root, balanced);
        return balanced;
    }
};

void test1() {
  Solution S;
  // 3,9,20,null,null,15,7
  TreeNode *t1 = new TreeNode(3);
  t1->left = new TreeNode(9);
  t1->right = new TreeNode(20);
  t1->right->left = new TreeNode(15);
  t1->right->right = new TreeNode(7);
  cout << "t? " << S.isBalanced(t1) << endl;
  t1->right->left->left = new TreeNode(3);
  cout << "f? " << S.isBalanced(t1) << endl;
}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}
