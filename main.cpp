#include <iostream>
#include<list>

using namespace std;

template<class T>
class List
{

    class node{
        public:
            node* previous = nullptr;
            T data;
            node* next = nullptr;

    }; // end node class.

        private:
            node* head = nullptr;
            node* tail = nullptr;

        public:

            // implementation insert function.
            void Insert(node* current, const T&value) {
                if(current->previous==nullptr)
                {
                    Push_front();
                }
              node* t = new node();
              t->previous = current->previous;
              t->data = value;
              t->next = current;
              current->previous = t;
              t->previous->next = t;

            } //postcondition: insert a new node before the current position.


            // implementation Push_back function.
            void Push_back(const T &value)
            {
                 node* t = new node();
                t->previous = tail;
                t->data = value;

                if (tail== nullptr){

                 head = tail = t;
                }
                else{

                  tail->next = t;
                  tail = t;
                }

            } // postcondition inset one node at the end of linked list.

            // implementation push_front function
            void Push_front(const T& value) {
               node* t = new node();
               t->data = value;
               t->next = head;

               if(head ==nullptr) {
                   head = t;
               }
               else {

                 head->previous = t;

                 head = t;
               }

            } //postcondition: put one node of the beginning of linked list.

            // implementation back function.
            T& Back() {

               return tail->data;
            } // postcondition: return the value at end of linked list.

            //implementation front function.
            T& Front() {

               return head->data;
            } //postcondition: return the first value in liked list

            // implementation erase function.
            void Erase(node* current) {

               if(current->previous == nullptr&&current->next == nullptr) {
                   head = tail = nullptr;
                   delete current;
                   return;
               }
               if(current->previous == nullptr) {

                   current->next->previous = nullptr;
                   head = current->next;
                   delete current;
                   return;
               }
                if(current->next == nullptr) {
                   current->previous->next = nullptr;
                   tail = current->previous;
                   delete current;
                   return;
               }
                current->previous->next = current->next;
                current->next->previous = current->previous;
                delete current;

            } //delete current node form linked list.

            //precondition: linked list has at least one element.
            void Pop_front() {
              Erase(head);
            } // postcondition remove one element at beginning of linked list.


            //precondition: linked list has at least one element.
            void Pop_back() {
              Erase(tail);
            } // postcondition: pop one element at the end of

            // implementation clear function
            void Clear() {
               node*current = head;
               while(current!=nullptr)
               {

                   node*t = current->next;
                   delete current;
                   current = t;
               }
               tail = head = nullptr;
            } // postcondition: remove all element from linked list.

            //implementation Empty function.
            bool Empty() {
              return (head ==nullptr);
            }


}; // end of list class.







int main()
{

   List<int> ls;
   ls.Push_back(5);
   ls.Push_back(10);
   ls.Pop_back();
   ls.Push_front(17);
   ls.Push_back(19);
   ls.Pop_back();
   ls.Push_back(21);
   ls.Push_front(12);


  while(!ls.Empty()) {

    cout <<ls.Front()<<'\n';
    ls.Pop_front();
  }








    return 0;
}
