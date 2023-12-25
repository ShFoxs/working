#include <iostream>
#include <memory>

// Абстрактний клас продукту
class Product {
public:
    virtual void display() const = 0;
    virtual ~Product() {}
};

// Конкретний клас продукту 1
class ConcreteProduct1 : public Product {
public:
    void display() const override {
        std::cout << "Concrete Product 1" << std::endl;
    }
};

// Конкретний клас продукту 2
class ConcreteProduct2 : public Product {
public:
    void display() const override {
        std::cout << "Concrete Product 2" << std::endl;
    }
};

// Абстрактний клас фабрики
class Factory {
public:
    virtual std::unique_ptr<Product> createProduct() const = 0;
    virtual ~Factory() {}
};

// Конкретна реалізація фабрики для продукту 1
class ConcreteFactory1 : public Factory {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProduct1>();
    }
};

// Конкретна реалізація фабрики для продукту 2
class ConcreteFactory2 : public Factory {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProduct2>();
    }
};

int main() {
    // Використання фабрики для створення продукту 1
    std::unique_ptr<Factory> factory1 = std::make_unique<ConcreteFactory1>();
    std::unique_ptr<Product> product1 = factory1->createProduct();
    product1->display();

    // Використання фабрики для створення продукту 2
    std::unique_ptr<Factory> factory2 = std::make_unique<ConcreteFactory2>();
    std::unique_ptr<Product> product2 = factory2->createProduct();
    product2->display();

    return 0;
}
