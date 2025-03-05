#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//抽象CPU类
class Cpu
{
public:
    //计算
    virtual void calculate() = 0;
};

//抽象显卡
class VideoCard
{
public:
    //显示
    virtual void display() = 0;
};

//抽象内存条
class Memory
{
public:
    //存储
    virtual void storage() = 0;
};

//电脑类
class Computer
{
public:

    Computer(Cpu* cpu, VideoCard* vc, Memory* mem)
    {
        this->m_Cpu = cpu;
        this->m_Vc = vc;
        this->m_Mem = mem;
    }

    //电脑运作
    void doWork()
    {
        this->m_Cpu->calculate();
        this->m_Vc->display();
        this->m_Mem->storage();
    }

    ~Computer()
    {
        if (this->m_Cpu != NULL)
        {
            delete this->m_Cpu;
            this->m_Cpu = NULL;
        }
        if (this->m_Vc != NULL)
        {
            delete this->m_Vc;
            this->m_Vc = NULL;
        }
        if (this->m_Mem != NULL)
        {
            delete this->m_Mem;
            this->m_Mem = NULL;
        }
    }

    Cpu* m_Cpu;
    VideoCard* m_Vc;
    Memory* m_Mem;
};

//intel厂商
class intelCpu :public Cpu
{
public:
    void calculate()
    {
        cout << "Intel的CPU开始计算了" << endl;
    }
};
class intelVideoCard :public VideoCard
{
public:
    void display()
    {
        cout << "Intel的显卡开始显示了" << endl;
    }

};
class intelMemory : public Memory
{
public:
    void storage()
    {
        cout << "Intel的内存条开始存储了" << endl;
    }
};

//Lenove厂商
class lenoveCpu :public Cpu
{
public:
    void calculate()
    {
        cout << "Lenove的CPU开始计算了" << endl;
    }
};
class lenoveVideoCard :public VideoCard
{
public:
    void display()
    {
        cout << "Lenove的显卡开始显示了" << endl;
    }

};
class lenoveMemory : public Memory
{
public:
    void storage()
    {
        cout << "Lenove的内存条开始存储了" << endl;
    }
};

int main()
{
    //组装三台电脑
    Cpu* intCpu = new intelCpu;
    VideoCard* intVc = new intelVideoCard;
    Memory* intMem = new intelMemory;

    Computer* c1 = new Computer(intCpu, intVc, intMem);
    cout << "第一台电脑组装结果为：" << endl;
    c1->doWork();
    delete c1;

    cout << "----------------------" << endl;

    Cpu* lenCpu = new lenoveCpu;
    VideoCard* lenVc = new lenoveVideoCard;
    Memory* lenMem = new lenoveMemory;
    Computer* c2 = new Computer(lenCpu, lenVc, lenMem);
    cout << "第二台电脑组装结果为：" << endl;
    c2->doWork();
    delete c2;

    cout << "----------------------" << endl;

    Cpu* lenCpu2 = new lenoveCpu;
    VideoCard* intVc2 = new intelVideoCard;
    Memory* lenMem2 = new lenoveMemory;
    Computer* c3 = new Computer(lenCpu2, intVc2, lenMem2);
    cout << "第三台电脑组装结果为：" << endl;
    c3->doWork();
    delete c3;

    system("pause");
    return 0;
}