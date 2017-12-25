#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
struct Node //структура, являющаяся звеном списка
{
    T value;
    int x;     //значение х будет передаваться в список
    Node *Next, *Prev; //указатели на адрес следующего и предыдущего элементов
};


template <class T>
class List {  // создаем класс список

public:
    Node <T> *Head; //указатели на адреса начала списка и его конца
    Node <T> *Tail;
public:
    List(): Head(NULL), Tail(NULL){}; //инициализируем адреса как пустые
    ~List();

    void Add(T value);  //функция добавления элементов в список
    void AddTail (T value);
    void Show(); //функция отображения списка
    void ShowTail();
    void Ins(T value, int x);
};


template <class T>
List<T>::~List<T> ()
{
    Node <T> *temp;
    while (Head) //пока по адресу на начало списка что-то есть
    {
        Tail=Head -> Next; //резервная копия адреса следующего звена списка
        delete Head; //очистка памяти от первого звена
        Head=Tail; //смена адреса начала на адрес следующего элемента
    }
}

template <class T>
void List<T> :: Add(T value) {
    Node <T> *temp=new Node <T>; //выделение памяти под новый элемент структуры
    temp -> Prev=NULL; //указываем, что изначально по следующему адресу пусто
    temp -> value=value; //записываем значение в структуру

    if (Head!=NULL) {  //если список не пуст
        Node <T>  *pwn = Head; //
        while (pwn != NULL){
            (pwn -> x)+=1;
            pwn = pwn->Next;
        }
        temp -> x = ((Head->x)-1);
        temp -> Next = Head;
        temp -> Prev= temp; //указываем адрес предыдущего элемента
        Head = temp; //меняем адрес начала
    }
    else { //если список пустой
        temp -> x = 1;
        temp -> Next=NULL; //следующий элемент указывает в пустоту
        Head=Tail=temp; //меняем адрес хвоста
    }
}

template <class T>
void List<T> :: AddTail(T value) {
    Node <T> *temp=new Node <T>;
    temp -> Next=NULL;
    temp -> value=value;

    if (Head!=NULL) {
        temp -> x = ((Tail->x)+1);
        temp -> Prev = Tail;
        Tail -> Next= temp;
        Tail = temp;
    }
    else {
        temp -> x = 1;
        temp -> Prev=NULL;
        Head=Tail=temp;
    }
}


template <class T>
void List <T>:: Ins (T value, int x) {
    if (x==1) {
        Add(value);
    } else if (x== ((Tail-> x)+1)) {
        AddTail(value);
    } else if (x> ((Tail-> x)+1)) {
        cout << "don't do this" << x << endl;
    } else {
        Node <T> *pwn = Head;
        while ((pwn->x)!=x){
            pwn = pwn-> Next;
        }
        Node <T> *pwnprev= pwn -> Prev;
        Node <T> *temp = new Node <T>;
        temp -> value = value;
        temp -> x=x;

        pwnprev->Next=temp;
        temp -> Prev = pwnprev;
        temp -> Next = pwn;
        pwn -> Prev = temp;
        while (pwn != NULL) {
            (pwn -> x) +=1;
            pwn = pwn -> Next;

        }
    }}
template <class T>
void List <T>::Show() { //выводим список с начала

    Node <T> *temp = Head; //временный указатель на адрес последнего элемента
    while (temp != NULL) { //пока не встретится пустое значение
        cout << temp->x << " " << temp->value << ";"; //выводит каждое считанное значение на экран
        temp = temp->Next; //смена адреса на адрес следующего элемента
    }
    cout << "\n";
}

template <class T>
void List <T>::ShowTail() { //выводим список с конца

    Node <T> *temp = Tail; //временный указатель на адрес последнего элемента
    while (temp != NULL) { //пока не встретится пустое значение
        cout << temp->x << " " << temp->value << ";";
        temp = temp->Prev; //указываем, что нужен адрес предыдущего элемента
    }
    cout << "\n";
}
int main() {

    List<int> lst; //объявляем переменную, тип которой есть список


    lst.AddTail(100); //добавляем в конец списка элементы
    lst.AddTail(200);
    lst.AddTail(0);
    lst.AddTail(1888);



    lst.Add(1);
    lst.Add(2);
    lst.Add(6);
    lst.Add(4338);

    lst.Ins(454,1);
    lst.Ins(4114,7);


    lst.AddTail (423);

    lst.Show(); //отображаем списки на экране
    cout << endl;
    lst.ShowTail();
    return 0;
}