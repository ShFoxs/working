#include <iostream>
#include <memory>

// Абстрактний клас продукту A
class AbstractProductA {
public:
    virtual void display() const = 0;
    virtual ~AbstractProductA() {}
};

// Абстрактний клас продукту B
class AbstractProductB {
public:
    virtual void show() const = 0;
    virtual ~AbstractProductB() {}
};

// Конкретний продукт A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void display() const override {
        std::cout << "Concrete Product A1" << std::endl;
    }
};

// Конкретний продукт A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void display() const override {
        std::cout << "Concrete Product A2" << std::endl;
    }
};

// Конкретний продукт B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void show() const override {
        std::cout << "Concrete Product B1" << std::endl;
    }
};

// Конкретний продукт B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void show() const override {
        std::cout << "Concrete Product B2" << std::endl;
    }
};

// Абстрактний клас абстрактної фабрики
class AbstractFactory {
public:
    virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
    virtual ~AbstractFactory() {}
};

// Конкретна реалізація абстрактної фабрики 1
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA1>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB1>();
    }
};

// Конкретна реалізація абстрактної фабрики 2
class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA2>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB2>();
    }
};

int main() {
    // Використання абстрактної фабрики 1
    std::unique_ptr<AbstractFactory> factory1 = std::make_unique<ConcreteFactory1>();
    std::unique_ptr<AbstractProductA> productA1 = factory1->createProductA();
    std::unique_ptr<AbstractProductB> productB1 = factory1->createProductB();

    productA1->display();
    productB1->show();

    // Використання абстрактної фабрики 2
    std::unique_ptr<AbstractFactory> factory2 = std::make_unique<ConcreteFactory2>();
    std::unique_ptr<AbstractProductA> productA2 = factory2->createProductA();
    std::unique_ptr<AbstractProductB> productB2 = factory2->createProductB();

    productA2->display();
    productB2->show();

    return 0;
}
