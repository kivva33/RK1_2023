#include "tasks_rk1.h"
#include <cstring>
#include <vector>
#include <iostream>
const int N = 255;
//задача 1
WorkWithFile::WorkWithFile(){
    dataOfFile = new char[N];
}
WorkWithFile::~WorkWithFile() {
    delete[] dataOfFile;
}
void WorkWithFile::writeStatInfoToFile(const char* outFile){
    readFromFile("sourceFile_task1");
    prepareTestFile("result_sourceFile_task1");
}
void WorkWithFile::readFromFile(const char* fileName){
    FILE* fin = fopen(fileName, "r");
    fscanf(fin, "%s", dataOfFile);
    fclose(fin);
}
void WorkWithFile::prepareTestFile(const char* fileName){
    int lenFile = strlen(dataOfFile);
    int* size = new int[lenFile];
    char* simvol = new char[lenFile];
    int count = 0;
    simvol[count] = '\0';
    for (int i = 0; i < lenFile; i++) {
        if (strchr(simvol, dataOfFile[i])) {
            simvol[strchr(simvol, dataOfFile[i]) - simvol]++;
            continue;
        }
        simvol[count] = dataOfFile[i];
        size[count] = 1;
        simvol[++count] = '\0';
    }
    FILE* fout = fopen(fileName, "r");
    for (int i = 0; i < count; i++) {
        fprintf(fout, "%c\t%d", simvol[i], size[i]);
    }
    fclose(fout);
}

