struct Node *nill;

struct Node {
    Node *ch[2];
    int val;
    int sz;

    void up() {
        if (this == nill) return ;
        sz = ch[0]->sz + ch[1]->sz + 1;
    }
};

void split(Node *a,Node *&b,Node *&c,int val) {
    if (a == nill) {
        b = c = nill;
    } else if (a->val <= val) {
        b = a;
        split(a->ch[1],b->ch[1],c,val);
        b->up();
    } else {
        c = a;
        split(a->ch[0],b,c->ch[0],val);
        c->up();
    }
}

unsigned ran() {
    static unsigned ranx = 233233233;
    return ranx += ranx << 2 | 1;
}

bool roll(int a,int b) {
    return ran() % (a+b) < a;
}

void merge(Node *&a,Node *b,Node *c) {
    if (b == nill) {
        a = c;
    } else if (c == nill) {
        a = b;
    } else if (roll(b->sz,c->sz)) {
        a = b;
        merge(a->ch[1],b->ch[1],c);
        a->up();
    } else {
        a = c;
        merge(a->ch[0],b,c->ch[0]);
        a->up();
    }
}
