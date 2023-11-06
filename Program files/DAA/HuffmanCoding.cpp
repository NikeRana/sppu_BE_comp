#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Define a structure to represent a node in the Huffman tree
struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// Define a custom comparison function for the priority queue
struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// Function to build the Huffman tree and return the root
HuffmanNode* buildHuffmanTree(map<char, int>& frequencyMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;

    for (auto entry : frequencyMap) {
        minHeap.push(new HuffmanNode(entry.first, entry.second));
    }

    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* newNode = new HuffmanNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }

    return minHeap.top();
}

// Function to generate Huffman codes for each character
void generateHuffmanCodes(HuffmanNode* root, string code, map<char, string>& huffmanCodes) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Function to encode a string using Huffman codes
string huffmanEncode(string text, map<char, string>& huffmanCodes) {
    string encodedText = "";
    for (char c : text) {
        encodedText += huffmanCodes[c];
    }
    return encodedText;
}

int main() {
    // string inputText = "aaaaabbbbbbbbbbccccccccccccddddddddddddddeeeeeeeeeeeeeefffffffffffffffffffff";

    // Count the frequency of each character in the input text
    map<char, int> frequencyMap;
    // for (char c : inputText) {
    //     frequencyMap[c]++;
    // }
    int n;
    cout<<"Enter number of characters : ";
    cin>>n;
    for(int i=0;i<n;i++){
        char ch;
        int freq;
        cout<<"Enter char : ";
        cin>>ch;
        cout<<"Enter frequency of "<<ch<<" : ";
        cin>>freq;
        frequencyMap[ch]=freq;
    }

    // Build the Huffman tree
    HuffmanNode* root = buildHuffmanTree(frequencyMap);

    // Generate Huffman codes for each character
    map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Encode the input text using Huffman codes
    // string encodedText = huffmanEncode(inputText, huffmanCodes);

    // Print the Huffman codes
    cout << "Huffman Codes:" << endl;
    for (auto entry : huffmanCodes) {
        cout << entry.first << ": " << entry.second << endl;
    }

    // cout << "\nOriginal Text: " << inputText << endl;
    // cout << "Encoded Text: " << encodedText << endl;

    return 0;
}
