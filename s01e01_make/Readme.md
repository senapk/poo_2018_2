- O comando include realiza uma opção de copiar colar de um arquivo no outro.
- Em C, você pode ter várias vezes a mesma declaração porém apenas uma definição.
- No arquivo .h devem vir as declarações apenas. No .c devem vir as definições.
- O compilador gera os código objeto e o linker junta os códigos objetos no executável.
- O arquivo Makefile dá orientações para o comando make.
- Se não passar parâmetro, o make vai executar o primeiro alvo do Makefile.
- O alvo "all" normalmente é o alvo que compila o projeto todo. O alvo "clean" normalmente limpa os executáveis e temporários.
- Dentro da pasta .vscode tem um arquivo chamado **tasks.json** que ensina o vscode, como chamar o **make all** e mostrar os erros de forma integrada no editor.
    - Se não tiver atalho predefinido para a ação **Run Build Task**, você pode ir em preferências, shortcuts, e adicinar um atalho como **control + shift + b**.
- Se quiser aprender mais sobre makefile leia esse artigo. [LINK](https://www.embarcados.com.br/introducao-ao-makefile/)

