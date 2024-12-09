#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>

/// @brief Classe que implementa uma tabela de hash
/// @tparam T Tipo de dado a ser armazenado na tabela
template <typename T>
class HashTable {
    private:
        /// @brief Tamanho da tabela
        int size;

        /// @brief Tabela de hash
        T *table;

        /// @brief Função de hash que retorna o resto da divisão do valor pelo tamanho da tabela
        /// @param value Valor a ser verificado na tabela
        /// @return Hash do valor
        int hash(T value) {
            return value % size;
        }

    public:
        /// @brief Construtor da classe
        /// @param size Tamanho da tabela
        HashTable(int size) {
            this->size = size;
            table = new T[size];
        }

        /// @brief Destrutor da classe
        ~HashTable() {
            delete[] table;
        }

        /// @brief Insere um valor na tabela
        /// @param value Valor a ser inserido
        void insert(T value) {
            table[hash(value)] = value;
        }

        /// @brief Verifica se um valor está na tabela
        /// @param value Valor a ser verificado
        bool contains(T value) {
            return table[hash(value)] == value;
        }

        /// @brief Remove um valor da tabela
        /// @param value Valor a ser removido
        void remove(T value) {
            table[hash(value)] = NULL;
        }
};



#endif // HASHTABLE_H