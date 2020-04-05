#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::internal;
using std::showpos;
using std::noshowpos;

#include <iomanip>
using std::setfill;
using std::setw;

#include "Simpletron.h"

Simpletron::Simpletron()
{
    for ( int i = 0; i < 100; i++)
        this->memory[i] = 0;

    this->ward = false;
}

void Simpletron::welcome()
{
    cout << "*** Bem vindo ao Simpletron!                               ***\n"
        << "*** Por favor insira uma instrução                         ***\n"
        << "*** (ou data word) por vez em seu programa. Eu vou digitar ***\n"
        << "*** o número de alocação e o ponto de interrogação (?).    ***\n"
        << "*** Então você digita a palavra para a alocação.           ***\n"
        << "*** Digite o número -99999 para parar de inserir dados     ***\n"
        << "*** no seu programa.                                       ***\n\n";
}

void Simpletron::setMemory( int memory[] )
{
    for ( int i = 0; i < 100; i++ )
        this->memory[i] = memory[i];

    cout << "\n*** Program loading completed ***\n";
    cout << "*** Program execution begins ***\n";
}

void Simpletron::run()
{
    do {

        startVariables();

        switch ( this->operationCode )
        {
            case this->READ:
                this->read();
                break;
            case this->WRITE:
                this->write();
                break;
            case this->LOAD:
                this->load();
                break;
            case this->STORE:
                this->store();
                break;
            case this->ADD:
                this->add();
                break;
            case this->SUBTRACT:
                this->subtract();
                break;
            case this->DIVIDE:
                this->divide();
                break;
            case this->MULTIPLY:
                multiply();
                break;
            case this->BRANCH:
                this->branch();
                break;
            case this->BRANCHNEG:
                this->branchneg();
                break;
            case this->BRANCHZERO:
                this->branchzero();
                break;
            case this->HALT:
                this->halt();
                break;
        }

    } while ( !this->ward );
}

void Simpletron::dump()
{
    cout << endl << endl;
    cout << "REGISTERS:" << endl;
    cout << "accumulator" << setw( 15 ) << setfill( ' ' ) << " ";  
    cout << internal << showpos << setfill( '0' ) << setw( 5 ) << this->accumulator << endl;
    cout << "counter" << setw( 22 ) << setfill( ' ' ) << " ";
    cout << noshowpos << setfill( '0' ) << setw( 2 ) << this->counter << endl;
    cout << "instructionRegister" << setw( 7 ) << setfill( ' ' ) << " ";
    cout << internal << showpos << setfill( '0' ) << setw( 5 ) << this->instructionRegister << endl;
    cout << "operationCode" << setw( 16 ) << setfill( ' ' ) << " ";
    cout << noshowpos << setfill( '0' ) << setw( 2 ) << this->operationCode << endl;
    cout << "operand" << setw( 22 ) << setfill( ' ' ) << " ";
    cout << noshowpos << setfill( '0' ) << setw( 2 ) << this->operand << endl << endl;

    cout << "MEMORY:" << endl;
    cout << "  ";
    for ( int i = 0; i < 10; i++ )
        cout << setfill( ' ' ) << setw(6) << i;

    cout << endl;

    for ( int i = 0; i < 100; i++ )
    {
        if ( i % 10 == 0 )
        {
            cout << endl << ((i == 0) ? " " : "") << noshowpos << i << setfill( '0' ) << setw( 1 );
        }

        cout << " " << internal << showpos << setfill( '0' ) << setw( 5 ) << this->memory[i];
    }

    cout << endl << endl;
}

bool Simpletron::startVariables()
{
    if ( this->isValid( memory[ counter ] ) ) {
        
        this->instructionRegister = memory[ counter ];
        this->operationCode = this->instructionRegister / 100;
        this->operand = this->instructionRegister % 100;

        return true;

    } else {

        return false;

    }
}

bool Simpletron::isValid( int instruction )
{
    if ( instruction < -9999 || instruction > 9999 )
        return false;
    
    return true;
}

