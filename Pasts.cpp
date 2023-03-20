#include <iostream>
#include <fstream>
using namespace std;
int main(){
    fstream fin;
    fstream fin5;
    fstream fout5;
    fin.open("post.in", ios::in);
    fin5.open("post.i5", ios::in);
    fout5.open("post.o5", ios::out);
    
    struct elem{
        string num;
        elem *next;
    };

    class LinkedList{
        public:
        LinkedList(){
            first = NULL;
            last = NULL;
        }

        void insert(string n){
            p = new elem;
            p->num = n;
            p->next = NULL;
            if (first == NULL){
                first = last = p;
            }
            else{
                last->next = p;
                last = last->next;
            }
        }

        void print(){
            fstream fout;
            fout.open("post.out", ios::out | ios::app);
            for(p = first; p!=NULL; p=p->next){
                fout << p->num << " ";
            }
        }

        private:
        elem *first, *last, *p;
    };
    LinkedList* list = new LinkedList[26];
    string text, word;
    getline(fin, text);
    if(text == ""){
        fstream fout;
        fout.open("post.out", ios::out);
        fout << "nothing";
        return 0;
    }
    int end = text.length();
    for(int i=end+1; i>=0; i--){
        if(text[i] == ' '){
            word = text.substr(i+1, end-i-1);
            end = i;
            list[word[0]-97].insert(word);
        }
    }
    word = text.substr(0, end);
    list[word[0]-97].insert(word);

    for(int i=0; i<26; i++){
        list[i].print();
    }
    return 0;
}
