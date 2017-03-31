![dfgfhff.jpg](https://bitbucket.org/repo/6dKBKj/images/3714505993-dfgfhff.jpg)
# Labirinto Perfeito#

Autor: Prof David Sena (sena.ufc@gmail.com)

## 1 - Instruções Gerais ##
O objetivo desse trabalho é fazer um código que resolva e gere um labirinto perfeito. O trabalho será dividido em duas partes, a ideia é começar recebendo o labirinto e as posições, de início e de final, percorrê-lo e encontrar um caminho que interligue as duas posições, resolvendo assim o labirinto. Logo após deve-se gerar o labirinto perfeito, ou seja um labirinto que tem apenas um caminho a partir de qualquer ponto do labirinto para qualquer outro ponto.

![labirinto.jpg](https://bitbucket.org/repo/6dKBKj/images/1540255883-labirinto.jpg)

## 1.1 - Descrição do Problema ##
O labirinto pode ser visto como uma matriz m x n, tal que m = número de linhas e n = número de colunas e que em cada posição(linha,coluna) seja possível verificar se é parede ou está livre. Pode se dizer que o labirinto é fechado, isto é, que há paredes ao redor, nas extremidades. O usuário deve informar duas posições dessa matriz, e o programa mostra o caminho livre que liga as duas possições. Para descobrir o caminho deve-se testar sempre quatro posições (cima x baixo x esquerda x direita), os vizinhos, verificando se está livre para poder ”caminhar”.

## 2 - Implementação Parte 1 ##
O programa deve receber duas posições válidas, uma pra indicar o ínicio e outra o fim do percurso para quer seja encontrado um caminho, como pode-se afirmar que a partir de qualquer ponto do labirinto para qualquer outro ponto existe um caminho, pois se trata de um labirinto perfeito, deve-se resolver o labirinto encontrando este caminho apartir das posições dadas pelo usuário. Exemplo com uma matriz 10 x 20.

## 2.1 - Exemplo Parte 1 ##
O usuário deve informar duas posições. A posição de início e de fim, representadas respectivamente pelas cores vermelha e verde. Com as posições informadas o programa percorre a matriz e com a utilização de uma pilha, descartas as posições que levam pra uma parede, formando o caminho apenas com posições livres. Resolvendo o labirinto perfeito.

A primeira parte é concluida com a solução do labirinto perfeito.

![qtela.jpg](https://bitbucket.org/repo/6dKBKj/images/603059523-qtela.jpg)

## 3 - Implementação Parte 2 ##
Seu objetivo é implementar e gerar o labirinto perfeito. Cria-se uma matriz m x n, dados que pode ser informado pelo o usuário, onde m é a altura, ou seja a quantidade de linhas e n a largura, quantidade de colunas.
Receba uma posição válida pra começar a percorrer a matriz e com a utilização de uma pilha vai gerando o labirinto, se durante o percurso para preencher a matriz chegar e esbarrar em uma parede e não tiver nenhum caminho livre, volta na pilha até o primeiro caminho livre e continua dele até que a matriz seja preechida e o labirinto seja formardo.

## 3.1 - Exemplo Parte 2 ##
O programa deve criar uma matriz m x n e solicitar ao usuário que informe uma posição válida pra começar a preencher a matriz, gerando o labirinto perfeito. Abaixo um exemplo com uma matriz 10 x 20.

Primeira interação o usuário escolhe uma posição válida.

![ptela.jpg](https://bitbucket.org/repo/6dKBKj/images/2683657857-ptela.jpg)

O programa, com a utilização de uma pilha, representado pela cor amarela, percorre a matriz, preechendo-a para formar o labirinto.

![stela.jpg](https://bitbucket.org/repo/6dKBKj/images/1958364758-stela.jpg)

A segunda parte é concluida e mostra o labirinto perfeito na tela.

![ttela.jpg](https://bitbucket.org/repo/6dKBKj/images/3337980098-ttela.jpg)

Finalizou, sair leberando todas as memórias alocadas.

## 4 - Todo
Procurar a saida recursivamente. Contar quantas saidas existes. Criar um caminho que una todas as saidas.
Achar o caminho mais curto ou o mais longo
