#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//单例模式 打印机类案例
class Printer
{
public:
    static Printer* getInstance()
    {
        return singlePrinter;
    }

    //打印功能
    void printText(string text)
    {
        cout << text << endl;
        m_Count++;
    }

    int m_Count;
private:

    Printer() { m_Count = 0; }
    Printer(const Printer &) {}
    static Printer* singlePrinter;
};
Printer* Printer::singlePrinter = new Printer;

int main()
{
    Printer* p1 = Printer::getInstance();
    p1->printText("入职申请");
    p1->printText("离职申请");
    p1->printText("调休申请");
    p1->printText("升职申请");
    cout << "打印次数： " << p1->m_Count << endl;

    Printer* p2 = Printer::getInstance();
    p2->printText("旅游申请");
    cout << "打印次数： " << p1->m_Count << endl;

    system("pause");
    return 0;
}