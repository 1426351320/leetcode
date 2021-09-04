#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<sstream>
#include<exception>
#include<bitset>
#include<queue>
#include<thread>
#include<memory>
#include<functional>
#include<stack>
#include<unordered_map>

using namespace std;
typedef struct Node
{
	Node(int arg):val(arg){}
	
	
	Node* Left = nullptr;
	Node* Right = nullptr;
	int val;
}*pnode;

void PreTree(pnode root)
{
	stack<pnode> store;

	while (!store.empty() || root != nullptr)
	{
		while (root != nullptr)
		{
			cout << root->val;
			store.push(root);
			root = root->Left;
		}
		if (store.top()->Right != nullptr)
			root = store.top()->Right;
		store.pop();		
	} 
}
void MidTree(pnode root)
{
	stack<pnode> store;

	while (!store.empty() || root != nullptr)
	{
		while (root != nullptr)
		{
			store.push(root);
			root = root->Left;
		}
		cout << store.top()->val;
		if (store.top()->Right != nullptr)
			root = store.top()->Right;
		store.pop();
	}
}
void PostTree(pnode root)
{
	stack<pnode> store;
	pnode last = nullptr;

	while (!store.empty() || root != nullptr)
	{
		while (root != nullptr)
		{
			store.push(root);
			root = root->Left;
		}
		if (store.top()->Right != nullptr)
		{
			root = store.top()->Right;
			continue;
		}
		while (!store.empty()&&(last == store.top()->Right || store.top()->Right == nullptr))
		{
			cout << store.top()->val;
			last = store.top();
			store.pop();
		}
		if(!store.empty())
			root = store.top()->Right;
	}
}


int main()
{
	pnode root=new Node(1);
	root->Left = new Node(4);
	root->Right = new Node(2);
	root->Left->Left = new Node(6);
	root->Left->Right = new Node(3);
	root->Right->Left = new Node(5);

	PostTree(root);



	return 0;
}
