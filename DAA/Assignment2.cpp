/*

Huffman Encoding

- It is a lossless compression algorithm that assigns shorter codes to frequent characters and longer codes to less frequent characters.

- Uses Greedy Strategy:
always pick the two smallest frequency nodes and merge them.

- Implemented using Min-Heap (priority_queue).

*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Comparator for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; 
    }
};

// Print Huffman Codes
void printCodes(Node* root, string code) {
    if (root==NULL) return;

    // Leaf node → print character & code
    if (!root->left && !root->right && root->ch != '#') {
        cout << root->ch << " : " << code << "\n";
    }

    printCodes(root->left,  code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++) cin >> chars[i];

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++) cin >> freq[i];

    // Min-Heap (priority queue)
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create leaf nodes
    for (int i = 0; i < n; i++) {
        pq.push(new Node(chars[i], freq[i]));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('#', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    Node* root = pq.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}


/*

Sample Input
--------------
Enter number of characters: 5
Characters: a b c d e
Frequencies: 5 9 12 13 16

Sample Output
-------------
Huffman Codes:
e : 0
d : 10
c : 110
b : 1110
a : 1111

-----------------------------------------------------------------------------------------

Time Complexity

Building heap: O(n)

Extract-min + insert operations done (n−1) times: each is O(log n)
Total = O(n log n)

---------------------------------------------------------
Space Complexity

Huffman tree stores all nodes → O(n)

Recursion stack → O(n)
Total = O(n)


Frequent characters get shorter codes : To minimize the total weighted path length, reducing encoded size.


Applications of Huffman Coding : 
1. File compression (ZIP, GZIP)
2. Multimedia compression
3. Network data compression

*/