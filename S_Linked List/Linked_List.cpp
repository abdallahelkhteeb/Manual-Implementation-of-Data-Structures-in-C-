//public:
#include "Linked_List.h"
    void Linked_List::print() {
        for(node *temp = head; temp; temp = temp->next)
            cout << temp->data << ' ';
        cout << "\n";
    };
    void Linked_List::insert_end(int n) {
        node *temp = new node(n);
        if(head == nullptr) { // I made the wrong hear.
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
            temp = nullptr;
            delete temp;
        }
        length++;
    };
    node *Linked_List::get_nth(int n) {
        int i = 0;
        for(node *temp = head; temp; temp = temp->next, i++) {
            if(i == n) 
                return temp;
        }
        return nullptr;
    };
    int Linked_List::search(int n) {
        int i = 0;                                                 //here the increament is important
        for(node *temp = head, *temp2 = nullptr; temp; temp2 = temp,temp = temp->next, i++) {
            if(temp->data == n) {
                swap(temp->data, temp2->data);
                if(!temp2)
                    return 0;   
                return i - 1;
            }
        }
            return -1;
    };

    Linked_List::~Linked_List() {
        
        // for(node *cur = head->next;head; head = cur, cur = head->next) {
        //     delete head;
        //     if(!cur->next) break;
        // }
        while(head) { // o(1) memory, and o(n) time
            node *cur = head->next;
            delete head;
            head = cur;
        }
    }
    void Linked_List::insert_front(int n) {// o(1) memory and o(1) time
        node *temp = new node(n);

        temp->next = head;
        head = temp;
        temp = nullptr;
        if(get_length() == 1)
            head = tail;
        delete temp;
        length++;
    }
    void Linked_List::delete_front() {
        if(head == nullptr)
            return;
        node *temp = head;
        head = temp->next;
        delete temp;
        length--;
    }
    node *Linked_List::get_nth_back(int n) {
        size_t length = get_length();
        if(n > length)
            return nullptr;
        return get_nth(length - n);
    };
    bool Linked_List::is_same(const Linked_List &list) {
        if(length == list.length) {
            node *cur1 = head, *cur2 = list.head;
            for(; cur1; cur1 = cur1->next, cur2 = cur2->next) {
                if(cur1->data != cur2->data)
                    return false;
            }
            return true;
        }
        return false;
    };
    int Linked_List::get_length() {
        int length {0};
        for(node *cur = head; cur; cur=cur->next)
            length++;
        return length;
    }
    bool Linked_List::delete_node(int idx) {
        if(idx > get_length() + 1 || idx < 0)
            return 0;
        if(idx == 0) {
            delete_front();
            return 1;
        } 
        node *prev = get_nth(idx - 1), *cur = prev->next;//modular code
        prev->next = cur->next; 
        bool is_tail = tail == cur;
        if(is_tail)
            tail = prev;
        
        delete cur;

        return 1;
    };
    int Linked_List::get_index(int data) {
        int idx = 0;
        for(node *cur = head ;cur; cur = cur->next, idx++) {
            if(cur->data == data)
                return idx;
        }
        return -1;
    }
    bool Linked_List::delete_key(int value) {
        int idx = get_index(value);
        return (delete_node(idx));
    }
    void Linked_List::swap_two() {
        
        //Idont know when the crach happens.
        for(node *cur = head; cur && cur->next; cur = cur->next->next) {
            swap(cur->data, cur->next->data);
        }
    }
 
    void Linked_List::reverse() {
        tail = head;
        node *prev = nullptr;
        while(head) {
            node *cur = head->next;
            head->next = prev;
            prev = head;
            head = cur;
        }
        head = prev;
    }
    void Linked_List::delete_even() {
        int size = get_length();
        for(int i = 0, j = 0; i < size; i+=2, j++)
            delete_node(j);
    }
    void Linked_List::sort() {
        for(node *cur = head; cur; cur = cur->next) {
            for(node *cur2 = cur->next; cur2; cur2 = cur2->next) {
                if(cur->data > cur2->data)
                    swap(cur->data, cur2->data);
            }
        }
    }
    void Linked_List::embadded(node *n, int value) {
        node *item = new node(value);
        item->next = n->next;
        n->next = item;
    }
    void Linked_List::insert_to_be_sorted(int value) {
        if(!get_length() || value <= head->data)
            insert_front(value);
        else if(value >= tail->data)
            insert_end(value);
        else {
            for(node *cur = head, *prev = nullptr; cur; prev = cur, cur = cur->next) {
                if(cur->data >= value) {
                    embadded(prev, value);
                    break;
                }
            }
        }
        length++;
    }
    void Linked_List::swap_head_tail() {
        if(!head || !head->next)
            return;

        int size = get_length();
        node *t2 = get_nth(size - 2);
        swap(head, tail);
        head->next = tail->next;
        t2->next = tail;
        
        tail->next = nullptr;
    }
    void Linked_List::rotate_left(int k) {
        if(!head || !head->next || get_length() % k == 0)
            return;
        k %= get_length();
        node *temp = get_nth(k - 1);
        tail->next = head;
        tail = temp;
        head = temp->next;
        tail->next = nullptr;
    }//That more efficient code.
    void Linked_List::delete_duplicated() {
        if(get_length() <= 1)
            return;
        int i = 0, j = 0;
        for(node *cur = head; cur; cur = cur->next, ++i) {
            j = i + 1;
            node *next = cur->next;
            while(next) {
                if(next->data == cur->data) {
                    next = next->next;
                    delete_node(j);
                } else {
                    j++;
                    next = next->next;
                }
            }
        }
    } 
    bool Linked_List::remove_last(int value) {
        if(get_length() <= 0)
            return 1;
        int i = 0, idx = -1;
        for(node *cur = head; cur; cur=cur->next, ++i) {
            if(cur->data == value)
                idx = i;
        }
        return (delete_node(idx));
    }
    void Linked_List::move_back(int value) {
        if(get_length() == 0)
            return;
        int size = get_length(), i = 0;     
        for(int i = 0; i < size; ++i) {
            bool ch {false};
            for(node *prev = head, *next = head->next; next; prev = next, next = next->next) {
                if(prev->data == value) {
                    ch = true;
                    swap(prev->data, next->data);
                }
            }
            if(ch == true) size --;
            else break;
        }
    }
    int Linked_List::max(node *head = nullptr, bool is_first = true) {
        if(is_first)
            return this->max(this->head, false);//because we need to initialize it just once.
        if(!head)//It is occur when the last call happens.
            return INT_MIN;// Base case
        return std::max(head->data, this->max(head->next, false));
    }
    void Linked_List::insert_in(const node *n, node *prev) {
        node *temp = new node(n->data);
        temp->next = prev->next;
        prev->next = temp;
        if(prev == tail)
            tail = temp;
        length++;
    }
    void Linked_List::delete_prev(node *prev) {
        node* temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
        length--;
    }
    void Linked_List::arrange_odd_even () {
        int idx = 0;
        for(node *cur = head, *prev2 = nullptr, *prev = head; cur;prev2 = cur,  cur = cur->next, ++idx) {
            if(idx % 2 == 0 && idx != 0) {
                insert_in(cur, prev);
                prev = prev->next;
                delete_prev(prev2);
                cur = prev2;
            }
        }
    }
    void Linked_List::insert_alternate(Linked_List &another) {
        for(node *cur1 = head, *cur2 = another.head; cur2; cur2 = cur2->next) {
            if(!cur1) {
                insert_end(cur2->data);
            } else {
                insert_in(cur2, cur1);
                cur1 = cur1->next->next;
            }
        }
    }
    void Linked_List::add_num(Linked_List &another) {
        int carry {0};
        for(node *cur1 = head, *cur2 = another.head; cur2 || cur1;) {
            if(cur1 && cur2) {
                int sum = cur1->data + cur2->data + carry;
                carry = sum / 10;
                cur1->data = sum % 10;
                cur1 = cur1->next, cur2 = cur2->next;
            } else if(cur2) {
                int sum = cur2->data + carry;
                carry = sum / 10;
                insert_end(sum);
                cur2 = cur2->next;
            } else {
                int sum = cur1->data + carry;
                carry = sum / 10;
                cur1->data = sum % 10;
                cur1 = cur1->next;
            }
        }
        if(carry) insert_end(carry);
    }
    void Linked_List::RemoveDuplicated() {
        bool mark {false}; node *cur = head, *prev = nullptr;
        while(cur) {
            if(cur->next) {
                if(cur->data == cur->next->data) {
                    mark = true;
                    if(!prev) {
                        delete_front();
                        cur = head;
                    } else {
                        delete_prev(prev);
                        cur = prev->next;
                    }
                } else {
                    if(mark) {
                            if(!prev) {
                            delete_front();
                            cur = head;
                        } else {
                            delete_prev(prev);
                            cur = prev->next;
                        }
                    } else {
                        prev = cur;
                        cur = cur->next;
                    }
                    mark = false;
                }
            } else {
                if(mark){
                            if(!prev) {
                            delete_front();
                            cur = head;
                        } else {
                            delete_prev(prev);
                            cur = prev->next;
                        }
                    }
                    break;
            }
            
        }
    }
    void Linked_List::reverse(int k) {
        if(!head || k <= 0 || k > get_length())
            return;
        node *cur = head, *prev = nullptr, *cur2 = head;
        int i = 1;
        bool is_first {true};
        for(node *head2 = head; head2; i++) {
            if(i % k == 0 || !head2->next) {
                 head2 = head2->next;
                while(cur2 != head2->next) {
                    cur2 = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = cur2;   
                }
                if(is_first) 
                head = prev;
            is_first = false;
            head2 = cur2;
            } else
                head2 = head2->next;
        }
    }
  
