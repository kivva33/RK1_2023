#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>

//задача 1
class WorkWithFile {
private :
    char* dataOfFile;
    void readFromFile(const char* fileName);
    void prepareTestFile(const char* fileName);
public :
    WorkWithFile();
    ~WorkWithFile();
    void writeStatInfoToFile(const char* outFile);
};
void task_1();
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
//задача 8
//описать list (двусвязный список, в котором храняться оценки)
class StudentInfo {
private :
    std::tuple<std::string /*фамилия*/, std::string /*имя*/, char* /*№ студ билета*/> infoStudent;


    std::map<std::string/*название предмета*/, std::pair<std::list<int> /*список оценок*/,
    float /*средняя оценка*/>> subjMark;


public :
    /*	desription	:	добавления отметки по выбранной дисциплине
        input		:	subjName - название дисциплины
                        mark -- оценка,
                        addSubj - если нет такой дисциплины, то добавить, если addSubj == true
        output		:	0 - оценка добавлена, 1 - нет такой дисциплины, 2 - была добавлена новая дисциплина
        author		:
        date		:
    */
    int addMark(const std::string& subjName, int mark, bool addSubj = false);

    /*	desription	:	добавление новой дисциплины
        input		:	subjName - название дисциплины
        output		:	0 - дисциплина добавлена, 1 - такая дисциплина уже есть
        author		:
        date		:

    */
    int addSubj(const std::string& subjName);

    /*	desription	:	получение средней оценки по выбранной дисциплине
        input		:	subjName - название дисциплины
        output		:	среднее значение оценки, если выбранной дисциплины нет, то вернуть -1
        author		:
        date		:
    */
    float getAverMark(const std::string& subjName);

    /*	desription	:	вывести информацию о студенте, его оценках по предметам в следующем формате
                        [Student info]\n\t[subj] : [avers,...] -- [averMark]\n
        input		:	writeFile - true = записать информацию в файл
                        writeFile - false = вывести информацию в консоль
        output		:
        author		:
        date		:
    */
    void printInfoStudent(bool writeFile = false);

    /*	desription	:	запись данных в файл формата файла
                            [Фамилия] [имя] : [номер билета]
                                [дисциплина 1]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
                                [дисциплина 2]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
                                .....
                                [дисциплина N]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
        input		:
        output		:	среднее значение оценки
        author		:
        date		:
    */
    void writeAllInfoToFile();
};