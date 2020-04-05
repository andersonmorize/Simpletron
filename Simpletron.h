// Simpletron Simulator
// Simulador de Simpletor para tester e depurar os programas
// em SML( Simpletron Machile Linguage )
#ifndef SIMPLETRON_H
#define SIMPLETRON_H

class Simpletron
{
public:
    Simpletron();
    void welcome();
    bool isValid( int ); // verifica se o valor é valido para o padroes simpletron
    void setMemory( int[] );
    void run(); // executa o codigo SML
    void dump(); // imprime o nome e o conteudo de cada registro

    enum opcode {
        // operações de entrada/saida
        READ = 10,
        WRITE = 11,
        
        // operações de carregamento e armazenamento
        LOAD = 20,
        STORE = 21,
        
        // operações aritmeticas
        ADD = 30,
        SUBTRACT = 31,
        DIVIDE = 32,
        MULTIPLY = 33,

        // operações de transferencia de controle
        BRANCH = 40,
        BRANCHNEG = 41,
        BRANCHZERO = 42,
        HALT = 43 // suspende - o programa completou sua tarefa
    };

private:

    int memory[100]; // memoria do simpletron
    int accumulator = 0; // rgistrador acumulador
    int counter = 0; // monitora a posição na memoria que contem a instrução sendo realizada
    int operationCode = 0; // indica a operação que está sendo atualmente realizada
    int operand = 0; // indica a posição da memoria em que a instrução atual opera
    int instructionRegister = 0; // instrução que será realizada
    bool ward; // responsavel por encerrar a aplicação

    bool startVariables(); // seta os valores de operationCode, operand e instructionRegiste

    // funções equivalentes as suas constantes
    void read();
    void write();
    void load();
    void store();
    void add();
    void subtract();
    void divide();
    void multiply();
    void branch();
    void branchneg();
    void branchzero();
    void halt();
};


#endif