#include <iostream>
#include <string>

// Абстрактний клас Прототипу
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void display() const = 0;
    virtual ~Prototype() {}
};

// Конкретний клас Прототипу
class ConcretePrototype : public Prototype {
private:
    std::string data_;

public:
    ConcretePrototype(const std::string& data) : data_(data) {}

    // Метод для створення копії об'єкта
    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    // Метод для виводу даних об'єкта
    void display() const override {
        std::cout << "Data: " << data_ << std::endl;
    }
};

int main() {
    // Створення оригінального об'єкта
    ConcretePrototype original("Original Data");
    original.display();

    // Клонування об'єкта
    Prototype* clone = original.clone();
    clone->display();

    // Звільнення пам'яті, оскільки ми більше не використовуємо клон
    delete clone;

    return 0;
}
