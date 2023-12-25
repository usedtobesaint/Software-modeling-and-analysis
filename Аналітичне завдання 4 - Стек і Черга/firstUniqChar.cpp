#include <iostream>
#include <unordered_map>

int firstUniqChar(const std::string& s) {
    // Хеш-таблиця для зберігання кількості з'явлень кожного символу
    std::unordered_map<char, int> charCount;

    // Заповнення хеш-таблиці
    for (char ch : s) {
        charCount[ch]++;
    }

    // Пошук першого неповторюваного символу
    for (int i = 0; i < s.length(); ++i) {
        if (charCount[s[i]] == 1) {
            return i;
        }
    }

    // Якщо неповторюваного символу не знайдено
    return -1;
}

int main() {
    // Приклади використання

    std::cout << firstUniqChar("leopard") << std::endl;       // 0
    std::cout << firstUniqChar("loveleopard") << std::endl;   // 2
    std::cout << firstUniqChar("aabb") << std::endl;           // -1

    return 0;
}
