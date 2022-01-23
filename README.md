# TP1
O trabalho final da cadeira de P1 dos alunos Andre e Diogo;
## Compiling
```bash
/gcc -o othello othello_fun.c othello.c
´´´

## Usage

```bash
/othelo
```

## License
[MIT](https://choosealicense.com/licenses/mit/)

## O que temos de fazer da maneira que eu percebi (Andre Banha)

Temos as 3 regras do jogo:
1 --> As pretas jogam sempre primeiro
2 --> Se nao der para jogar entao perde se a vez e o outro joga mas se houver maneira de por uma peça entao ´e obrigado a jogar
3 -->Todas as peças flanqueadas em qualquer movimento devem ser viradas ( mesmo que nao ajudem)

E depois temos as regras que vamos ser obrigados a fazer para o trabalho
--Temos de mostrar as possibilidades de onde por as peças para ambos jogadores
--Lugares vazios sao marcados com "."
--Lugares com pretos sao marcados com "x"
--Lugares com brancos sao marcados com "o"
--Começar com o tabuleiro original
--Começar com o tabuleiro custom lido de um ficheiro
--Fazer o tabuleiro costum onde o jogador pode por as peças que quiser onde quiser
--Terminar o jogo quando quando nao ha mais lugares livres
--Contar as peças de cada jogador e mostrar um vencedor
--Implementar um tipo de AI (isto e para creditos extra e nao e obrigatorio mas mesmo assim pode darnos mais 2 valores!) (TODO)
--Limpar codigo(todo)
--Comentar tudo!(Todo)
--

## Fases

1- Desenhos da aplicaçao e criaçao das funçoes que vamos usar

2-Pensar como usar as funçoes e depois encontrar uma soluçao para o problema geral

#Funçoes obrigatorias

● init_board( board )
    ○ Inicializa o tabuleiro (parâmetro board) com as peças brancas e pretas iniciais.

● print_board( board )
    ○ mostra o tabuleiro atual no standard output (ecrã).

● play( board, line, col, color )
    ○ coloca uma peça de cor color na posição ( line , col ) e vira as peças do adversário
de acordo com as regras indicadas na descrição do jogo..



● flanked( board, line, col, color )
    ○ Conta o número de peças viradas ao jogar numa certa linha e coluna. Se a jogada for
inválida retorna zero.

● int count_flips_dir(board, line, col, delta_line, delta_col,
color)
    ○ Conta quantas peças serão viradas, numa certa linha e coluna, e numa certa numa
direção (definida por delta_line e delta_col, por exemplo se delta_line=1 e
delta_col=1, estamos a considerar a direção “baixo-direita”)

# Recomendaçoes

Sugere-se a organização do código nos seguintes ficheiros:

●othello_func.h : com os protótipos das funções do programa

●othello_func.c : implementação das funções definidas em othello_func.h

●othello.c : implementação da função main()

O comando
## gcc -c othello.c
compila o ficheiro othello.c e gera o ficheiro objeto othello.o
O comando
## gcc -o othello othello.o othello_func.o
liga os ficheiros objeto ( othello.o e othello_func.o ) e cria o executável othello


# Pronto assim temos 2 maneiras de fazer os arrays
Ok diogo temos de fazer os arrays agora podemos fazer cada um um array de 8 e ter 8 ou podemos ter um grande array de arrays por linhas ou colunas

[# # # # # # # #]  -->a
[# # # # # # # #]  -->b
[# # # # # # # #]  -->c
[# # # # # # # #]  -->d
[# # # # # # # #]  -->e
[# # # # # # # #]  -->f
[# # # # # # # #]  -->g
[# # # # # # # #]  -->h

 1  2  3  4  5  6  7  8
 9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64

e depois 
[1 ,9,17,25,33,41,49,57]  -->a
[2,10,18,26,34,42,50,58]  -->b  
[3,11,19,27,35,43,51,59]  -->c
[4,12,20,28,36,44,52,60]  -->d
[5,13,21,29,37,45,53,61]  -->e
[6,14,22,30,38,46,54,62]  -->f
[7,15,23,31,39,47,55,63]  -->g
[8,16,24,32,40,48,56,64]  -->h
