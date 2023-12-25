#include <iostream>

// Старий клас зі своїм власним інтерфейсом
class OldInterface {
public:
    virtual void oldMethod() const {
        std::cout << "Old Method" << std::endl;
    }
    virtual ~OldInterface() {}
};

// Новий інтерфейс, який ми хочемо використовувати
class NewInterface {
public:
    virtual void newMethod() const = 0;
    virtual ~NewInterface() {}
};

// Адаптер, який дозволяє використовувати старий клас у новому коді
class Adapter : public NewInterface {
private:
    OldInterface* oldInstance;

public:
    Adapter(OldInterface* oldInstance) : oldInstance(oldInstance) {}

    // Реалізація нового методу за допомогою старого методу
    void newMethod() const override {
        oldInstance->oldMethod();
    }
};

int main() {
    // Створення екземпляра старого класу
    OldInterface oldInstance;

    // Створення адаптера, який використовує старий клас у контексті нового інтерфейсу
    Adapter adapter(&oldInstance);

    // Виклик методу через новий інтерфейс
    adapter.newMethod();

    return 0;
}
