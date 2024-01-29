#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Node {
public:
    char ch;
    int freq;
    Node* left, * right;

    Node(char ch, int freq, Node* left, Node* right) {
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }

};

class comp {
public:
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }

};

void encode(Node* root, string str,
    unordered_map<char, string>& huffmanCode)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}



void buildHuffmanTree(string text)
{

    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, comp> pq;

    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1)
    {

        Node* left = pq.top(); pq.pop();
        Node* right = pq.top();	pq.pop();

        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);


    unordered_map<char, int>::iterator itr1 = freq.begin();
    unordered_map<char, string>::iterator itr2 = huffmanCode.begin();

    while (itr1 != freq.end() && itr2 != huffmanCode.end()) {
        cout << "Char: " << itr1->first << " Freq: " << itr1->second << " Code: " << itr2->second << "\n";
        ++itr1;
        ++itr2;
    }



}

int main() {
    string text{};
    cout << "Please enter your message: ";
    cin >> text;
    buildHuffmanTree(text);


    return 0;
}