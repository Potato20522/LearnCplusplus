#include<iostream>

using namespace std;

//抽象不同零件类
//抽象CPU类
class CPU {
public:
    //抽象的计算函数
    virtual void calculate() = 0;

    virtual ~CPU() { cout << "CPU析构" << endl; }
};

//抽象显卡类
class VideoCard {
public:
    //抽象的显示函数
    virtual void display() = 0;

    virtual ~VideoCard() {cout << "显示析构" << endl;}
};

//抽象内存条类
class Memory {
public:
    //抽象的存储函数
    virtual void storage() = 0;

    virtual ~Memory() {cout << "内存条析构" << endl;}
};

//电脑类
class Computer {
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem) : cpu(cpu), vc(vc), mem(mem) {}
    /*Computer(CPU *cpu, VideoCard *vc, Memory *mem) {
        this->cpu=cpu;
        this->vc=vc;
        this->mem=mem;
    }*/

    //提供工作的函数
    void work() {
        cpu->calculate();
        vc->display();
        mem->storage();
    }

    //提供析构函数，释放3个电脑零件
     ~Computer() {
        //释放CPU零件
        if (cpu != nullptr) {
            delete cpu;
            cpu = nullptr;
        }

        //释放显卡零件
        if (vc != nullptr) {
            delete vc;
            vc = nullptr;
        }

        //释放内存条零件
        if (mem != nullptr) {
            delete mem;
            mem = nullptr;
        }
        cout << "Computer析构" << endl;
    }

private:
    CPU *cpu;//CPU零件的指针
    VideoCard *vc;
    Memory *mem;
};

//具体的厂商
class IntelCPU : public CPU {
public:
    void calculate() override {
        cout << "Intel的CPU开始计算了" << endl;
    }
};

class IntelVideoCard : public VideoCard {
public:
    void display() override {
        cout << "Intel的显卡开始计算了" << endl;
    }
};

class IntelMemory : public Memory {
public:
    void storage() override {
        cout << "Intel的内存条开始存储了" << endl;
    }
};

//Lenovo厂商
class LenovoCPU : public CPU {
public:
    void calculate() override {
        cout << "Lenovo的CPU开始计算了！" << endl;
    }
};

class LenovoVideoCard : public VideoCard {
public:
    void display() override {
        cout << "Lenovo的显卡开始显示了！" << endl;
    }
};

class LenovoMemory : public Memory {
public:
    void storage() override {
        cout << "Lenovo的内存条开始存储了！" << endl;
    }
};

void test01() {
    //第一台电脑零件
    CPU *intelCpu = new IntelCPU;
    VideoCard *intelCard = new IntelVideoCard;
    Memory *intelMem = new IntelMemory;

    cout << "第一台电脑开始工作：" << endl;
    //创建第一台电脑
    Computer *computer1 = new Computer(intelCpu, intelCard, intelMem);
    computer1->work();
    delete computer1;

    cout << "-----------------------" << endl;
    cout << "第二台电脑开始工作：" << endl;
    //第二台电脑组装
    Computer *computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);;
    computer2->work();
    delete computer2;

    cout << "-----------------------" << endl;
    cout << "第三台电脑开始工作：" << endl;
    //第三台电脑组装
    Computer *computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);;
    computer3->work();
    delete computer3;

}

int main() {
    test01();
    return 0;
}
