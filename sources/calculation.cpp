#include <header.h>

int main()
{
    string f; // собираем функцию
    string formula; // храним здесь выражение
    char Ch;
    double x, x1;
    int count = 0; // флаг для х
    int fl = 1; // Флаг используется, чтобы отличить унарный минус от бинарной операции -
    int flag = 0; // Флаг для тригонометрический операций
    cout << "Formula: ";// Формулу вводим с клавитатуры
    getline(cin, formula, '\n');
    if (!CheckStaples(formula)) {
        cerr << "\nError!!";
        return 0;
    }
    stringstream str(formula);
    Leksema item;
    for (size_t i = 0; i < formula.size(); ++i)
    {
        Ch = str.peek();
        if (Ch == 'x' && f == "") {
            item.type = 0;
            if (!count) {
                cout << "Enter x: "; cin >> x1;
                count = 1;
            }
            item.val = x1;
            myqueue.push_back(item);
            fl = 0;
        }
        if ((Ch == '-' && fl) || Ch == '.' || (Ch >= '0' && Ch <= '9')) // Унарный минус или число
        {
            str >> x; // Читаем число
            item.type = 0; // Тип лексемы - число
            item.val = x;
            myqueue.push_back(item); // Число в очередь
            fl = 0; // Для отличия унарного - от бинарного -
            continue;
        }
        if (Ch == '-' || Ch == '+' || Ch == '*' || Ch == '/') // Знак операции
        {
            while (1) // вытолкнуть из стека в выходную последовательность (очередь) все операции с большим либо равным приоритетом
            {
                int rang = 0;
                if (mystack.size() > 0) rang = getRang(mystack.top().type);
                if (rang < getRang(Ch) || mystack.size() == 0)
                {
                    item.type = Ch;
                    mystack.push(item); // Операцию отправляем в стек
                    break;
                }
                // Отправляем в очередь все операции с большим или равным приоритетом
                myqueue.push_back(mystack.top());
                mystack.pop(); // Удаляем операцию из стека
                
            }
            fl = 1;
            
        }
        if ((isalnum((unsigned char)Ch) && Ch != 'x') || (isalnum((unsigned char)Ch) && Ch == 'x' && f != "")) {
            f += Ch;
        }
        if (f == "cos" || f == "sin" || f == "tg" || f == "ctg" || f == "exp") {
            flag = 1;
        }
        if (Ch == '(') // Помещаем в стек
        {
            item.type = Ch;
            mystack.push(item);
            if (flag) {
                item.type = addType(f);
                mystack.push(item);
                flag = 0;
            }
        }
        if (Ch == ')') //вытолкнуть из стека в выходную последовательность(очередь) все до открывающей скобки.Сами скобки уничтожаются
        {
            if (!myqueue.size()) {
                cerr << "\nError!!!";
                return 0;
            }
            while (mystack.top().type != '(') {
                myqueue.push_back(mystack.top());
                mystack.pop();
            }
            mystack.pop();
        }
        str.get(); // Читаем символ из потока
    }
    if (f != "") {
        cerr << "\nError!!!";
        return 0;
    }
    // 2.    Если достигнут конец входной последовательности (очереди), вытолкнуть все из стека в выходную последовательность (очередь) и завершить работу.
    while (mystack.size() > 0)
    {
        myqueue.push_back(mystack.top());
        mystack.pop();
    }
    // Печать выражения в постфиксной форме
    for (list <Leksema>::iterator pos = myqueue.begin(); pos != myqueue.end(); ++pos)
        if (pos->type) cout << pos->type << ' '; else cout << pos->val << ' ';
    // Алгоритм вычисления значения выражения в постфиксной форме
    while (myqueue.size() > 0) // 1.    Если не достигнут конец входной последовательности (очереди), прочитать очередную лексему
    {
        if (myqueue.front().type == 0) // Операнд число
        {
            mystack.push(myqueue.front());
            myqueue.pop_front(); // Удалить из очереди
        }
        else if (myqueue.front().type == 'c' || myqueue.front().type == 's' || myqueue.front().type == 't'
                 || myqueue.front().type == 'g' || myqueue.front().type == 'e') {
            item.type = 0;
            item.val = Func(myqueue, mystack);
            myqueue.pop_front();
            mystack.pop();
            mystack.push(item);
        }
        else // Операнд знак операции
        {
            // Если операция бинарная, то в стеке должно быть 2 числа, если операция унарная, то в стеке 1 число
            double x, y, Rez;
            if (mystack.size() == 0) // Стек пуст (ошибка)
            {
                cerr << "\nError!!!";
                return 0;
            }
            if (mystack.top().type) // Операнд в стеке не число
            {
                cerr << "\nError!!!";
                return 0;
            }
            y = mystack.top().val; // Операнд из стека (это 2-ой операнд)
            // вытолкнуть из стека два операнда и положить в стек результат применения прочитанной операции к этим операндам, взятым в обратном порядке
            mystack.pop(); // Удалить операнд из стека
            if (mystack.size() == 0) // Стек пуст (ошибка)
            {
                cerr << "\nError!!!";
                return 0;
            }
            if (mystack.top().type) // Операнд в стеке не число
            {
                cerr << "\nError!!!";
                return 0;
            }
            x = mystack.top().val;  // Операнд из стека (это 1-ый операнд)
            mystack.pop(); // Удалить операнд из стека
            switch (myqueue.front().type) // Выполняем операцию
            {
                case '+': Rez = x + y; break;
                case '-': Rez = x - y; break;
                case '*': Rez = x * y; break;
                case '/': Rez = x / y; break;
                default:
                    cerr << "\nError!!!";
                    return 0;
            }
            myqueue.pop_front(); // Извлечь операнд из очереди  (знак операции, которую выполнили)
            item.type = 0;
            item.val = Rez; // Результат в новую лексему
            mystack.push(item); // Результат в стек
            
        }
    }
    // В стеке останется единственное число — значение выражения
    if (isinf(mystack.top().val)) {
        cerr << "\nError!!!";
        return 0;
    }
    cout << "\nresult = " << mystack.top().val << endl;
    return 0;
}
