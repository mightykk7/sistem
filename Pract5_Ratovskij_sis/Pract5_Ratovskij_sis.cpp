
#include <iostream>
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList
{
private:  
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    void push_front(int value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    void push_back(int value) {
        Node* node = new Node(value);
        if (tail == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    void pop_front() {
        if (head == nullptr) {
            std::cout << "Список пуст";
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    void pop_back() {
        if (head == nullptr) {
            std::cout << "Список пуст";
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }
    void display() {
        if (head == nullptr) {
            std::cout << "Список пуст";
            return;
        }
        Node* node = head;
        std::cout << "Элементы списка: ";
        while (node != nullptr) {
            std::cout << node->data << " ";
            node = node->next;
            
        }
        std::cout << std::endl;
    }
    void sort() {
        if (head == nullptr)
            return;
        for (Node* current = head; current != nullptr && current->next !=nullptr; current = current->next) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
        }
    }
    void remove_duplicates() {
        if (head == nullptr || head == tail) {
            return;
        }
        for (Node* current = head; current != nullptr; current = current->next) {
            for (Node* runner = current->next; runner != nullptr; ) {
                Node* next_runner = runner->next;
                if (runner->data == current->data) {
                    if (runner->prev != nullptr) {
                        runner->prev->next = runner->next;
                    }
                    if (runner->next != nullptr) {
                        runner->next->prev = runner->prev;
                    }
                    if (runner == tail) {
                        tail = runner->prev;
                    }
                    delete runner;
                }
                runner = next_runner;
            }
        }
    }
};

void show_menu() {
    std::cout << "\n=== Меню двусвязного списка ===\n";
    std::cout << "1. Добавить элемент в начало\n";
    std::cout << "2. Добавить элемент в конец\n";
    std::cout << "3. Удалить элемент с начала\n";
    std::cout << "4. Удалить элемент с конца\n";
    std::cout << "5. Отобразить список\n";
    std::cout << "6. Сортировать список\n";
    std::cout << "7. Удалить дубликаты\n";
    std::cout << "8. Выйти\n";
    std::cout << "Выберите пункт меню: ";
}

int main() {
    setlocale(0, "rus");
    DoublyLinkedList list;
    int choice = 0;
    while (choice != 8) {
        show_menu();
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::cout << "Введите значение для добавления в начало: ";
            int value;
            std::cin >> value;
            list.push_front(value);
            std::cout << "Элемент добавлен в начало.\n";
            break;
        }
        case 2: {
            std::cout << "Введите значение для добавления в конец: ";
            int value;
            std::cin >> value;
            list.push_back(value);
            std::cout << "Элемент добавлен в конец.\n";
            break;
        }
        case 3:
            list.pop_front();
            break;
        case 4:
            list.pop_back();
            break;
        case 5:
            list.display();
            break;
        case 6:
            list.sort();
            std::cout << "Список отсортирован.\n";
            break;
        case 7:
            list.remove_duplicates();
            std::cout << "Дубликаты удалены.\n";
            break;
        case 8:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
        if (choice == 8) {
            break;
        }
    }
}



