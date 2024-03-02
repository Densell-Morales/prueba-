#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;
struct Lexema {
    string token;
    string tipo;
};

int main() {
    // Expresiones regulares
    regex integerRegex("\\d+");
    regex wordRegex("[a-zA-Z]+");
    regex symbolRegex("[^a-zA-Z0-9\\s]");

    // Palabras clave
    vector<string> keywords = {"if", "else", "while", "for", "int", "float", "print"};

    // Operadores especiales
    vector<string> operadoresDeComparacion = { "<", ">", "<=", ">=", "=", "<>"};

    // Palabras específicas
    vector<string> palabrasEspecificas = {
            "hola", "como", "estas", "dia", "noche", "bien", "mal", "programa", "usuario", "entrada"
            // Agrega más palabras aquí según tus necesidades
    };

    // Palabras específicas
    vector<string> OperadorAritmetico = {
            "+","-","*","/"
            // Agrega más palabras aquí según tus necesidades
    };



    // Bucle principal
    while (true) {
        // Cadena de entrada
        string input;
        cout << "Ingrese expresiones (o 'exit' para salir): ";
        getline(cin, input);

        // Salir del bucle si se ingresa la palabra "exit"
        if (input == "exit") {
            break;
        }

        // Almacenar lexemas en un vector
        vector<Lexema> lexemas;

        // Procesar cada carácter en la entrada
        for (char caracter : input) {
            Lexema lexema;
            lexema.token = caracter;

            // Comprobar si el carácter es una palabra clave
            bool isKeyword = false;
            for (const string& keyword : keywords) {
                if (caracter == keyword[0]) {
                    lexema.tipo = "Keyword";
                    isKeyword = true;
                    break;
                }
            }

            if (!isKeyword) {
                // Comprobar si el carácter es un operador especial
                for (const string& operador : operadoresDeComparacion) {
                    if (caracter == operador[0]) {
                        lexema.tipo = "Operador especial";
                        isKeyword = true;
                        break;
                    }
                }
            }


            if (!isKeyword) {
                // Comprobar si el carácter coincide con alguna palabra
                for (const string& palabra : palabrasEspecificas) {
                    if (input.find(palabra) != string::npos) {
                        lexema.tipo = "Palabra";
                        isKeyword = true;
                        break;
                    }
                }
            }

            if (!isKeyword) {
                // Comprobar si el carácter es un operador aritmetico
                for (const string& Operador : OperadorAritmetico) {
                    if (caracter == Operador[0]) {
                        lexema.tipo = "Operador aritmetico";
                        isKeyword = true;
                        break;
                    }
                }
            }

            if (!isKeyword) {
                // Comprobar si el carácter coincide con alguna expresión regular
                if (regex_match(string(1, caracter), integerRegex)) {
                    lexema.tipo = "Numero";
                } else if (regex_match(string(1, caracter), wordRegex)) {
                    if (isupper(caracter)) {
                        lexema.tipo = "Letra mayuscula";
                    } else if (islower(caracter)) {
                        lexema.tipo = "Letra minuscula";
                    }
                } else if (regex_match(std::string(1, caracter), symbolRegex)) {
                    lexema.tipo = "Simbolo";
                } else {
                    lexema.tipo = "Desconocido";
                }
            }

            // Agregar lexema al vector
            lexemas.push_back(lexema);
        }

        // Mostrar el resultado de manera vertical
        for (const auto& lexema : lexemas) {
            cout << lexema.token << "=" << lexema.tipo << "\n";
        }
    }

    cout << "Programa finalizado.\n";

    return 0;
}