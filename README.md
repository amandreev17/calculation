# Калькулятор

## Инфиксные, префиксные и постфиксные выражения

В арифметическом выражении B * C его форма предоставляет достаточно информации для
корректной интерпретации. В данном случае переменная B умножается на переменную C,
поскольку оператор умножения * находится в выражении между ними. Такой тип записи
называется **инфиксной**, поскольку оператор расположен между (in between) двух
операндов, с которыми он работает.

Рассмотрим другой инфиксный пример: A + B * C. Операторы + и * по-прежнему
располагаются между операндами, но появляется проблема. С какими именно операндами
они будут работать? + работает с A и B или * принимает B и C? Выражение выглядит
неоднозначно.

Неоднозначность разрешается за счет того, что каждый оператор имеет свой приоритет.
Операторы с высоким приоритетом используются прежде операторов с низким. Приоритет
можно изменить с помощью скобок. Для арифметических операций умножение и деление
стоят выше сложения и вычитания. Если появляются два оператора одинакового
приоритета, то используются порядок слева направо, или их ассоциативность.

В выражении A + B * C B и C перемножаются первыми, затем к результату добавляется
A. (A + B) * C заставит выполнить сложение A и B перед умножением. В выражении A +
B + C по очерёдности (через ассоциативность) первым будет вычисляться самый левый +.

Это очевидно для человека, но  компьютер нуждается в точном знании того, как и в
какой последовательности вычисляются операторы. Одним из способов записи выражения,
гарантирующим, что не возникнет путаницы по отношению к порядку операций, является
создание того, что называется выражением с полностью расставленными скобками. Такой
тип выражения использует пару скобок для каждого оператора. Скобки диктуют порядок
операций, так что здесь не возникает многозначности. Так же отпадает необходимость
помнить правила расстановки приоритетов.

Выражение A + B * C + D может быть переписано как ((A + (B * C)) + D) с целью
показать, что умножение происходит в первую очередь, а затем следует крайнее левое
сложение. A + B + C + D перепишется в (((A + B) + C) + D), поскольку операции
сложения ассоциируются слева направо.

Существует ещё два очень важных формата выражений, которые на первый взгляд могут
показаться неочевидными. Рассмотрим инфиксную запись A + B. Что произойдёт, если мы 
поместим оператор перед двумя операндами? Результирующее выражение будет + A B.
Также мы можем переместить оператор в конец, получив A B +.

Эти изменения позиции оператора по отношению к операндам создают два новых формата
\- **префиксный и постфиксный**. **Префиксная** запись (иногда ее называют польской
нотацией) выражения требует, чтобы все операторы предшествовали двум операндам, с
которыми они работают. **Постфиксная** (обратная польская нотация или запись), в свою очередь, требует, чтобы операторы шли после соответствующих операндов. Примеры представлены в табл. 1.

**Таблица 1**
|Инфиксная запись|Префиксная запись|Постфиксная запись|
|:-:|:-:|:-:|
|A + B|+ A B|A B +|
|A + B \* C|+ A \* B C|A B C \* +|

A + B * C в префиксной нотации можно переписать как + A * B C. Оператор умножения
ставится непосредственно перед операндами B и C, указывая на приоритет * над +.
Затем следует оператор сложения перед A и результатом умножения.

В постфиксной записи выражение выглядит как A B C * +. Порядок операций вновь
сохраняется, поскольку * находится непосредственно после B и C, обозначая, что он
имеет приоритет выше следующего +. Хотя операторы перемещаются и теперь находятся
до или после соответствующих операндов, порядок последних по отношению друг к другу
остаётся в точности таким, как был.

Рассмотрим инфиксное выражение (A + B) * C. В этом случае запись требует наличия
скобок для указания выполнить сложение перед умножением. Однако, когда A + B
записывается в префиксной форме, то оператор сложения просто помещается перед
операндами: + A B. Результат этой операции является первым операндом для умножения.
Оператор умножения перемещается в начало всего выражения, давая * + A B C.
Аналогично, в постфиксной записи A B + явно указывается, что первым происходит
сложение. Умножение может быть выполнено для получившегося результата и оставшегося
операнда C. Соответствующим постфиксным выражением будет A B + C *.

Эти выражения представлены в табл. 2. В префиксной и постфиксной записи не нужны
скобки. Операторы больше не являются неоднозначными по отношению к своим операндам.
Только инфиксная запись требует дополнительных символов. Порядок операций внутри
префиксного и постфиксного выражений полностью определён позицией операторов и
ничем иным. Во многом именно это делает инфиксную запись наименее желательной
нотацией для использования в компиляторах.

**Таблица 2**
|Инфиксное выражение|Префиксное выражение|Постфиксное выражение|
|:-:|:-:|:-:|
|(A + B)\* C|\* + A B C|A B + C \*|

В табл. 3 представлены некоторые дополнительные примеры инфиксных выражений и
эквивалентных им префиксных и постфиксных записей. 

**Таблица 3**
|Инфиксное выражение|Префиксное выражение|Постфиксное выражение|
|:-:|:-:|:-:|
|A + B \* C + D|+ + A \* B C D|A B C \* + D +|
|(A + B) \* (C + D)|\* + A B + C D|A B + C D + \*|
|A \* B + C \* D|+ \* A B \* C D|A B \* C D \* +|
|A + B + C + D|+ + + A B C D|A B + C + D +|

**Алгоритм Дейкстры перевода из инфиксной формы в постфиксную форму**
1. Если не достигнут конец входной последовательности (очереди), прочитать очередную
лексему. 
* Если прочитан операнд (число), записать его в выходную последовательность (очередь). 
* Если прочитана открывающая скобка, положить ее в стек. 
* Если прочитана закрывающая скобка, вытолкнуть из стека в выходную последовательность (очередь) все до открывающей скобки. Сами скобки уничтожаются. 
* Если прочитан знак операции, вытолкнуть из стека в выходную последовательность (очередь) все операции с большим либо равным приоритетом, а прочитанную операцию положить в стек. 
2. Если достигнут конец входной последовательности (очереди), вытолкнуть все из стека в выходную последовательность (очередь) и завершить работу.

**Алгоритм вычисления значения выражения в постфиксной форме**
1. Если не достигнут конец входной последовательности (очереди), прочитать очередную лексему. 
* Если прочитан операнд (число), положить его в стек. 
* Если прочитан знак операции, вытолкнуть из стека два операнда (для бинарной операции и один для унарной, в качестве унарной операции можно интерпретировать функции с одним параметром: sin, cos, tan, log и т.д.) и положить в стек результат применения прочитанной операции к этим операндам, взятым в обратном порядке. 
2. Если достигнут конец входной последовательности (очереди), завершить работу. В стеке останется единственное число — значение выражения.
