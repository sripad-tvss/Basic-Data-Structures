#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node *left,*right;
}node;
node *createnode(int key)
{
    node *t=(node *)malloc(sizeof(node));
    t->data=key;
    t->left=NULL;
    t->right=NULL;
    return t;
}
node *bst(int pre[],int in[],int m,int n)
{
	static int a=0;
	int i;
	if(m>n)
	return NULL;

	node *root =createnode(pre[a++]);
		if(n==m)
			return root;
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
	return createnode(key);
	if(key<root->data)
		root->left=insert(root->left,key);
	else if(key > root->data)
	root->right=insert(root->right,key);


return root;
}
int main(){
    int i,n,data,key;
    printf("Enter no.of nodes\n");
    scanf("%d",&n);
    int pre[n],in[n];
    printf("Enter preorder\n");
    for(i=0;i<n;i++)
        scanf("%d",&pre[i]);
    printf("Enter preorder\n");
     for(i=0;i<n;i++)
        scanf("%d",&in[i]);

    node *root=bst(pre,in,0,n-1);
    preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("Enter element to search \n");
	scanf("%d",&data);
	node *s=search(root,data);
	if(s!=NULL)
	printf("Element is found\n");
	else printf("Element is not present in given tree\n");
	printf("Enter element to insert ");
	scanf("%d",&key);
	node *s1=search(root,key);
	if(s1!=NULL)
	printf("Element is already present\n");
	else insert(root,key);
	inorder(root);
	printf("\n");
}
