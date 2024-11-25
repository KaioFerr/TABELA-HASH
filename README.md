# Tabela Hash em cpp
Uma tabela hash é uma estrutura de dados que associa chaves a valores, permitindo buscas rápidas. Ela utiliza uma função hash para transformar uma chave em um índice de um array, onde o valor associado à chave será armazenado.
## Vantagens

1. **Acesso rápido**: O principal benefício de uma tabela hash é o acesso rápido aos dados. A busca, inserção e remoção podem ser realizadas em tempo constante \(O(1)\) na maioria das situações.
2. **Eficiência**: Quando bem dimensionada e com uma boa função hash, a tabela hash pode ser muito eficiente, proporcionando desempenho superior em relação a outras estruturas de dados como listas ou árvores.
3. **Simples de implementar**: A estrutura é relativamente simples de implementar.
4. **Flexibilidade**: Tabelas hash podem ser usadas em uma ampla variedade de cenários, como caches, buscas rápidas e contagem de frequências.

## Desvantagens

1. **Colisões**: Quando duas ou mais chaves geram o mesmo índice, ocorre uma colisão, o que pode afetar a performance. Resolver colisões (por exemplo, com encadeamento ou endereçamento aberto) pode aumentar o custo de operações.
2. **Uso de memória**: As tabelas hash podem consumir mais memória do que outras estruturas de dados devido à necessidade de alocar espaço extra para evitar colisões e armazenar os dados.
3. **Desempenho dependente da função hash**: A performance de uma tabela hash depende diretamente da qualidade da função hash. Uma função hash ruim pode levar a uma distribuição desigual dos índices e a muitas colisões, prejudicando o desempenho.
4. **Não ordenada**: As tabelas hash não mantêm a ordem dos elementos, o que pode ser uma limitação se for necessário acessar os elementos de forma ordenada.
5. **Rehashing**: Quando a tabela hash atinge uma carga muito alta, pode ser necessário realizar o rehashing (aumentar o tamanho da tabela e redistribuir os elementos), o que pode ser um processo caro em termos de tempo.

## Colisões em Tabelas Hash

Uma **colisão** ocorre quando duas ou mais chaves diferentes geram o mesmo índice na tabela hash. Para resolver essas colisões, são usadas técnicas de **sondagem**. Duas abordagens comuns são:

### Teste Linear (Linear Probing)

O **teste linear** é uma técnica de sondagem onde, ao ocorrer uma colisão, o próximo índice é verificado sequencialmente até encontrar um índice vazio. O processo continua até encontrar um local disponível ou até percorrer toda a tabela.

- **Vantagem**: Simples de implementar e eficiente quando a tabela está parcialmente cheia.
- **Desvantagem**: Pode gerar agrupamentos (clustering) de entradas, reduzindo a eficiência.

### Sondagem Quadrática (Quadratic Probing)

A **sondagem quadrática** resolve colisões com um salto crescente, ou seja, ao invés de verificar os próximos índices de forma sequencial, ela verifica índices usando uma função quadrática, como \(h(k) + i^2\), onde \(i\) é o número da tentativa de sondagem.

- **Vantagem**: Reduz o agrupamento (clustering) comparado ao teste linear, distribuindo melhor os elementos.
- **Desvantagem**: Pode ainda levar a colisões e, em alguns casos, pode ser difícil de implementar corretamente.

Essas duas técnicas são utilizadas para garantir que as tabelas hash continuem eficientes, mesmo quando ocorrem colisões durante a inserção de dados.

