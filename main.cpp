#include <iostream>
#include <string>

using namespace std;

// 추상 컴퓨터 클래스
class Computer {
public:
    virtual string getDescription() const = 0;
    virtual int getPrice() const = 0;
    virtual ~Computer() {}
};

// 기본 컴퓨터 클래스
class BaseComputer : public Computer {
public:
    string getDescription() const override {
        return "Computer";
    }

    int getPrice() const override {
        return 500000;
    }
};

// 데코레이터 추상 클래스
class ComputerDecorator : public Computer {
protected:
    const Computer* computer; // 구성된 객체
public:
    explicit ComputerDecorator(const Computer* c) : computer(c) {}
    virtual ~ComputerDecorator() {
        delete computer;
    }
};

// RAM 데코레이터
class RAM : public ComputerDecorator {
public:
    explicit RAM(const Computer* c) : ComputerDecorator(c) {}

    string getDescription() const override {
        return "RAM" + computer->getDescription();
    }

    int getPrice() const override {
        return computer->getPrice() + 50000;
    }
};

// SSD 데코레이터
class SSD : public ComputerDecorator {
public:
    explicit SSD(const Computer* c) : ComputerDecorator(c) {}

    string getDescription() const override {
        return "SSD" + computer->getDescription();
    }

    int getPrice() const override {
        return computer->getPrice() + 80000;
    }
};

// GPU 데코레이터
class GPU : public ComputerDecorator {
public:
    explicit GPU(const Computer* c) : ComputerDecorator(c) {}

    string getDescription() const override {
        return "GPU" + computer->getDescription();
    }

    int getPrice() const override {
        return computer->getPrice() + 200000;
    }
};

// 메인 함수
int main() {
    const Computer* myComputer = new BaseComputer();

    // 사용자 입력
    char choice;
    cout << "Add RAM? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        myComputer = new RAM(myComputer);
    }

    cout << "Add SSD? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        myComputer = new SSD(myComputer);
    }

    cout << "Add GPU? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        myComputer = new GPU(myComputer);
    }

    // 결과 출력
    cout << "Selected configuration: " << myComputer->getDescription() << endl;
    cout << "Total price: " << myComputer->getPrice() << "원" << endl;

    // 메모리 해제
    delete myComputer;

    return 0;
}
