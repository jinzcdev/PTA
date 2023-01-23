// https://pintia.cn/problem-sets/16/problems/696
Deque CreateDeque(){
    PtrToNode header = (PtrToNode)malloc(sizeof(struct Node));
    header -> Next = header -> Last = NULL;
    Deque deque = (Deque)malloc(sizeof(struct DequeRecord));
    deque -> Front = deque -> Rear = header;
    return deque;
}

int Push( ElementType X, Deque D ){
    PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));
    newNode -> Element = X;
    if(D -> Front == D -> Rear){
        D -> Front -> Next = newNode;
        newNode -> Last = D -> Front;
        newNode -> Next = NULL;
        D -> Rear = newNode;
    }else{
        newNode -> Next = D -> Front -> Next;
        D -> Front -> Next -> Last = newNode;
        newNode -> Last = D -> Front;
        D -> Front -> Next = newNode;
    }
    return 1;
}

ElementType Pop( Deque D ){
    if(D -> Front == D -> Rear) return ERROR;
    PtrToNode first = D -> Front -> Next;
    int v;
    if(D -> Front -> Next == D -> Rear){
        D -> Front -> Next = NULL;
        D -> Rear = D -> Front;
    }else{
        D -> Front -> Next = first -> Next;
        first -> Next -> Last = D -> Front;
    }
    v = first -> Element;
    free(first);
    return v;
}

int Inject( ElementType X, Deque D ){
	PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));
	newNode -> Element = X;
	D -> Rear -> Next = newNode;
	newNode -> Last = D -> Rear;
	newNode -> Next = NULL;
	D -> Rear = newNode;
	return 1;
}

ElementType Eject( Deque D ){
	if(D -> Front == D -> Rear) return ERROR;
	PtrToNode end = D -> Rear;
	D -> Rear = end -> Last;
	D -> Rear -> Next = NULL;
	return end -> Element;
}