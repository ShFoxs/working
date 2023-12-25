#include <iostream>
#include <string>

// Абстрактний клас для столів
class Table {
public:
    virtual void create() const = 0;
    virtual ~Table() {}
};

// Абстрактний клас для стільців
class Chair {
public:
    virtual void create() const = 0;
    virtual ~Chair() {}
};

// Абстрактна фабрика
class FurnitureFactory {
public:
    virtual Table* createTable() const = 0;
    virtual Chair* createChair() const = 0;
    virtual ~FurnitureFactory() {}
};

// Конкретна реалізація стола
class WoodenTable : public Table {
public:
    void create() const override {
        std::cout << "Wooden Table created" << std::endl;
    }
};

// Конкретна реалізація стільця
class WoodenChair : public Chair {
public:
    void create() const override {
        std::cout << "Wooden Chair created" << std::endl;
    }
};

// Конкретна фабрика для дерев'яних меблів
class WoodenFurnitureFactory : public FurnitureFactory {
public:
    Table* createTable() const override {
        return new WoodenTable();
    }

    Chair* createChair() const override {
        return new WoodenChair();
    }
};

// Клас, який використовує абстрактну фабрику для створення меблів
class FurnitureClient {
public:
    FurnitureClient(FurnitureFactory* factory) : factory_(factory) {}

    void createFurniture() const {
        Table* table = factory_->createTable();
        Chair* chair = factory_->createChair();

        table->create();
        chair->create();

        delete table;
        delete chair;
    }

private:
    FurnitureFactory* factory_;
};

int main() {
    // Створення дерев'яної фабрики меблів
    FurnitureFactory* woodenFactory = new WoodenFurnitureFactory();

    // Клієнт, який використовує дерев'яну фабрику
    FurnitureClient client(woodenFactory);

    // Створення меблів
    client.createFurniture();

    // Звільнення ресурсів
    delete woodenFactory;

    return 0;
}
