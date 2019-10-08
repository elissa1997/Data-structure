# include <stdlib.h>
# include <stdlib.h>
# define AtomType char
# define NewSpace (Glist)malloc(sizeof(Glist))

typedef struct GLNode
{
    int tag;
    union
    {
        AtomType atom;
        struct
        {
            struct GLNode *hp,*tp;
        }ptr;
        
    };
    
}*Glist;

Glist initGlist(){
    Glist C = NewSpace;
    C ->tag = 1;

    C -> ptr.hp = NewSpace;
    C -> ptr.hp -> tag = 0;
    C -> ptr.hp -> atom = 'a';

    C -> ptr.tp = NewSpace;
    C -> ptr.tp -> tag = 1;
    C -> ptr.tp -> ptr.hp = NewSpace;
    C -> ptr.tp -> ptr.tp = NULL;

    C -> ptr.tp -> ptr.hp -> tag = 1;
    C -> ptr.tp -> ptr.hp -> ptr.hp = NewSpace;
    C -> ptr.tp -> ptr.hp -> ptr.hp -> tag = 0;
    C -> ptr.tp -> ptr.hp -> ptr.hp -> atom = 'b';
    C -> ptr.tp -> ptr.hp -> ptr.tp = NewSpace;

    C -> ptr.tp -> ptr.hp -> ptr.tp -> tag = 1;
    C -> ptr.tp -> ptr.hp -> ptr.tp -> ptr.hp = NewSpace;
    C -> ptr.tp -> ptr.hp -> ptr.tp -> ptr.hp -> tag = 0;
    C -> ptr.tp -> ptr.hp -> ptr.tp -> ptr.hp -> atom = 'c';
    C -> ptr.tp -> ptr.hp -> ptr.tp -> ptr.hp -> ptr.tp = NewSpace;

    C -> ptr.tp -> ptr.hp -> ptr.tp -> ptr.hp -> tag = 1;
    C -> ptr.tp -> ptr.hp -> ptr.tp -> ptr.hp -> ptr.hp = NewSpace;
    C -> ptr.tp -> ptr.hp -> ptr.tp -> ptr.hp -> ptr.hp -> tag = 0;
    C -> ptr.tp -> ptr.hp -> ptr.tp -> ptr.hp -> ptr.hp -> atom = 'd';
    C -> ptr.tp -> ptr.hp -> ptr.tp -> ptr.hp -> ptr.tp = NULL;

    return C;

}

int glistDepth(Glist C){
    if (!C) {
        return 1;
    }
    if (C->tag==0) {
        return 0;
    }
    int max=0;
    for (Glist pp=C; pp; pp=pp->ptr.tp) {
        int dep=GlistDepth(pp->ptr.hp);
        if (dep>max) {
            max=dep;
        }
    }
    return max+1;
}

int main(){
    int depth = 0;
    Glist C = initGlist();
    depth = glistDepth(C);
    printf("%d",depth);
}