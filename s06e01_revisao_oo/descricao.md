

```bash


# init max_energia
init 500

carregar farinha 100
carregar arroz 200
carregar cuzcuz 1000


# andar 1 metro gasta peso/100 de energia
andar 10
show
jumento 370 [farinha:100][arroz:200][cuzcuz:1000]
andar 1000
fail: andou x metros e parou
show
jumento 0 [farinha:100][arroz:200][cuzcuz:1000]

# aumenta a energia em 1000
#chicotada forca
chicotada 
show
jumento 1000 [farinha:100][arroz:200][cuzcuz:1000]
```


Jumento sergio;
Jumento * ptr = new;
ptr = &sergio;
