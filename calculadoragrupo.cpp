#include <iostream>
#include <string>
#include <vector>
setlocale(LC_ALL,"Portuguese");

using namespace std;

struct Operacao {
    int num1;
    int num2;
    char op;
    int resultado;
};

int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

int multiplicacao(int a, int b) {
    return a * b;
}

int divisao(int a, int b) {
    if (b == 0) {
        cout << "Erro: divis�o por zero!" << endl;
        return 0;
    } else {
        return a / b;
    }
}

void calcular(char op, int num1, int num2, vector<Operacao>& historico) {
    int resultado;
    
    switch (op) {
        case '+':
            resultado = soma(num1, num2);
            break;
        case '-':
            resultado = subtracao(num1, num2);
            break;
        case '*':
            resultado = multiplicacao(num1, num2);
            break;
        case '/':
            resultado = divisao(num1, num2);
            break;
        default:
            cout << "Opera��o inv�lida!" << endl;
            return;
    }
    
    cout << "Resultado: " << resultado << endl;
    cout << num1 << " " << op << " " << num2 << " = " << resultado << endl;
    
    Operacao nova_operacao = {num1, num2, op, resultado};
    historico.push_back(nova_operacao);
}

main() {
    char op;
    int num1, num2;
    vector<Operacao> historico;
    
    bool repeat = true;
    while (repeat) {
        cout << "Digite a opera��o (+, -, *, /): ";
        cin >> op;
        
        cout << "Digite o primeiro n�mero: ";
        cin >> num1;
        
        cout << "Digite o segundo n�mero: ";
        cin >> num2;
        
        calcular(op, num1, num2, historico);
        
        cout << "Deseja continuar? (s/n): ";
        char choice;
        cin >> choice;
        
        if (choice == 's' || choice == 'S') {
            repeat = true;
        } else {
            repeat = false;
        }
    }
    
    cout << "Hist�rico de c�lculos:" << endl;
    for (int i = 0; i < historico.size(); i++) {
        Operacao op = historico[i];
        cout << op.num1 << " " << op.op << " " << op.num2 << " = " << op.resultado << endl;
    }
}