## Estrutura de uma Tabela Hash
```cpp
  class Hash {
    public:
        Hash(int max_items = 100);
    
        ~Hash();
    
        bool isFull() const;
        int getLength() const;
    
        void retriveItemTesteLinear( Aluno& aluno, bool& found);
        void retriveItemTesteQuadratico(Aluno &aluno, bool &found);
        void insertItemTesteLinear( Aluno aluno);
        void insertItemTesteQuadratico(Aluno aluno);
        void deleteItemTesteLinear( Aluno aluno);
        void deleteItemTesteQuadratico(Aluno aluno);
    
        void print();
    
    private:
        int getHash( Aluno aluno);
        int max_items;
        int length;
        Aluno* structure;
};
```
## Inserção de Item na Tabela
```cpp
  void Hash::insertItemTesteLinear(Aluno aluno) {
    int location;
    location = getHash(aluno);
    while (structure[location].getId() > 0) location = (location + 1) % max_items;
    structure[location] = aluno;
    length++;
}

void Hash::insertItemTesteQuadratico(Aluno aluno) {
    int location = getHash(aluno);
    int attempt = 0;

    while (structure[(location + attempt * attempt) % max_items].getId() > 0) {
        attempt++;
        if (attempt == max_items) {
            throw std::overflow_error("Tabela Hash cheia");
        }
    }

    location = (location + attempt * attempt) % max_items;
    structure[location] = aluno;
    length++;
}
```
## Deletar um Item na Tabela
```cpp
  void Hash::deleteItemTesteLinear(Aluno aluno) {
    int locInicial = getHash(aluno);
    bool continuarBuscando = true;
    int location = locInicial;
    do {
        if(structure[location].getId() == aluno.getId() || structure[location].getId() == -1) {
            continuarBuscando = false;
        }else
            location = (location + 1) % max_items;

    }while (location != locInicial && continuarBuscando);

    if (structure[location].getId() == aluno.getId()) {
        structure[location] = Aluno(-2, "");
        length--;
    }
}

void Hash::deleteItemTesteQuadratico(Aluno aluno) {
    int locInicial = getHash(aluno);
    int i = 0; //
    int location = locInicial;
    bool encontrou = false;

    do {
        int probe = (locInicial + i * i) % max_items;
        if (structure[probe].getId() == aluno.getId()) {
            structure[probe] = Aluno(-2, "");
            length--;
            encontrou = true;
            break;
        }
        if (structure[probe].getId() == -1) {
            break;
        }
        i++;
    } while (i < max_items);

    if (encontrou) {
        std::cout << "Aluno com ID = " << aluno.getId() << " foi deletado." << std::endl;
    } else {
        std::cout << "Aluno com ID = " << aluno.getId() << " não encontrado para exclusão." << std::endl;
    }
}
```

## Recuperar um Item da Tabela
```cpp
  void Hash::retriveItemTesteLinear(Aluno &aluno, bool &found) {
    int locInicial = getHash(aluno);
    bool continuarBuscando = true;
    int location = locInicial;
    do {
        if(structure[location].getId() == aluno.getId() || structure[location].getId() == -1) {
            continuarBuscando = false;
        }else
            location = (location + 1) % max_items;

    }while (location != locInicial && continuarBuscando);

    found = (structure[location].getId() == aluno.getId());
    if (found) {
        aluno = structure[location];
    }
}

void Hash::retriveItemTesteQuadratico(Aluno &aluno, bool &found) {
    int locInicial = getHash(aluno); // Localização inicial (hash do aluno)
    bool continuarBuscando = true;
    int location = locInicial;
    int i = 1; // Tentativa de sondagem
    do {
        if (structure[location].getId() == aluno.getId() || structure[location].getId() == -1) {
            continuarBuscando = false;
        } else {
            location = (locInicial + i * i) % max_items; // Sondagem quadrática
            i++; // Incrementa o deslocamento
        }
    } while (location != locInicial && continuarBuscando && i < max_items); // Evita laço infinito

    found = (structure[location].getId() == aluno.getId());
    if (found) {
        aluno = structure[location];
    }
}
```

## Referências

- ROCHA, William. *Introdução à Tabela Hash - Parte 1*. Disponível em: https://www.youtube.com/watch?v=jQ0r7P8rC1M&list=PLxI8Can9yAHex0IsMeE_tzBP0WMYASaQD&index=10.

- ROCHA, William. *Introdução à Tabela Hash - Parte 2*. Disponível em: https://www.youtube.com/watch?v=RmO18m_8ncc&list=PLxI8Can9yAHex0IsMeE_tzBP0WMYASaQD&index=11. 

- ROCHA, William. *Introdução à Tabela Hash - Parte 3*. Disponível em: https://www.youtube.com/watch?v=ujV_NtXXQ_g&list=PLxI8Can9yAHex0IsMeE_tzBP0WMYASaQD&index=12.























