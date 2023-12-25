#include <iostream>

// Интерфейс для реализации
class Implementor {
public:
    virtual void operationImpl() = 0;
};

// Конкретная реализация
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() override {
        std::cout << "Concrete Implementor A operation" << std::endl;
    }
};

class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() override {
        std::cout << "Concrete Implementor B operation" << std::endl;
    }
};

// Интерфейс для абстракции
class Abstraction {
public:
    virtual void operation() = 0;
};

// Расширенная абстракция
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* implementor) : implementor_(implementor) {}

    void operation() override {
        std::cout << "Refined Abstraction operation ";
        implementor_->operationImpl();
    }

private:
    Implementor* implementor_;
};

int main() {
    Implementor* implementorA = new ConcreteImplementorA();
    Implementor* implementorB = new ConcreteImplementorB();

    Abstraction* abstractionA = new RefinedAbstraction(implementorA);
    Abstraction* abstractionB = new RefinedAbstraction(implementorB);

    abstractionA->operation();
    abstractionB->operation();

    delete implementorA;
    delete implementorB;
    delete abstractionA;
    delete abstractionB;

    return 0;
}