# Sobre o Projeto

Realizar um alinhamento de DNA, nessa primeria parte iremos receber duas fitas de dna e na segunte parte receberemos 50 fitas de dna. 


### Primeiro caso de Entrada

    Quando não existem espaços na fita e ambas tem o mesmo tamanho

Dado duas fitas

 - agtcaatcgga
 - aggtaatccat

Em seguida iremos realizar a soma dos pessos (Alpha, Beta e Gama)

    // Alpha(Se as bases forem iguas, +1)
    // Beta (Se as bases forem diferentes, 0);
    // Gama (Se existe um gap "-" e uma base nirogenada, -1)
    // Ao final soma alpha + beta + gama;


### Como é feito a soma dos pessos ?
    Comparamos as bases de pares um a um 
    da primeira fita com a segunda fita

    primeite fita : agtcaatcgga
    segunda  fita : aggtaatccat

    primeiro par:  a/a (então alpha recebe 1 ponto)
    segundo  par:  g/g (alfa recebe mais 1 ponto)
    terceito par:  t/g (são diferentes, porém beta não tem pontuação)

    nessa situação "gama" não foi utilizado, pois não existe "gaps" nas fitas 

### Segundo caso de Entrada

    Quando existe espaço na fita, como também não são do mesmo tamanho

Dado duas fitas
- gg-ta atctaagg
- gt-aatga

##  
    Primeiro retiramos os espaços e colocamos traços '-'

    gg-ta atctaagg   // fita com espaço  
    gt-aatga        //  fita sem espaço e com tracinho

    Logo após (alinhamos) compensamos com traços '-' a fita menor para ficar com o mesmo tamanho da maior fita

    -gg-taatctaagg
    ------gt-aatga

    Feito isso realizamos a soma dos pesos

    ps: Os taços sempre serão colocados no inicio 
    
### Documentação do código

[acesse a estrutura mais detalhada do projeto](https://github.com/Ericoalb/estrutura_dna/blob/main/doc.md)