// https://pintia.cn/problem-sets/16/problems/699
List Reverse( List L ){
  if(L -> Next == NULL) return L;
  Position t,p = L -> Next -> Next,k = L -> Next;
  while(p != NULL){
    t = p;
    p = p -> Next;
    k -> Next = p;
    t -> Next = L -> Next;
    L -> Next = t;
  }
  return L;
}