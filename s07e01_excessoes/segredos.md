```bash
#__begin__
$addUser david 1717

$addUser david papagaio

fail: id ja existe
$login david 50
fail: senha invalida
$login david 1717
$logout
$logout
fail: ninguem logado
$addUser bia 51
$login bia 51
$showUsers
bia
david
$changePass 52 90
fail: senha invalida
$changePass 51 90
$setSegredo 15 gosto de roer a unha do pe
fail: nivel invalido
$setSegredo 7 gosto de roer a unha do pe
$show
bia: [gosto de roer a unha do pe] 7
$logout
$login david 1717
$setSegredo 1 nao gosto do lula
$logout
$login admin admin
$showall
bia [gosto de roer a unha do pe] 7
david [nao gosto do lula] 1
admin [] 0
$logout
$show
fail: ninguem logado
$end
#__end__
``` 

