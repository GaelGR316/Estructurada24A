//Gael Gómez Rivers
//Centro Universitario de los Altos
//423034247
//23/04/24

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

int main() {
    std::srand(std::time(0));
    std::vector<std::string> palabras = {"oracion", "palabra", "esquizofrenia", "pantalla", "maria", "escritorio", "cocinero", "leñador", "proyecto", "computadora", "asesino", "persona", "tatuaje", "billetera", "caida", "cargador", "amigo", "pestañas", "cuerpo"};
    std::string palabra_secreta = palabras[std::rand() % palabras.size()];
    std::string palabra_adivinada(palabra_secreta.size(), '_');
    int intentos = palabra_secreta.size() * 2;

    while (intentos > 0 && palabra_adivinada != palabra_secreta) {
        std::cout << "Palabra: " << palabra_adivinada << "\n";
        std::cout << "Intentos restantes: " << intentos << "\n";
        std::cout << "Ingresa una letra: ";
        char letra;
        std::cin >> letra;

        if (std::find(palabra_secreta.begin(), palabra_secreta.end(), letra) != palabra_secreta.end()) {
            for (int i = 0; i < palabra_secreta.size(); ++i) {
                if (palabra_secreta[i] == letra) {
                    palabra_adivinada[i] = letra;
                }
            }
        } else {
            --intentos;
            if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
                --intentos;
            }
            std::cout << "La letra no está en la palabra secreta.\n";
        }
    }

    if (palabra_adivinada == palabra_secreta) {
        std::cout << "¡Felicidades! Has adivinado la palabra secreta: " << palabra_secreta << "\n";
    } else {
        std::cout << "Has perdido. La palabra secreta era: " << palabra_secreta << "\n";
    }

    return 0;
}
