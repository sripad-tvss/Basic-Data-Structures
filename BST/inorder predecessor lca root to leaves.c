#include<stdio.h>
#include<stdlib.h>
int c=0,*a;
typedef struct node{
 int data;
 struct node*left;
 struct node *right;
}node;
node *create(int data)
{
	node *n=(node *)malloc(sizeof(node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
node *bst(int pre[],int in[],int m,int n)
{
	static int a=0;
	int i;
	if(m>n)
	{
	return NULL;
	}
	node *root =create(pre[a++]);
		if(n==m)
		{
			return root;
		}
	for(i=m;i<n;i++)
		if(in[i]==(root->data))
		break;

	root->left=bst(pre,in,m,i-1);
	root->right=bst(pre,in,i+1,n);
return root;
}
void preorder(node *root)
{
	if(root!=NULL)
	{	printf("%4d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *root)
{
	if(root!=NULL)
	{	inorder(root->left);
		if(root->left==NULL && root->right == NULL)
		a[c++]=root->data;
		printf("%4d",root->data);
		inorder(root->right);
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{	postorder(root->left);
		postorder(root->right);
		printf("%4d",root->data);
	}
}
node *search(node *root,int key)
{
	if(root==NULL || root->data==key)
	return root;
	if(root->data > key)
	return search(root->left,key);
	else return search(root->right,key);
}
node *insert(node *root,int key)
{
	node *n=search(root,key);
	if(root==NULL)
	return create(key);
	if(key<root->data)
		root->left=insert(root->left,key);
	else if(key > root->data)
	root->right=insert(root->right,key);


return root;
}
node *deletenode(node *root,int key)
{
	if(root==NULL)
	return root;
	else if(key<root->data)
	root->left=deletenode(root->left,key);
	else if(key> root->data)
	root->right = deletenode(root->right,key);
	else
	{
		if(root->left!=NULL && root->right!=NULL)
		{
			node *t=root->right;
			while(t->left!=NULL)
			t=t->left;
			root->data = t->data;
			root->right = deletenode(root->right,t->data);
			return root;
		}
		node *t=root->left!=NULL ? root->left: root->right;
		free(root);
		return t;


	}
}
node *inpre(node *root,int key)
{
	node *r=search(root,key);
	if(r->left!=NULL)
	{
		node *t=r->left;
		while(t->right!=NULL)
		t=t->right;
	return t;
	}
	if(root->data < key)
	{
		while(root->right !=NULL && root->right->data < key)
			root= root->right;
		return root;
	}
	else if(root->data>key)
	{node *t;
		while( root->left!=NULL && root->left->data >= key)
		root= root->left;
    return root->left;
	}
	else return root->left;
}
node *lca(node *root,int k1,int k2)
{
	if(root->data == k1 || root->data == k2)
	return NULL;
	if(root->data>k1 && root->data<k2)
	return root;
	else if(root->data > k1 && root->data>k2)
	{
		if(root->left->data==k1 || root->left->data == k2)
			return root;
		return lca(root->left,k1,k2);
	}
	else if(root->data < k1 && root->data < k2)
	{
		if(root->right->data==k1 || root->right->data == k2)
			return root;
		return lca(root->right,k1,k2);
	}

}
void paths(node *root, int ele)
{
	if(root->data==ele)
	{
	printf("%d ",root->data);
	return ;}
	if(root->data<ele)
	{
	printf("%d ",root->data);
	paths(root->right,ele);
	}
	else
	{
	printf("%d ",root->data);
	paths(root->left,ele);
	}

}
void rboundary(node *root)
{	if(root->right!=NULL)
	rboundary(root->right);
	printf("%4d",root->data);
}
void boundary(node *root)
{	int i;
	node *t=root;
	printf("%4d",t->data);
if(t->left!=NULL)
{
	while(t->left!=NULL)
	{t=t->left;
	printf("%4d",t->data);
	}
	for(i=1;i<c;i++)
	printf("%4d",a[i]);
	rboundary(root);
}
}
int main()
{	int b[2];
	a=b;
	int i,n,key,data;
	printf(" Enter size ");
	scanf("%d",&n);
	int pre[n],in[n];
	printf(" Enter preorder ");
	for(i=0;i<n;i++)
	scanf("%d",&pre[i]);
	printf(" Enter inorder ");
	for(i=0;i<n;i++)
	scanf("%d",&in[i]);
	node *root = bst(pre,in,0,n-1);
	//printf("\nPreorder of constructed tree is \n");
	//preorder(root);
	printf("\nInorder of constructed tree is \n");
	inorder(root);
	//printf("\nPostorder of constructed tree is \n");
	//postorder(root);
	//printf("\nEnter element to delete:\n");
	//scanf("%d",&data);
	//root=deletenode(root,data);
	//printf("\n Inorder after deletion is :\n");
	//inorder(root);
	//while(n--){
	//printf("\nEnter the value for which you want inorder prede:\n");
 	/*scanf("%d",&data);
	node *t=inpre(root,data);
	if(t == NULL || (key == t->data))
	printf("-1 is inpre\n");
	else printf("%d is inpre ",t->data);}
	int k1,k2;
	printf("\nEnter elements for lca\n");
	scanf("%d",&k1);
	scanf("%d",&k2);
	if(k1>k2)
	{data=k1;
	k1=k2;
	k2=data;}
	node *lc=lca(root,k1,k2);
	if(lc!=NULL)
	printf("%d is lca \n",lc->data);
	else printf("-1 is lca \n");*/
        printf("\n");
	for(i=0;i<c;i++)
	{	//printf("%d ",a[i]);
		paths(root,a[i]);printf("\n");
	}
boundary(root);
return ;
}
