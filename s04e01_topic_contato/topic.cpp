class Pass
    nome: string
    idade: int
    
    Pass(nome, idade)
    toString(): string

class Topic
    nPref: int
    cadeiras: vector<Pass*>

    Topic(nPref, lotacao):
        cadeiras(lotacao, nullptr), 
        nPref(nPref)

    toString():
        for(i = 0; i < cadeiras.size(); i++)
            saida <<  (i < nPref ? '@' : '=');
            saida << (cadeiras[i] != nullptr ? 
                      cadeiras[i].toString() : "");
            saida << " ";
    int find(nome)
    int findPref(){
    }
    int findComum(){
    }
    in(nome, idade){
        if(find(nome) == -1)
            ja esta no trem
        pass = new Pass(nome, idade)
        if(pref)
            pos = findPref()
            if(pos == -1)
    }

    out(nome)
        pos = find(nome)
        if(pos == -1)
            nao esta 
        delete cadeiras[pos]
        cadeiras[pos] = nullptr





