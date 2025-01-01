// https://pintia.cn/problem-sets/434/exam/problems/type/6?problemSetProblemId=6182
Position Find(HashTable H, ElementType Key) {
    for (int i = 0; i < H->TableSize; i++) {
        Position pos = Hash(Key + i, H->TableSize);
        Cell cell = H->Cells[pos];
        if (cell.Info == Legitimate && cell.Data == Key) {
            return pos;
        }
        if (cell.Info == Empty) return pos;
    }
    return ERROR;
}