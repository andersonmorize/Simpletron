// Teste do Simpletron Simulator
#include <iostream>
using std::cin;
using std::cout;

#include "Simpletron.h"

int main()
{
    Simpletron simpletron;

    simpletron.welcome();
    
    int instruction = 0, count = 0;

    int memory[100];

    for ( int i = 0; i < 100; i++)
        memory[i] = 0;

    while ( instruction != -99999 )
    {
        // cout << ( count < 10 ) : '0' ?;
        cout << count << " ? ";
        cin >> instruction;

        if( simpletron.isValid( instruction ) && instruction != -99999)
            memory[count] = instruction;
        else if ( instruction != -99999 )
        {
            while( !simpletron.isValid( instruction ) && instruction != -99999 )
            {
                cout << "*** valor inválido ***\n";
                cout << "*** digite novamente ***\n";
                cout << count << " ? ";
                cin >> instruction;
            }

            memory[count] = instruction;
        }

        count++;
    }

    simpletron.setMemory(memory);

    simpletron.run();
}