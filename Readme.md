## Trabalhos
- 1. 01 Carro  
- 2. 02 Topic
- 2. 03 Contato
- 3. 04 Banco (extra)
- 2. 05 Tamagochi
- 3. 06 Agiota
- 1. 07 Refazer com repositorio (Agiota)
- 1. 08 Repositorio I
- 2. 09 Anotações
- 3. 10 Salário
- 4. 11 Trem
- 4. 12 Twitter


## Download
- Vscode
    - https://code.visualstudio.com/docs/?dv=win
- Git for windows
    - https://gitforwindows.org/
- Mingw
    - https://osdn.net/frs/redir.php?m=c3sl&f=mingw%2F68260%2Fmingw-get-setup.exe
- GitKraken (opcional)
    - https://www.gitkraken.com/

## Instale o git

```
while(true)
	clique next
```

## Instalando o MinGW
- Execute o instalador do Mingw
    - instale no destino padrão C:\MinGW
- Escolha os pacotes
    - mingw-developer-tookit-bin
    - mingw32-gc-g++-bin
- Vá em Instalação
    - Apply Changes
    - Apply
- Espere e tenha fé

## Configurando o MinGW no Path

- Control Panel, Advanced System Settings
- Advanced tab, Environment Variables
- System Variables (no quadrado de baixo, não no de cima)
- Selecione a variável "PATH" (no quadrado de baixo)
- Edit
- Adicione em novas linhas 
    - C:\MinGW\bin
    - C:\MinGW\msys\1.0\bin
- abra um **NOVO** cmd e teste os seguintes comandos
    - bash
    - gcc --version
    - make --version

## Visual Studio Code
- Rode o instalador do vscode.
- Abra a pasta do seu projeto.
- Abra o terminal integrado com control '
- Crie o arquivo Makefile
```
CC = gcc
CFLAGS = -Wall -std=c99 -g
```

- Compile seu código e execute
```
$ ls
main.c Makefile
$ make main
gcc -Wall -std=c99 -g main.c -o main
$ ./main
hello world
```

## Configurando o debug
- Lembre de Compilar com a flag -g
- Clique no potó
- Configure o arquivo executavel colocando o nome do seu arquivo executável
- Configure o path do **gdb.exe**

# Aula s01e01

- Valores
    - Honestidade(vocês) e Justiça(eu)
- Modelo de aula
    - Participação em sala de aula
    - Interativa
    - Prática
    - Atividades em dupla em sala de aula
    - Assiduidade: não faz a atividade ou não participa, leva falta
- Plágio
    - Uma forma de corrupção estudantil
    - Obter vantagem ilícita sobre o sistema de avaliação.
    - Dizer que fez algo que não fez ou sabe algo que não sabe.
    - Infringir as regras definidas pela atividade.
    - Procurar pelas respostas de uma atividade e omitir isso.
- Trabalhos
    - vou avaliar os **relatórios**, nem sempre os códigos
    - alguns podem ser feitos em dupla
    - outros, obrigatoriamente individuais
    - nota (1 - 4) para cada atividade
    - prazo fixo sem prorrogação
        - nota de reboot - estudar e corrigir
- Avaliação
    - mini avaliações para acompanhamento quizenais (30 min)
    - trabalhos semanais (quinzenais)
    - provas se necessário
    - cada atividade ou prova tem um peso
    - código que tem identação errada sofrerá redução de nota
    - avaliar funcionalidades entregues. Código que não funciona não será avaliado.
        - a nota final é feita pela média ponderada de todas as atividades
    - planilha de notas e repositórios
- Material didático e ajuda
    - exemplos em sala de aula - github atualizado toda aula
    - gravação da aula
    - livro e site
- Entrega de material
    - Moodle
    - Git da disciplina
    - Git do repositório de trabalhos

- Material de Leitura sobre Makefiles: https://www.embarcados.com.br/introducao-ao-makefile/
