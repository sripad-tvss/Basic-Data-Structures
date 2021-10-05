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
int height(node *root)
{
    int h;
    if(root==NULL)
        return -1;
    int  x=height(root->left);
    int y=height(root->right);
    return x>y?x+1:y+1;

}

int main()
{
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
    printf("%d is height of tree",height(root));
}