// lê uma palavra do teclado para uma posição especifica da memoria
void Simpletron::read()
{
    cout << " ? ";
    try {
        cin >> memory[ operand ];
    }
    catch ( ... ) {
        cout << "\n*** Error na leitura da memoria ***"
            << "\n*** A execução do Simpletron foi interrompida ***\n";  
    }
    
    ++this->counter;
}

// escreve na tela uma palavra de uma posição especifica na memoria
void Simpletron::write()
{
    try {
        cout << memory[ operand ];
    }
    catch ( ... ) {
        cout << "\n*** Error na exibição da memoria ***"
            << "\n*** A execução do Simpletron foi interrompida ***\n";
    }
    ++this->counter;
}

// carrega uma palavra de uma posição especifica na memória para o acumulador
void Simpletron::load()
{
    try {
        accumulator = memory[ operand ];
    }
    catch ( ... ) {
        cout << "\n*** Error no carregamento da memoria no acumulador ***"
            << "\n*** A execução do Simpletron foi interrompida ***\n";
    }
    ++this->counter;
}

// armazena uma palavra do acumulador para um posição especifica na memoria
void Simpletron::store()
{
    try {
        memory[ operand ] = accumulator;
    } catch ( ... ) {
        cout << "\n*** Error no carregamento do acumulador na memoria ***"
            << "\n*** A execução do Simpletron foi interrompida ***\n";
    }
    ++this->counter;
}

// adiciona uma palavra de uma posição especifica na memoria
// a palavra no acumulador
void Simpletron::add()
{
    try {
        accumulator += memory[ operand ];
    } catch ( ... ) {
        cout << "\n*** Error na tentativa de soma ***"
            << "\n*** A execução do Simpletron foi interrompida ***\n";
    }
    ++this->counter;
}

// subtrai uma palavra de uma posição especifica na memoria
// da palavra no acumulador
void Simpletron::subtract()
{
    try {
        accumulator -= memory[ operand ];
    } catch ( ... ) {
        cout << "\n*** Error na tentativa de subtração ***"
            << "\n*** A execução do Simpletron foi interrompida ***\n";
    }
    ++this->counter;
}

// divide uma palavra de posição especifica na memoria
// pela palavra no acumulador
void Simpletron::divide()
{
    try {
        accumulator = memory[ operand ] / accumulator;
    } catch ( ... ) {
        cout << "\n*** Error na tentativa de divisão ***"
            << "\n*** A execução do Simpletron foi interrompida ***\n";
    }
    
    ++this->counter;
}

// multiplica uma palavra de uma posição especifica na memoria
// pela palavra no acumulador
void Simpletron::multiply()
{
    try {
        accumulator = memory[ operand ] * accumulator;
    } catch ( ... ) {
        cout << "\n*** Error na tentativa de multiplicação ***"
            << "\n*** A execução do Simpletron foi interrompida ***\n";
    }
    ++this->counter;
}

// desvia para uma posição especifica na memoria
void Simpletron::branch()
{
    try {
        counter = operand;
    } catch ( ... ) {
        cout << "\n*** Error no desvio de memoria ***"
            << "\n*** A execução do Simpletron foi interrompida ***\n";
    }
    
}

// desvia para uma posição especifia na memoria se o acumulador for negativo
void Simpletron::branchneg()
{
    try {
        if ( accumulator < 0 )
            this->counter = this->operand;
        else
            ++this->counter;
    } catch ( ... ) {
        cout << "\n*** Error no desvio de memoria ***"
            << "\n*** A execução do Simpletron foi interrompida ***\n";
    }
}

// desvia para uma posição especifica na memoria se o acumulador for 0
void Simpletron::branchzero()
{
    try {
        if ( accumulator == 0 )
            this->counter = this->operand;
        else
            ++this->counter;
    } catch ( ... ) {
        cout << "\n*** Error no desvio de memoria ***"
            << "\n*** A execução do Simpletron foi interrompida ***\n";
    }
}

void Simpletron::halt()
{
    this->ward = true;
    this->dump();
    cout << "\n*** Simpletron execution terminated ***\n";
}
