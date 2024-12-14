#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <unordered_map>
#include <iostream>
#include <stdexcept>
#include <iterator>

// Класс итератора для хэш-таблицы
template <typename Key, typename Value>
class HashTableIterator {
public:
    using Iterator = typename std::unordered_map<Key, Value>::iterator;

    explicit HashTableIterator(Iterator it) : current(it) {}

    // Перегрузка оператора разыменования
    std::pair<Key, Value>& operator*() {
        return *current;
    }

    // Перегрузка оператора ->
    std::pair<Key, Value>* operator->() {
        return &(*current);
    }

    // Перегрузка оператора ++ (префиксный)
    HashTableIterator& operator++() {
        ++current;
        return *this;
    }

    // Перегрузка оператора ++ (постфиксный)
    HashTableIterator operator++(int) {
        HashTableIterator temp = *this;
        ++current;
        return temp;
    }

    // Перегрузка оператора -- (префиксный)
    HashTableIterator& operator--() {
        --current;
        return *this;
    }

    // Перегрузка оператора -- (постфиксный)
    HashTableIterator operator--(int) {
        HashTableIterator temp = *this;
        --current;
        return temp;
    }

    // Перегрузка оператора сравнения (==)
    bool operator==(const HashTableIterator& other) const {
        return current == other.current;
    }

    // Перегрузка оператора сравнения (!=)
    bool operator!=(const HashTableIterator& other) const {
        return current != other.current;
    }

private:
    Iterator current;
};

// Класс контейнера хэш-таблицы
template <typename Key, typename Value>
class HashTable {
public:
    using Iterator = HashTableIterator<Key, Value>;

    // Добавить объект в контейнер
    void insert(const Key& key, const Value& value) {
        hashTable[key] = value;
    }

    // Удалить объект из контейнера
    void remove(const Key& key) {
        auto it = hashTable.find(key);
        if (it != hashTable.end()) {
            hashTable.erase(it);
        } else {
            throw std::runtime_error("Key not found");
        }
    }

    // Вывести содержимое контейнера
    void print() const {
        for (const auto& pair : hashTable) {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
    }

    // Установить итератор на начало контейнера
    Iterator begin() {
        return Iterator(hashTable.begin());
    }

    // Установить итератор на конец контейнера
    Iterator end() {
        return Iterator(hashTable.end());
    }

    // Найти значение по ключу
    Value find(const Key& key) const {
        auto it = hashTable.find(key);
        if (it != hashTable.end()) {
            return it->second;
        }
        throw std::runtime_error("Key not found");
    }

    // Проверить, пуст ли контейнер
    bool empty() const {
        return hashTable.empty();
    }

    // Получить размер контейнера
    size_t size() const {
        return hashTable.size();
    }

private:
    std::unordered_map<Key, Value> hashTable;
};

#endif // HASH_TABLE_H
