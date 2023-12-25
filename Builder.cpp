#include <iostream>
#include <string>

// Продукт, який будується
class Product {
public:
    void setPartA(const std::string& partA) {
        partA_ = partA;
    }

    void setPartB(const std::string& partB) {
        partB_ = partB;
    }

    void setPartC(const std::string& partC) {
        partC_ = partC;
    }

    void show() const {
        std::cout << "Part A: " << partA_ << std::endl;
        std::cout << "Part B: " << partB_ << std::endl;
        std::cout << "Part C: " << partC_ << std::endl;
    }

private:
    std::string partA_;
    std::string partB_;
    std::string partC_;
};

// Абстрактний Будівельник
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product getResult() const = 0;
    virtual ~Builder() {}
};

// Конкретний Будівельник
class ConcreteBuilder : public Builder {
public:
    void buildPartA() override {
        product_.setPartA("Part A");
    }

    void buildPartB() override {
        product_.setPartB("Part B");
    }

    void buildPartC() override {
        product_.setPartC("Part C");
    }

    Product getResult() const override {
        return product_;
    }

private:
    Product product_;
};

// Директор, який використовує Будівельника для конструювання продукта
class Director {
public:
    Director(Builder* builder) : builder_(builder) {}

    void construct() {
        builder_->buildPartA();
        builder_->buildPartB();
        builder_->buildPartC();
    }

private:
    Builder* builder_;
};

int main() {
    // Створення конкретного будівельника
    ConcreteBuilder builder;

    // Створення директора і передача будівельника
    Director director(&builder);

    // Директор викликає будівельника для конструювання продукта
    director.construct();

    // Отримання готового продукта від будівельника
    Product product = builder.getResult();

    // Виведення результатів
    product.show();

    return 0;
}
