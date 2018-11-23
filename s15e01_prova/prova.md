# Orientações da Prova

# (Auto) Avaliação de POO

A prova deve ser feita de forma individual sem ajuda externa. Você pode fazer consulta a internet para tirar dúvidas de linguagem ou debugar um erro. Pode inclusive pesquisar nos trabalhos que você já fez.

O tempo total de prova é 6 horas na frente do computador que você deve marcar. Em no máximo 6 intervalos de 1 hora de prova. Mas entre o horário que você começar e terminar são no máximo 24 horas.
Exemplo: 
- Senta, começa a fazer, 2 horas de prova.
- Sai pra pensar, passear, almoçar, etc.
- Volta, passa mais 1 hora de prova. 
- Sai pra rezar, pedir luz a Deus.
- Volta pro computador e mais uma hora de prova.
- Volta e completa a prova com mais 1 hora.
...
- Total: 6 horas de prova na frente do computador e atividade enviada em até 24 horas que você começou.

Se por diversão, quiser continuar tentando até o fim do prazo, pela sua honra, você pode, mas deixe claro no relatório o que você fez dentro das 6 horas e o que fez fora das 6 horas. Sugiro fazer o máximo que puder dentro do tempo, começando pelas mais fáceis.

Ao final, você deve enviar um arquivo zipado com seu nome no formato fulano_da_silva.zip.
Dentro dele deve ter.
- relatorio.txt
- projeto.cpp
- questões.txt

No relatório, você faz escrever como foi a prova, quais as questões que fez ou que não fez e se fez algo além fora das 6 horas de prova.

O que for feito fora do tempo vai ser considerado parcialmente como extra. Lembre que essa não é uma nota absoluta, é uma avaliação com auto avaliação. O importante é o conjunto daquilo que você já fez, aprendeu, colocou no seu git, desenvolveu em sala.

Lembre: envie o arquivo seu_nome.zip para o link a seguir até meio dia.

https://www.dropbox.com/request/YA1n5fd2z7tkYKvi48Rd

Se não for fazer a prova agora, pare por aqui e volte a esse arquivo mais tarde. Bye.

Projeto: 
Complete o projeto da Agenda Híbrida.

# Parte 1 - Favoritos
- Implemente a funcionalidade de Favoritar, Desfavoritar e mostrar favoritos.
- Cada Contato deve possuir um atributo _**bool favorited**_ que define se ele é ou não favorito.
- A agenda deve ter uma lista de favoritos, além da lista de contatos. A lista de favoritos deve ser um 

```c++
class Contato
    - bool favorited

class Agenda
    - map<string, Contato*> favoritos;
```

- Ao mostrar a agenda, os contatos favoritados devem iniciar com '@', enquanto os contatos normais iniciam com '-'.
- Implemente as ações de favoritar(fav), desfavoritar(unfav), e mostrar favoritos(favorited).
```bash
$agenda
- ana C [0:casa:4567][1:oi:8754]
- bia C [0:vivo:5454]
- eva C [0:oi:8585][1:claro:9999]
- rui C [0:casa:3233]
- zac C [0:fixo:3131]

$fav eva
$fav ana
$fav ana
$fav zac
$fav rex
fail: contato rex nao existe

$agenda
@ ana C [0:casa:4567][1:oi:8754]
- bia C [0:vivo:5454]
@ eva C [0:oi:8585][1:claro:9999]
- rui C [0:casa:3233]
@ zac C [0:fixo:3131]

$desfav zap
@ ana C [0:casa:4567][1:oi:8754]
- bia C [0:vivo:5454]
@ eva C [0:oi:8585][1:claro:9999]
- rui C [0:casa:3233]
- zac C [0:fixo:3131]

$favorited
@ ana C [0:casa:4567][1:oi:8754]
@ eva C [0:oi:8585][1:claro:9999]


```
- Adapte as outras funções da agenda para que a adicão ou remoção de contatos e favoritar e desfavoritar mantenha o sistema íntegro.

- Altere a parte de incluir contato para se o contato ja existir, apenas adicionar os telefones.
---

# Parte 2 - Polimorfismo

Altere sua agenda para suportar polimorfismo de Entrada. Qualquer coisas que tiver um id, um método toString e puder ser favoritada poderá ser guardada na agenda.

```c++

class Entry {
    bool favorited;
public:
    Entry()
    virtual ~Entry()
    virtual string getId()
    virtual void setFavorited(bool value)
    virtual bool isFavorited()
    virtual string toString()
};

class Agenda {
    map<string, Entry*> m_entries;
    map<string, Entry*> m_favorites;
public:
    void addEntry(Entry * entry)
    void rmEntry(string id)
    void favorite(string idEntry)
    void unfavorite(string idEntry)
    vector<Entry*> getFavorited()
    Entry * getEntry(string id)
    vector<Entry*> getEntries()
    vector<Entry*> search(string pattern)
    string toString()
};
```

Além de contatos, sua agenda poderá guardar anotações.
Como sua agenda não "sabe mais" o que é um contato ou uma anotação, 
você deve montar uma classe que herda de Agenda e contém os métodos extras
que você precisar

```c++
class AgendaMaster : public Agenda{
public:
    AgendaMaster()
    Contato * getContato(string id);
    Note * getNote(string id);
```

```c++
class Note : public Entry { 
    string id;
    vector<string> itens;
public:
    Note(string id = "")
        :id(id)
    {}
    string getId(){
        return id;
    }
    void addItem(string item){
        itens.push_back(item);
    }
    string toString(){
        string saida = Entry::toString() + " N [ ";
        for(auto item : itens){
            saida += item + " ";
        }
        return saida + "]";
    }
};
```




