#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node
{
    char data;
    int frequency;
    Node* left;
    Node* right;

    Node(char data, int frequency)
    {
        this->data = data;
        this->frequency = frequency;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct CompareFrequency
{
    bool operator()(Node* left, Node* right)
    {
        return left->frequency > right->frequency;
    }
};

void generateHuffmanCodes(Node* root, string code, unordered_map<char, string>& codes)
{
    if (root)
    {
        if (!root->left && !root->right)
        {
            codes[root->data] = code;
        }
        generateHuffmanCodes(root->left, code + "0", codes);
        generateHuffmanCodes(root->right, code + "1", codes);
    }
}

void encodeWithHuffman(const string& input)
{
    unordered_map<char, int> frequencies;
    for (char ch : input)
    {
        frequencies[ch]++;
    }

    priority_queue<Node*, vector<Node*>, CompareFrequency> minHeap;
    for (auto& pair : frequencies)
    {
        minHeap.push(new Node(pair.first, pair.second));
    }

    while (minHeap.size() > 1)
    {
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        Node* internalNode = new Node('$', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;
        minHeap.push(internalNode);
    }

    Node* root = minHeap.top();

    unordered_map<char, string> codes;
    generateHuffmanCodes(root, "", codes);

    cout << "\n\n******************* Huffman Codes *******************\n\n" << endl;

    for (auto& pair : codes)
    {
        cout << "Character: " << pair.first << endl;
        cout << "Frequency: " << frequencies[pair.first] << endl;
        cout << "Huffman Code: " << pair.second << endl;
        cout << endl;
    }
}

int main()
{
    string input;
    cout << "Enter the input string: ";
    cin >> input;
    encodeWithHuffman(input);

    return 0;
}