//задача 2
char* convertDecToBin(int number) {
    int* numberDemoBin = new int[64];
    int count = 0;
    numberDemoBin[count] = '\0';
    for (; number != 0; count++) {
        numberDemoBin[count] = (number & 1);
        number = number >> 1;
        numberDemoBin[count + 1] = '\0';
    }
    char* numberToBin = new char[64];
    numberToBin[0] = '\0';
    for (int i = 0; i < count; i++) {
        numberToBin[i + 1] = '\0';
        if (numberDemoBin[count - 1 - i]) {
            numberToBin[i] = '1';
            continue;
        }
        numberToBin[i] = '0';
    }
    delete[] numberDemoBin;
    return numberToBin;
}
void writeToFile(const char* fileName, const char* strNum) {
    FILE* fout = fopen(fileName, "w");
    fprintf(fout, "%s\n",  strNum);
    fclose(fout);

}
void task_2(){
    writeToFile("result_task2", convertDecToBin(9));
}
//задача 3
char* convertBinToHex(const char* binNum){
    char* rightcopybinNum = new char[(4 - strlen(binNum) % 4) + strlen(binNum) + 1];
    if (strlen(binNum) % 4) {
        for (int i = 0; i < 4 - strlen(binNum) % 4; i++) {
            rightcopybinNum[i] = '0';
        }
        rightcopybinNum[4 - strlen(binNum) % 4] = '\0';
        strcat(rightcopybinNum, binNum);
    }
    else {
        strcpy(rightcopybinNum, binNum);
    }
    char bin[][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                     "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };
    char hex[] = "0123456789ABCDEF";
    char* ToHex = new char[strlen(rightcopybinNum) / 4 + 1];
    for (int i = 0; i < strlen(rightcopybinNum) / 4; i++) {
        char* compare = new char[5];
        for (int j = 0; j < 4; j++)
            compare[j] = rightcopybinNum[4 * i + j];
        compare[4] = '\0';
        for (int j = 0; ; j++) {
            if (!strcmp(compare, bin[j])) {
                ToHex[i] = hex[j];
                ToHex[i + 1] = '\0';
                break;
            }
        }
        delete[] compare;
    }
    delete[] rightcopybinNum;
    return ToHex;
}
void writeToFile(const char* fileName, int writeAppend, const char* hexNum, const char* binNum){
    if(writeAppend){
        FILE* fout = fopen(fileName, "w");
        fprintf(fout, "%s\t%s\n", binNum, hexNum);
        fclose(fout);
        return;

    }
    FILE* fout = fopen(fileName, "a");
    fprintf(fout, "%s\t%s\n", binNum, hexNum);
    fclose(fout);
}
void task_3(){
    char bin1[] = "1001000110101111";//1 перезапись
    writeToFile("result_task3", 1, convertBinToHex(bin1), bin1);
    char bin2[] = "100100011";// 0 дозапись
    writeToFile("result_task3", 0, convertBinToHex(bin2), bin2);
    char bin3[] = "1111111111111111";// 0 дозапись
    writeToFile("result_task3", 0, convertBinToHex(bin3), bin3);
}
//задача 4
void buildTree(int height){
    int len = height * 2 - 1;
    char* star = new char[len];
    for(int i = 0; i < len; i++){
        star[i] = ' ';
    }
    star[len] = '\0';
    for(int i = 0; i < height; i++){
        star[len / 2 - i] = '*';
        star[len / 2 + i] = '*';
        printf("%s\n", star);
    }
}
void task_4(){
    buildTree(5);
}
//задача 5
void randFill(float* ar, int N) {
    for (int i = 0; i < N; i++) {
        int x = rand() % 100;
        ar[i] = (float)x;
    }
}
std::vector<std::pair<int, float>> averStr2DArray(const float* ar, int colCount, int rowCount) {
    std::vector<std::pair<int, float>> massiv;
    for (int j = 0; j < rowCount; j++) {
        float sum = 0;
        for (int i = 0; i < colCount; i++) {
            sum += ar[colCount * j + i];
        }
        massiv.emplace_back(j, sum / (colCount));
    }
    return massiv;
}
void task_5(){
    float ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto gg = averStr2DArray(ar, 2, 5);
    FILE* fout = fopen("result_task5", "w");
    for (auto p : gg) {
        fprintf(fout, "%d\t:\t%f\n", p.first, p.second);
    }
    fclose(fout);
}
//задача 6
int Node::countNodes = 0;
void LinkedList::push_back(int nameNode) {
    if (Head == nullptr) {
        Head = new Node();
        Tail = new Node();
        Head->prev == nullptr;
        Head->next = Tail;
        Tail->prev = Head;
        Tail->next = nullptr;
        Head->nameNode = ++nameNode;
        Node::countNodes++;
        return;//заканчиваем выполнение функции
    }
    Tail->next = new Node();
    Node* t = Tail->next;
    Tail->nameNode = ++nameNode;
    t->prev = Tail;
    t->next = nullptr;
    Tail = t;
    Node::countNodes++;
}
void LinkedList::writeToFileFromTail() {
    FILE* fout = fopen("result_task6_Tail", "w");
    Node* p = Tail->prev;
    while (p != nullptr) {
        fprintf(fout, "%d; ", p->nameNode);
        p = p->prev;
    }
    fclose(fout);
}
void LinkedList::writeToFileFromHead() {
    FILE* fout = fopen("result_task6_Head", "w");
    Node* p = Head;
    while (p->next != nullptr) {
        fprintf(fout, "%d; ", p->nameNode);
        p = p->next;
    }
    fprintf(fout, "\n");
    fclose(fout);
}
void task_6(){
    LinkedList p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);
    p.writeToFileFromHead();
    p.writeToFileFromTail();
}
//задача 7
void LinkedList::insert(int nameNode, int position) {
    Node* p;
    p = new Node();
    if (position < 0 || position >= p->countNodes)
        return;
    Node* under = Head;
    Node* after = Head;
    if (!position) {
        p->prev = Head->prev;
        Head->prev = p;
        p->next = Head;
        p->nameNode = ++nameNode;
        Node::countNodes++;
        return;
    }
    for (int i = 0; i < position - 1; i++)
        under = under->next;
    after = under->next;
    p->next = under->next;
    under->next = p;
    p->prev = after->prev;
    after->prev = p;
    p->nameNode = ++nameNode;
    Node::countNodes++;
}
void task_7(){
    LinkedList p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);
    p.insert(3, 1);
    p.writeToFileFromHead();
    p.writeToFileFromTail();
}
