# TP1
O trabalho final da cadeira de P1 dos alunos Andre e Diogo;
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
--Temos de mostrar as possibilidades de onde por as peças para ambos jogadores(TODO)
--Lugares vazios sao marcados com "." (TODO)
--Lugares com pretos sao marcados com "x" (TODO)
--Lugares com brancos sao marcados com "o" (TODO)
--Começar com o tabuleiro original (TODO)
--Começar com o tabuleiro custom lido de um ficheiro(TODO)
--Fazer o tabuleiro costum onde o jogador pode por as peças que quiser onde quiser(TODO)
--E decidido random quem fica com as pretas (o primeiro a jogar) (TODO)
--Terminar o jogo quando quando nao ha mais lugares livres(TODO)
--Contar as peças de cada jogador e mostrar um vencedor(TODO)
--Implementar um tipo de AI (isto e para creditos extra e nao e obrigatorio mas mesmo assim pode darnos mais 2 valores!) (TODO)

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