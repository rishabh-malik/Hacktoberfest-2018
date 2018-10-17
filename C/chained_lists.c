#include <stdio.h>
// create structure
struct ValueStr{
    char * title;
    char * content;
};

typedef struct ValueStr valuestr;

struct Maillon{
    int id;
    valuestr value;
    struct Maillon * next;
};

typedef struct Maillon * Encyclopedia;

// function declarations
void *malloc(size_t size);
Encyclopedia create_encyclopedia(void);
Encyclopedia insert(Encyclopedia, int, char *, char *);
void display(Encyclopedia);

int main(){
    Encyclopedia e = create_encyclopedia();
    // insert(e : Encyclopedia, i : int, t : char *, c : char *) : Encyclopedia
    e = insert(e, 1234, "Title of the article", "Content of the article");
    display(e);
    return 0;
}

// create encyclopedia
Encyclopedia create_encyclopedia(){
    return NULL;
}

// insert encylopedia
Encyclopedia insert(Encyclopedia e, int i, char * t, char * c){
    Encyclopedia article = (Encyclopedia)malloc(sizeof(struct Maillon));
    article->id = i;
    article->value.title = t;
    article->value.content = c;
    article->next = e;
    return article;
}
// display encyclopedia
void display(Encyclopedia e){
    while(e != NULL){
        int i = e->id;
        char * t = e->value.title;
        char * c = e->value.content;
        printf("Here is the encyclopedia\nId : %d\nTitle : %s\nContent : %s\n", i, t, c);
        e = e->next;
    }
}
