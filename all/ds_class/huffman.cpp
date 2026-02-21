#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;

namespace Huffman
{
    struct Node
    {
        char ch;
        int freq;
        Node *left, *right;
        Node(char c, int f)
        {
            ch = c;
            freq = f;
            left = right = NULL;
        }
    };
    struct compare
    {
        bool operator()(Node *A, Node *B)
        {
            return (A->freq > B->freq);
        }
    };

    unordered_map<char, string> codes;//编码表
    unordered_map<string, char> reverseCodes;//译码表
    unordered_map<char, int> freqMap; // 字频表

    // 生成哈夫曼编码
    void generateCodes(Node *root, string str, unordered_map<char, string> &codes)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            codes[root->ch] = str;
        }
        generateCodes(root->left, str + "0", codes);
        generateCodes(root->right, str + "1", codes);
    }

    // 删除哈夫曼树
    void deleteTree(Node *root)
    {
        if (!root)
            return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    // 生成哈夫曼树和编码
    void generateHuffman()
    {
        // 清空之前的编码
        codes.clear();
        priority_queue<Node *, vector<Node *>, compare> minHeap;
        //字频入堆
        for (auto &pair : freqMap)
        {
            if (pair.second > 0)
            {
                Node *newNode = new Node(pair.first, pair.second);
                minHeap.push(newNode);
            }
        }
        if (minHeap.size() == 1)//特判只有一个字符的情况
        {
            Node *root = minHeap.top();
            codes[root->ch] = "0";
            deleteTree(root);
            return;
        }

        // 构建哈夫曼树
        while (minHeap.size() > 1)
        {
            Node *left = minHeap.top();
            minHeap.pop();
            Node *right = minHeap.top();
            minHeap.pop();
            Node *NNode = new Node('\0', left->freq + right->freq);
            NNode->left = left;
            NNode->right = right;
            minHeap.push(NNode);
        }
        Node *root = minHeap.top();
        generateCodes(root, "", codes);
        deleteTree(root);

        // 创建反向映射：编码 -> 字符
        for (auto &pair : codes)
        {
            reverseCodes[pair.second] = pair.first;
        }
    }

    // 初始化默认的26个小写字母
    void initDefaultFreq()
    {
        srand(time(0));
        freqMap.clear();
        for (char c = 'a'; c <= 'z'; c++)
        {
            freqMap[c] = rand() % 100 + 1; // 随机生成1-100的频率
        }
        generateHuffman();
    }

    // 显示当前字符和频率
    void displayCharacters()
    {
        cout << "\n当前字符及其频率:\n";
        cout << "==================\n";
        for (auto &pair : freqMap)
        {
            cout << "字符 '" << pair.first << "': 频率 = " << pair.second << endl;
        }
        cout << "==================\n";
    }

    // 显示当前编码表
    void displayCodes()
    {
        cout << "\n当前哈夫曼编码表:\n";
        cout << "==================\n";
        for (auto &pair : codes)
        {
            cout << "字符 '" << pair.first << "': 编码 = " << pair.second << endl;
        }
        cout << "==================\n";
    }

    // 功能1：调节字符和权值
    void adjustCharacters()
    {
        while (true)
        {
            cout << "\n=== 字符和权值调节 ===\n";
            cout << "1. 显示当前字符和权值\n";
            cout << "2. 添加新字符\n";
            cout << "3. 删除字符\n";
            cout << "4. 修改字符权值\n";
            cout << "5. 重置为默认26个小写字母\n";
            cout << "6. 返回主菜单\n";
            cout << "请选择操作: ";

            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
            { // 显示当前字符和权值
                displayCharacters();
                break;
            }
            case 2:
            { // 添加新字符
                char ch;
                int freq;
                cout << "请输入要添加的字符: ";
                cin >> ch;
                cout << "请输入该字符的频率(正整数): ";
                cin >> freq;

                if (freq <= 0)
                {
                    cout << "频率必须为正整数!\n";
                    break;
                }

                freqMap[ch] = freq;
                generateHuffman();
                cout << "已添加字符 '" << ch << "'，频率为 " << freq << endl;
                cout << "已重新生成哈夫曼编码\n";
                break;
            }
            case 3:
            { // 删除字符
                char ch;
                cout << "请输入要删除的字符: ";
                cin >> ch;

                if (freqMap.find(ch) != freqMap.end())
                {
                    freqMap.erase(ch);
                    generateHuffman();
                    cout << "已删除字符 '" << ch << "'\n";
                    cout << "已重新生成哈夫曼编码\n";
                }
                else
                {
                    cout << "字符 '" << ch << "' 不存在!\n";
                }
                break;
            }
            case 4:
            { // 修改字符权值
                char ch;
                int freq;
                cout << "请输入要修改的字符: ";
                cin >> ch;

                if (freqMap.find(ch) != freqMap.end())
                {
                    cout << "请输入新的频率(正整数): ";
                    cin >> freq;

                    if (freq <= 0)
                    {
                        cout << "频率必须为正整数!\n";
                        break;
                    }
                    freqMap[ch] = freq;
                    generateHuffman();
                    cout << "已将字符 '" << ch << "' 的频率修改为 " << freq << endl;
                    cout << "已重新生成哈夫曼编码\n";
                }
                else
                {
                    cout << "字符 '" << ch << "' 不存在!\n";
                }
                break;
            }
            case 5:
            { // 重置为默认26个小写字母
                initDefaultFreq();
                cout << "已重置为26个小写字母(随机频率)\n";
                break;
            }
            case 6:
            {
                return;
            }
            default:
            {
                cout << "无效的选择!\n";
                break;
            }
            }
        }
    }

    // 功能2：哈夫曼编码
    void huffmanEncoding()
    {
        cout << "\n=== 哈夫曼编码 ===\n";
        displayCodes();

        string input;
        cout << "请输入要编码的字符串: ";
        cin.ignore(); // 清除输入缓冲区
        getline(cin, input);

        // 检查字符串中是否有不存在的字符
        bool valid = true;
        for (char ch : input)
        {
            if (codes.find(ch) == codes.end())
            {
                cout << "错误: 字符 '" << ch << "' 不在编码表中!\n";
                cout << "请先通过功能1添加该字符\n";
                valid = false;
                break;
            }
        }

        if (!valid)
        {
            return;
        }

        // 进行编码
        cout << "编码结果: ";
        for (size_t i = 0; i < input.size(); i++)
        {
            cout << codes[input[i]];
            if (i != input.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    // 功能3：哈夫曼解码
    void huffmanDecoding()
    {
        cout << "\n=== 哈夫曼解码 ===\n";
        displayCodes();// 显示当前编码表

        cout << "请输入二进制编码序列(编码之间用空格分隔): ";
        cin.ignore(); // 清除输入缓冲区
        string line;
        getline(cin, line);
        vector<string> inputCodes;
        stringstream ss(line);
        string code;
        while (ss >> code)
        {
            inputCodes.push_back(code);
        }

        // 解码
        string result = "";
        bool valid = true;

        for (size_t i = 0; i < inputCodes.size(); i++)
        {
            if (reverseCodes.find(inputCodes[i]) != reverseCodes.end())
            {
                result += reverseCodes[inputCodes[i]];
            }
            else
            {
                cout << "错误: 编码 \"" << inputCodes[i] << "\" 不存在于编码表中!\n";
                valid = false;
                break;
            }
        }

        if (valid)
        {
            cout << "解码结果: " << result << endl;
        }
    }

    void main_menu_huffman()
    {
        initDefaultFreq();
        while (true)
        {
            cout << "\n========== HUFFMAN 编码系统 ==========\n";
            cout << "1. 调节字符和权值\n";
            cout << "2. 哈夫曼编码\n";
            cout << "3. 哈夫曼解码\n";
            cout << "4. 显示当前编码表\n";
            cout << "5. 退出系统\n";
            cout << "请选择功能: ";

            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
                adjustCharacters();
                break;
            case 2:
                huffmanEncoding();
                break;
            case 3:
                huffmanDecoding();
                break;
            case 4:
                displayCodes();
                break;
            case 5:
                cout << "感谢使用哈夫曼编码系统!\n";
                return;
            default:
                cout << "无效的选择，请重新输入!\n";
            }
        }
    }
}

// 主函数
int main()
{
    system("chcp 65001 > nul");
    cout << "欢迎使用哈夫曼编码/解码系统!\n";
    Huffman::main_menu_huffman();

    return 0;
}