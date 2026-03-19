#include <iostream>
#include <vector>
#include <string>
#include <fstream> 

using namespace std;

// Funcao para salvar as tarefas no arquivo
void salvarArquivo(const vector<string>& tarefas) {
    ofstream arquivo("tarefas.txt");
    if (arquivo.is_open()) {
        for (const string& t : tarefas) {
            arquivo << t << endl;
        }
        arquivo.close();
    }
}

// Funcao para carregar as tarefas ao iniciar
void carregarArquivo(vector<string>& tarefas) {
    ifstream arquivo("tarefas.txt");
    string linha;
    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            if (!linha.empty()) {
                tarefas.push_back(linha);
            }
        }
        arquivo.close();
    }
}

int main() {
    vector<string> tarefas;
    int opcao = 0;
    string tarefa;

    // 1. Tenta carregar as tarefas assim que o programa abre
    carregarArquivo(tarefas);

    do {
        // Limpar a tela para ficar bonito (Windows)
        system("cls");

        cout << "========================================" << endl;
        cout << "       MEU GERENCIADOR DE TAREFAS       " << endl;
        cout << "========================================" << endl;

        if (tarefas.empty()) {
            cout << "\n   [ Nenhuma tarefa pendente ]\n" << endl;
        } else {
            for (int i = 0; i < tarefas.size(); i++) {
                cout << i + 1 << ". " << tarefas[i] << endl;
            }
        }

        cout << "----------------------------------------" << endl;
        cout << "1. Adicionar | 2. Remover | 3. Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;
        cin.ignore();

        if (opcao == 1) {
            cout << "Nova tarefa: ";
            getline(cin, tarefa);
            tarefas.push_back(tarefa);
            salvarArquivo(tarefas); // Salva logo apos adicionar
        } 
        else if (opcao == 2) {
            int indice;
            cout << "Numero para remover: ";
            cin >> indice;
            if (indice > 0 && indice <= tarefas.size()) {
                tarefas.erase(tarefas.begin() + (indice - 1));
                salvarArquivo(tarefas); // Salva logo apos remover
            }
        }

    } while (opcao != 3);

    cout << "\nSalvando e saindo... Ate logo!" << endl;
    return 0;
}