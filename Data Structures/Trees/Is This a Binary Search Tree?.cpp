/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
/*
 * Difficulty Medium
 * Max Score 30
 * https://www.hackerrank.com/challenges/ctci-is-binary-search-tree/
 * https://www.hackerrank.com/challenges/is-binary-search-tree/
 */
bool checkBSTHelper(Node *root, int min, int max) {
    if (!root) return true;

    if (!(min < root->data && root->data < max))
        return false;

    return checkBSTHelper(root->left, min, root->data) &&
           checkBSTHelper(root->right, root->data, max);

}

bool checkBST(Node *root) {

    return checkBSTHelper(root, INT32_MIN, INT32_MAX);
}

