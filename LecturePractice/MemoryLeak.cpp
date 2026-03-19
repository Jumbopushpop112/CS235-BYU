//
// Created by matth on 3/4/2026.
//
// MEMORY LEAKY PROGRAM
int main() {
    int* a = new int(5);
    delete a;
    a = nullptr;
}