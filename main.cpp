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



        }
    }

    cout << "Programa finalizado.\n";

    return 0;
}