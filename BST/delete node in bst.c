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

node *delete(node *root,int key)
{
	if(root==NULL)
        return root;

	if(key<root->data)
		root->left=delete(root->left,key);
	else if(key > root->data)
	root->right=delete(root->right,key);
    else{
        if(root->left!=NULL &&root->right!=NULL)
        {
            node *t=t->right;
            while(t->left!=NULL)
                t=t->left;
            root->data=t->data;
            root->right=delete(root->right,t->data);
            return root;
        }
        node *t=root->left!=NULL ? root->left:root->right;
        free(root);
        return t;
    }


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
    printf("\npreorder of constructed tree is\n");
    preorder(root);
     printf("\ninorder of constructed tree is\n");

	inorder(root);
	printf("\npost order is \n");
	postorder(root);


	printf("Enter element to delete ");
	scanf("%d",&key);
	root=delete(root,key);

	printf("Inorder after deleting is \n");

	inorder(root);
	printf("\n");
}
