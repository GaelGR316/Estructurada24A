#include <iostream>
#include <string>
#include <algorithm>

bool esPalindromo(const std::string& str) {
    std::string strReversa = str;
    std::reverse(strReversa.begin(), strReversa.end());
    return str == strReversa;
}

void contarCaracteres(const std::string& str, int& vocales, int& consonantes, int& espacios) {
    vocales = consonantes = espacios = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        char c = str[i];
        if (std::isspace(c)) {
            ++espacios;
        } else if (std::isalpha(c)) {
            c = std::tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ++vocales;
            } else {
                ++consonantes;
            }
        }
    }
}

int main() {
    std::string frase;
    std::cout << "Introduce una palabra o frase: ";
    std::getline(std::cin, frase);

    int vocales, consonantes, espacios;
    contarCaracteres(frase, vocales, consonantes, espacios);

    std::cout << "Vocales: " << vocales << "\n";
    std::cout << "Consonantes: " << consonantes << "\n";
    std::cout << "Espacios: " << espacios << "\n";

    std::cout << "La frase " << (esPalindromo(frase) ? "es" : "no es") << " un palindromo.\n";

    std::cout << "Frase en mayusculas: ";
    std::transform(frase.begin(), frase.end(), frase.begin(), ::toupper);
    std::cout << frase << "\n";

    std::cout << "Frase en minusculas: ";
    std::transform(frase.begin(), frase.end(), frase.begin(), ::tolower);
    std::cout << frase << "\n";

    std::string otraFrase;
    std::cout << "Introduce otra palabra o frase: ";
    std::getline(std::cin, otraFrase);

    std::cout << "Concatenacion de las frases: " << frase + " " + otraFrase << "\n";

    return 0;
}
