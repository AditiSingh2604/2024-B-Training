// IMPLEMENTATION OF BINARY SEARCH

#include <iostream>
#include <vector>

// Binary search function
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Found the target
        } else if (arr[mid] < target) {
            left = mid + 1; // Target may be on the right side
        } else {
            right = mid - 1; // Target may be on the left side
        }
    }

    return -1; // Target not found
}

int main() {
    std::vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int target = 9;

    int result = binarySearch(sortedArray, target);

    if (result != -1) {
        std::cout << "Target " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array." << std::endl;
    }

    return 0;
}

// IMPLEMENTATION OF BINARY HEAP

#include <vector>
#include <iostream>

class MinHeap {
private:
    std::vector<int> heap;

    // Helper functions to calculate parent and child indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    // Helper function to heapify the subtree rooted at index i
    void heapify(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    // Constructor
    MinHeap() {}

    // Function to insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);

        int i = heap.size() - 1;
        while (i != 0 && heap[parent(i)] > heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Function to extract the minimum element (root) from the heap
    int extractMin() {
        if (heap.empty()) {
            std::cerr << "Heap is empty." << std::endl;
            return -1;
        }

        int minElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);

        return minElement;
    }

    // Function to check if the heap is empty
    bool isEmpty() const {
        return heap.empty();
    }
};

int main() {
    MinHeap minHeap;
    minHeap.insert(4);
    minHeap.insert(10);
    minHeap.insert(7);
    minHeap.insert(1);
    minHeap.insert(3);

    while (!minHeap.isEmpty()) {
        std::cout << minHeap.extractMin() << " ";
    }

    return 0;
}

// IMPLEMENTATION OF BINARY TREE

#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    // Helper function for inserting a node recursively
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    // Helper function for performing an inorder traversal recursively
    void inorderRecursive(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inorderRecursive(node->left);
        std::cout << node->data << " ";
        inorderRecursive(node->right);
    }

    // Helper function for performing a preorder traversal recursively
    void preorderRecursive(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }

    // Helper function for performing a postorder traversal recursively
    void postorderRecursive(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        postorderRecursive(node->left);
        postorderRecursive(node->right);
        std::cout << node->data << " ";
    }

    // Helper function to delete a node and its children recursively
    void deleteTree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Destructor
    ~BinaryTree() {
        deleteTree(root);
    }

    // Function to insert a value into the binary tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Function to perform an inorder traversal of the binary tree
    void inorderTraversal() {
        inorderRecursive(root);
        std::cout << std::endl;
    }

    // Function to perform a preorder traversal of the binary tree
    void preorderTraversal() {
        preorderRecursive(root);
        std::cout << std::endl;
    }

    // Function to perform a postorder traversal of the binary tree
    void postorderTraversal() {
        postorderRecursive(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree binaryTree;
    binaryTree.insert(5);
    binaryTree.insert(3);
    binaryTree.insert(7);
    binaryTree.insert(2);
    binaryTree.insert(4);

    std::cout << "Inorder Traversal: ";
    binaryTree.inorderTraversal();

    std::cout << "Preorder Traversal: ";
    binaryTree.preorderTraversal();

    std::cout << "Postorder Traversal: ";
    binaryTree.postorderTraversal();

    return 0;
}