#include <iostream>
#include <sstream>
#include <stack>
#include <list>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

struct Leksema // Лексема - Неделимый элемент выражения (формулы)
{
    char type; // '(' ')' '+' '-' '*' '/'  0 - число
    double val; // Значение число
};
char addType(string& f) { // определяем, как в стеке будут храниться функции
    if (f == "sin") {
        f = "";
        return 's';
    }
    if (f == "cos") {
        f = "";
        return 'c';
    }
    if (f == "tg") {
        f = "";
        return 't';
    }
    if (f == "ctg") {
        f = "";
        return 'g';
    }
    if (f == "exp") {
        f = "";
        return 'e';
    }
    return 'E';
}

int getRang(char Ch) // Приоритет операции
{
    if (Ch == '*' || Ch == '/') return 2;
    if (Ch == '+' || Ch == '-') return 1;
    else return 0;
}

stack <Leksema> mystack; // Стек
list <Leksema> myqueue; // Очередь

double Func(list<Leksema>& q, stack<Leksema>& s) {  // вычисляем значения функций
    if (q.front().type == 'c') {
        return cos(s.top().val);
    }
    if (q.front().type == 's') {
        return sin(s.top().val);
    }
    if (q.front().type == 't') {
        return tan(s.top().val);
    }
    if (q.front().type == 'e') {
        return exp(s.top().val);
    }
    if (q.front().type == 'g') {
        return 1.0/(tan(s.top().val));
    }
    return -1.0;
}

bool CheckStaples(string f) {
    int count_right = 0;
    int count_left = 0;
    for(char st: f) {
        if (st == '(') count_right += 1;
        else if (st == ')') count_left += 1;
    }
    return count_left == count_right;
}
