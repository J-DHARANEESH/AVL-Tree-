#include<iostream>
using namespace std;
struct TreeNode {  
	    int value;  
	    TreeNode *left;  
	    TreeNode *right;  };  
  bool isTreeEmpty(TreeNode* root) {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }
  void inorder(TreeNode *root)  {  
	    if (root == NULL)  
	        return;  
	    inorder(root->left); 
	    cout<< root->value << "   "; 
	    inorder(root->right);}  
void preorder(TreeNode *root){
    if (root == NULL)  
	        return;  
        cout<< root->value<< "   "; 
	    inorder(root->left);
	    inorder(root->right);} 
void postorder(TreeNode *root){
    if (root == NULL)  
	        return;  
	    inorder(root->left);
	    inorder(root->right);
        cout<< root->value<< "   "; 
        } 
  int height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      int lheight = height(r -> left);
      int rheight = height(r -> right);
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  } 
  int getBalanceFactor(TreeNode * n) {
    if (n == NULL)
      return -1;
    return height(n -> left) - height(n -> right);
  }
  TreeNode * rightRotate(TreeNode * y) {
    TreeNode * x = y -> left;
    TreeNode * T2 = x -> right; 
    x -> right = y;
    y -> left = T2;
    return x;
  }
  TreeNode * leftRotate(TreeNode * x) {
    TreeNode * y = x -> right;
    TreeNode * T2 = y -> left; 
    y -> left = x;
    x -> right = T2;
    return y;
  }
  int findMinimum(TreeNode* root) {  
    if(root ==NULL)
        cout << "Tree does not exist!";
	while(root->left != NULL) {  
	        root = root->left;  }  
	return root->value;
  }  
  int findMaximum(TreeNode* root) {  
    if(root ==NULL)
        cout << "Tree does not exist!"; 
	while(root->right != NULL) {  
	        root = root->right;  }  
	return root->value;
  }
  TreeNode *NewNode(int data){
    TreeNode *newNode = new TreeNode();
    newNode->value = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
  TreeNode * insert(TreeNode * r, TreeNode * new_node) {
    if (r == NULL) {
      r = new_node;
      cout << "Value inserted successfully" << endl;
      return r;
    }
    if (new_node -> value < r -> value) {
      r -> left = insert(r -> left, new_node);
    } else if (new_node -> value > r -> value) {
      r -> right = insert(r -> right, new_node);
    } else {
      cout << "No duplicate values allowed!" << endl;
      return r;
    }
    int bf = getBalanceFactor(r);
    if (bf > 1 && new_node -> value < r -> left -> value)
      return rightRotate(r);  
    if (bf < -1 && new_node -> value > r -> right -> value)
      return leftRotate(r);
    if (bf > 1 && new_node -> value > r -> left -> value) {
      r -> left = leftRotate(r -> left);
      return rightRotate(r);
    }
    if (bf < -1 && new_node -> value < r -> right -> value) {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }
    return r;
  }
    TreeNode * minValueNode(TreeNode * node) {
    TreeNode * current = node;
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }
 TreeNode * deleteNode(TreeNode * r, int v) {
    if (r == NULL) {
      return NULL;
    }
    else if (v < r -> value) {
      r -> left = deleteNode(r -> left, v);
    }
    else if (v > r -> value) {
      r -> right = deleteNode(r -> right, v);
    }
    else {
      if (r -> left == NULL) {
        TreeNode * temp = r -> right;
        delete r;
        return temp;
      } else if (r -> right == NULL) {
        TreeNode * temp = r -> left;
        delete r;
        return temp;
      } else {
        TreeNode * temp = minValueNode(r -> right);
        r -> value = temp -> value;
        r -> right = deleteNode(r -> right, temp -> value);
      }
    }

    int bf = getBalanceFactor(r);
    if (bf == 2 && getBalanceFactor(r -> left) >= 0)
      return rightRotate(r);
    else if (bf == 2 && getBalanceFactor(r -> left) == -1) {
      r -> left = leftRotate(r -> left);
      return rightRotate(r);
    }
    else if (bf == -2 && getBalanceFactor(r -> right) <= -0)
      return leftRotate(r);
    else if (bf == -2 && getBalanceFactor(r -> right) == 1) {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }

    return r;
  }
bool Search(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->value == data)
    {
        return true;
    }
    else if (data <= root->value)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}
  int main()
{
    TreeNode *root = NULL; 
    TreeNode * newNode;
    int c, e,ele,val;
    do
    {  
        cout <<"------------------------------\n";
        cout << "1.Insert an element\n";
        cout << "2.Search an element\n";
        cout << "3.Display\n";
        cout << "4.findMin\n";
        cout << "5.findmax\n";
        cout << "6.Delete\n";
        cout << "7.Exit\n";
        cout <<"------------------------------\n";
        cout << "Enter your choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter the element: ";
            cin >> e;
            newNode=NewNode(e);
            root = insert(root, newNode);
            break;
        case 2:
            int number;
            cout << "Enter number be searched\n";
            cin >> number;
    
            if (Search(root, number) == true)
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;
        case 3:
            cout <<"Inorder\n";
            inorder(root);
            cout <<"\n";
            cout <<"Preorder\n";
            preorder(root);
            cout <<"\n";
            cout <<"Postorder\n";
            postorder(root);
            cout <<"\n";
            break;
        case 4:
            cout <<"The minimum element is:\n";
            ele=findMinimum(root);
            cout << ele;
            cout <<"\n";
            break;
        case 5:
            cout <<"The maximum element is:\n";
            ele=findMaximum(root);
            cout << ele;
            cout <<"\n";
            break;
        case 6:
            cout << "Enter value to be deleted: ";
            cin >> val;
            if (Search){
              root = deleteNode(root,val);
              cout << "Value Deleted" << endl;
            } else {
              cout << "Value NOT found" << endl;
            }
            break;
        default:
            cout << "Wrong choice\n";
        };
    }while(c!=7);
   return 0;
}