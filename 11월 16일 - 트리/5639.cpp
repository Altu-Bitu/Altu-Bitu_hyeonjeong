#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* makeTree(Node* tree, int key) { //트리 만들어줌
	if (tree == NULL) {//첫 입력인경우
		tree = new Node();
		tree->data = key;
		tree->left = NULL; tree->right = NULL;
	}
	else if (key <= tree->data)  //left로
		tree->left = makeTree(tree->left, key);
	
	else //right로
		tree->right = makeTree(tree->right, key);

	return tree;
}

void postorder(Node* tree) { //후위순회
	if (tree == NULL)
		return;
		postorder(tree->left);
		postorder(tree->right);
		cout << tree->data << '\n';
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int key;
	Node* tree = NULL;
	//입력받고 전위순회로 만들기 , n이 들어올때까지만 받기
	//ctrl+z키로 EOF 값인 -1 입력된다 -> 입력의 끝
	while (cin>>key) { 
		tree= makeTree(tree, key); 
	}

	//후위순회
	postorder(tree);

	return 0;
}