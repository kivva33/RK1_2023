#include <iostream>
#include <vector>

//задача 2
char* convertDecToBin(int number);
void writeToFile(const char* fileName, const char* strNum);
void task_2();
//задача 3
char* convertBinToHex(const char* binNum);
void writeToFile(const char* fileName, int writeAppend, const char* hexNum, const char* binNum);
void task_3();
//задача 4
void buildTree(int height);
void task_4();
//задача 5
void randFill(float* ar, int N);
std::vector<std::pair<int, float>> averStr2DArray(const float* ar, int colCount, int rowCount);
void task_5();
//задача 6
struct Node {
    Node* next;
    Node* prev;
    int nameNode;
    static int countNodes;
};
class LinkedList {
private:
    Node* Head;
    Node* Tail;
public:
    LinkedList() {
        Head = nullptr;
        Tail = Head;
    };
    ~LinkedList() {
        Node* p = Head;
        while (p != nullptr) {
            p->prev = nullptr;
            p = p->next;
        }
    };
    void push_back(int nameNode);
    void writeToFileFromTail();
    void writeToFileFromHead();
    void insert(int nameNode, int position);
};
void task_6();
//задача 7
void task_7();