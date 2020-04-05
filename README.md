# Simpletron

Solução das questões 8.18 e 8.19 do livro C++ Como Programar - Deitel
O desafio foi criar um computador que chamaremos de Simpletron. Como seu nome implica, é uma
máquina simples, mas também é uma máquina poderosa. O Simpletron executa programas escritos na única linguagem
que ele entende diretamente, isto é, a Simpletron Machine Language ou, abreviadamente, SML.

## SML (Simpletron Machine Language)

Todas as informações no Simpletron são tratadas em termos de palavras. Uma palavra é
um número decimal de quatro dígitos com sinal como +3364 , -1293 , +0007 , -0001 etc. Os primeiros dois dígitos de cada 
instrução do SML são o código de operação que especifica a operação a ser realizada. Os últimos dois dígitos de uma instrução
de SML são operandos — o endereço da posição da memória contendo a palavra à qual a operação se aplica.

#### Códigos de operação de Simpletron Machine Language (SML).
Código de operação | Significado
-------------------|--------------
READ = 10; | Lê uma palavra do teclado para uma posição específica da memória.
WRITE = 11; | Escreve na tela uma palavra de uma posição específica da memória.
LOAD = 20; | Carrega uma palavra de uma posição específica na memória para o acumulador.
STORE = 21; | Armazena uma palavra do acumulador para uma posição específica na memória.
ADD = 30; | Adiciona uma palavra de uma posição específica na memória à palavra no acumulador (deixa o resultado no acumulador).
SUBTRACT = 31; | Subtrai uma palavra de uma posição específica na memória da palavra no acumulador (deixa o  resultado no acumulador)
DIVIDE = 32; | Divide uma palavra de uma posição específica na memória pela palavra no acumulador (deixa o resultado no acumulador).
MULTIPLY = 33; | Multiplica uma palavra de uma posição específica na memória pela palavra no acumulador (deixa o resultado no acumulador).
BRANCH = 40; | Desvia para uma posição específica na memória.
BRANCHNEG = 41; | Desvia para uma posição específica na memória se o acumulador for negativo.
BRANCHZERO = 42; | Desvia para uma posição específica na memória se o acumulador for zero.
HALT = 43; | Suspende — o programa completou sua tarefa.

#### Exemplo de SLM 1
Posição | Número | Instrução
--------|--------|----------
00 | +1007 | (Read A)
01 | +1008 | (Read B)
02 | +2007 | (Load A)
03 | +3008 | (Add B)
04 | +2109 | (Store C)
05 | +1109 | (Write C)
06 | +4300 | (Halt)
07 | +0000 | (Variable A)
08 | +0000 | (Variable B)
09 | +0000 | (Result C)

#### Exemplo de SML 2
Posição | Número | Instrução
--------|--------|----------
00 | +1009 | (Read A)
01 | +1010 | (Read B)
02 | +2009 | (Load A)
03 | +3110 | (Subtract B)
04 | +4107 | (Desvio negativo para 07)
05 | +1109 | (Write A)
06 | +4300 | (Halt)
07 | +1110 | (Write B)
08 | +4300 | (Halt)
09 | +0000 | (Variable A)
10 | +0000 | (Variable B)

## Simpletron Simulator
Seu Simpletron Simulator transformará o computador que você está utilizando em
um Simpletron, e você realmente será capaz de executar, testar e depurar os programas de SML
