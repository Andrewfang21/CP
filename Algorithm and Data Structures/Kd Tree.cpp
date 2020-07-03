#include<bits/stdc++.h>
using namespace std;

const int K = 2;

struct Node {
	int point[K];
	Node *left, *right;

	Node* newNode(int A[]) {
		Node *temp = new Node;

		for (int i = 0; i < K; i ++)
			temp -> point[i] = A[i];

		temp -> left = temp -> right = NULL;

		return temp;
	}

	void copyPoint(int p1[], int p2[]) {
		for (int i = 0; i < K; i ++)
			p1[i] = p2[i];
	}

	bool samePoints(int p1[], int p2[]) {
		for (int i = 0; i < K; i ++)
			if (p1[i] != p2[i])
				return false;

		return true;
	}

	Node *minNode(Node *x, Node *y, Node *z, int dim) {
		Node *res = x;
		if (y != NULL && y -> point[dim] < res -> point[dim])
			res = y;
		if (z != NULL && z -> point[dim] < res -> point[dim])
			res = z;

		return res;
	}

	Node* findMinNode(Node *pos, int dim, int depth) {
		if (pos == NULL)
			return NULL;

		int axis = depth % K;
		if (axis == dim){
			if (pos -> left == NULL)
				return pos;

			return findMinNode(pos -> left, dim, depth + 1);
		}

		return minNode(pos,
					   findMinNode(pos -> left, dim, depth + 1),
				   	   findMinNode(pos -> right, dim, depth + 1),
				   	   dim);
	}

	int findMin(Node *pos, int dim, int depth) {
		if (pos == NULL)
			return INT_MAX;

		int axis = depth % K;
		if (axis == dim){
			if (pos -> left == NULL)
				return pos -> point[dim];

			return min(pos -> point[dim], findMin(pos -> left, dim, depth + 1));
		}

		return min(pos -> point[dim],
			   min(findMin(pos -> left, dim, depth + 1),
				   findMin(pos -> right, dim, depth + 1)));

	}

	Node* insertNode(Node *pos, int point[], int depth) {
		if (pos == NULL)
			return newNode(point);

		int axis = depth % K;
		if (point[axis] < pos -> point[axis])
			pos -> left = insertNode(pos -> left, point, depth + 1);
		else
			pos -> right = insertNode(pos -> right, point, depth + 1);

		return pos;
	}

	Node* deleteNode(Node *pos, int point[], int depth) {
		if (pos == NULL)
			return NULL;

		int axis = depth % K;
		if (samePoints(pos -> point, point)) {
			if (pos -> right != NULL) {
				Node *minNode = findMinNode(pos -> right, axis, 0);
				copyPoint(pos -> point, minNode -> point);

				pos -> right = deleteNode(pos -> right, minNode -> point, depth + 1);
			}
			else if (pos -> left != NULL) {
				Node *minNode = findMinNode(pos -> left, axis, 0);
				copyPoint(pos -> point, minNode -> point);

				pos -> right = deleteNode(pos -> left, minNode -> point, depth + 1);				
			}
			else {
				delete pos;
				return NULL;
			}

			return pos;
		}

		if (point[axis] < pos -> point[axis])
			pos -> left = deleteNode(pos -> left, point, depth + 1);
		else
			pos -> right = deleteNode(pos -> right, point, depth + 1);
	
		return pos;
	}

	bool searchNode(Node *pos, int point[], int depth) {
		if (pos == NULL)
			return false;
		if (samePoints(pos -> point, point))
			return true;

		int axis = depth % K;
		if (point[axis] < pos -> point[axis])
			return searchNode(pos -> left, point, depth + 1);

		return searchNode(pos -> right, point, depth + 1);
	}
};

int main() {
	struct Node *root = NULL;
	int points[][K] = {{30, 40}, {5, 25}, {70, 70}, 
                       {10, 12}, {50, 30}, {35, 45}}; 

   int n = sizeof(points) / sizeof(points[0]);

   for (int i = 0; i < n; i ++)
   		root = root -> insertNode(root, points[i], 0);

	int point1[] = {10, 19};
   	(root -> searchNode(root, point1, 0)) ? printf("Found\n") : printf("Not Found\n");

	int point2[] = {12, 19};
   	(root -> searchNode(root, point2, 0)) ? printf("Found\n") : printf("Not Found\n");  


   	for (int i = 0; i < K; i ++) {
   		printf("Minimum of %d'th dimension is %d\n", i, root -> findMin(root, i, 0));
   	}

   	root = root -> deleteNode(root, points[0], 0);
   	printf("Root after deletion of (30, 40) = (%d, %d)\n", root -> point[0], root -> point[1]);
  
return 0;  
}
