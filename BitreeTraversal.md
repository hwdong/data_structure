```
#include <vector>
#include <stack>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x=-1, TreeNode *l= nullptr, TreeNode *r= nullptr)
		: val(x), left(l), right(r) { }
};
void preorderTraversal(TreeNode *root) {
	if (!root) return;
	stack<TreeNode *> S;
	TreeNode *p = root;
	S.push(p);
	while (!S.empty()) {
		p = S.top();  S.pop(); 	std::cout << p->val << " ";

		if(p->right) S.push(p->right);
		if (p->left) S.push(p->left);
	}
}

void inorderTraversal(TreeNode *root) {
	if (!root) return;
	stack<TreeNode *> S;
	TreeNode *p = root;
	S.push(root);
	while (!S.empty()) {
		p = S.top();
		while (p->left) { p = p->left; S.push(p); }//一路向左走
	
		while (!S.empty()) {
			p = S.top();  S.pop(); 	std::cout << p->val << " ";//p的左子树处理完，处理p

			if (p->right ) {//处理右子树
				p = p->right; S.push(p);
				break;
			}
			
		}
	}
}


void postorderTraversal(TreeNode *root) {
	if (!root) return;
	stack<TreeNode *> S;
	TreeNode *p = root, *pre;
	S.push(root);
	while (!S.empty()) {
		p = S.top();
		while (p->left) { p = p->left; S.push(p); }//一路向左走

		pre = 0;
		while (!S.empty()) {
			p = S.top();
			if (p->right && p->right != pre) {//处理右子树
				p = p->right; S.push(p);
				break;
			}
			else {//右子树为空或处理完
				S.pop(); 	std::cout << p->val << " ";
				pre = p;
			}
		}
	}
}

vector<int> postorderTraversal_(TreeNode *root) {
	list<int> result;
	stack<TreeNode *> S;
	TreeNode *p = root;
	while (!S.empty() || p != nullptr) {
		if (p != nullptr) {//访问p,并走向右子树
			S.push(p);
			result.push_front(p->val);
			p = p->right;
		}
		else {  //右子树走完了
			TreeNode *cur = S.top();
			S.pop();
			p = cur->left;
		}
	}
	for_each(result.begin(), result.end(), [](int t) {std::cout << t << " "; });
	return vector<int>(result.begin(), result.end());
}

```


/*
Morris中序步骤：

1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。

b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。
*/

```
void inorderMorrisTraversal(TreeNode *root) {
	if (!root) return;
	TreeNode *p = root,*pre = nullptr;
	while (p) {
		if (p->left == nullptr) {//无左子树，输出该结点，走到右子树
			std::cout << p->val; 
			p = p->right;
		}
		else {
			pre = p->left;
			while (pre->right&&pre->right != p) {				
				pre = pre->right;
			}
			if (pre->right == nullptr) {
				pre->right = p;   //建立前驱结点的右线索
				p = p->left;      //走向左孩子
			}
			else { //左子树走完，输出该结点
				std::cout << p->val;
				pre->right = nullptr; //断开前驱结点的右线索
				p = p->right;    //走向右孩子
			}			
		}
	}
}
```
/*
Morris先序与中序遍历不同在于：先序在进入左子树前就输出当前节点，
                     而中序在从其前驱节点回到该节点时才输出该节点
Morris先序步骤：
1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。输出当前节点（在这里输出，这是与中序遍历唯一一点不同）。当前节点更新为当前节点的左孩子。

b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。
*/
```
void preorderMorrisTraversal(TreeNode *root) {
	if (!root) return;
	TreeNode *p = root, *pre = nullptr;
	while (p) {		
		if (p->left == nullptr) {//无左子树，输出该结点，走到右子树
			std::cout << p->val;
			p = p->right;
		}
		else {
			pre = p->left;
			while (pre->right&&pre->right != p) {
				pre = pre->right;
			}
			if (pre->right == nullptr) {
				std::cout << p->val;  //进入左子树前，输出该结点
				pre->right = p;   //建立前驱结点的右线索
				p = p->left;      //走向左孩子
			}
			else { //左子树走完
				//std::cout << p->val;
				pre->right = nullptr; //断开前驱结点的右线索
				p = p->right;    //走向右孩子
			}
		}
	}
}
```

/*
Morris后序与中序、先序遍历不同在于：后序在进入左子树或从前驱节点（左子树）返回时都没有输出
         而是在从一个左子树返回当前结点时，将左子树的右下结点倒序输出，从而达到根最后访问的
		 目的。为此，需要对这个树建一个dumpy节点，将整个树作为dumpy节点的左子树。
步骤：

当前节点设置为临时节点dump。

1. 如果当前节点的左孩子为空，则将其右孩子作为当前节点。（注意：这里并不输出当前节点）

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。

b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。倒序输出从当前节点的左孩子到该前驱节点这条路径上的所有节点。当前节点更新为当前节点的右孩子。
*/
```
void reverse(TreeNode *p) {
	std::stack<TreeNode *> S;
	S.push(p);
	while (p->right) { p = p->right; S.push(p); }
	while (!S.empty()) {
		p = S.top(); S.pop();
		std::cout << p->val << " ";
	}
}
void postorderMorrisTraversal(TreeNode *root) {
	if (!root) return;
	TreeNode dumpy(-1,root);

	TreeNode *p = &dumpy, *pre = nullptr;
	while (p) {
		if (p->left == nullptr) {//无左子树，走到右子树
			//std::cout << p->val; 
			p = p->right;
		}
		else {
			pre = p->left;
			while (pre->right&&pre->right != p) {
				pre = pre->right;
			}
			if (pre->right == nullptr) {
				pre->right = p;   //建立前驱结点的右线索
				p = p->left;      //走向左孩子
			}
			else { //左子树走完，
				//std::cout << p->val;				
				pre->right = nullptr; //断开前驱结点的右线索
				reverse(p->left); //逆向输出当前节点左子树的右下路径结点  //reverse(pre->right->left);
				p = p->right;    //走向右孩子
			}
		}
	}
}


int main(int argc, char **argv) {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->left->right = new TreeNode(5);
	root->right = new TreeNode(6);
	root->right->right = new TreeNode(7);
	root->right->right->left = new TreeNode(8);

	preorderMorrisTraversal(root); std::cout <<"\n";	
	inorderMorrisTraversal(root);  std::cout << "\n";
	postorderMorrisTraversal(root);  std::cout << "\n\n";

	preorderTraversal(root);  std::cout << "\n";
	inorderTraversal(root);  std::cout << "\n";
	postorderTraversal(root);  std::cout << "\n";
	postorderTraversal_(root);  std::cout << "\n";
	return 0;
}
```