#include <iostream>

class Singleton {
public:
    // Метод для отримання єдиного екземпляру
    static Singleton& getInstance() {
        // Якщо екземпляр ще не створений, створити його
        if (instance_ == nullptr) {
            instance_ = new Singleton();
        }
        return *instance_;
    }

    // Інші методи класу
    void showMessage() const {
        std::cout << "Hello from Singleton!" << std::endl;
    }

    // Важно: Забороняємо копіювання та присвоєння
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Деструктор
    ~Singleton() {
        // Звільняємо ресурси, якщо необхідно
        delete instance_;
    }

private:
    // Приватний конструктор для заборони створення ззовні
    Singleton() {}

    // Єдиний екземпляр класу
    static Singleton* instance_;
};

// Ініціалізація статичної змінної
Singleton* Singleton::instance_ = nullptr;

int main() {
    // Отримання єдиного екземпляру
    Singleton& singleton = Singleton::getInstance();

    // Використання екземпляру
    singleton.showMessage();

    return 0;
}
