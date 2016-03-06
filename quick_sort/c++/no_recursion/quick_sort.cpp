#include <stack>
using namespace std;

int handle(int* a, int size) {
    if (a == NULL || size <= 1) {
        return 0;
    }

    int key = 0;
    int last = size - 1;
    for (int i = 1; i <= last;) {
        if (a[i] < a[key]) {
            int t = a[key];
            a[key] = a[i];
            a[i] = t;
            key = i;
            i++;
        }
        else {
            int t = a[i];
            a[i] = a[last];
            a[last] = t;
            last--;
        }
    }

    return key;
}

struct Pair {
    int begin;
    int length;
};

void quickSort(int* a, int size) {
    if (size <= 1) {
        return;
    }

    int begin = 0;
    int length = size;
    stack<Pair> s;
    do {
        while (length > 1) {
            int c = handle(a + begin, length);
            Pair p = { begin + c + 1, length - c - 1 };
            s.push(p);
            length = c;
        }
        if (!s.empty()) {
            Pair p = s.top();
            s.pop();
            if (p.length > 1) {
                int c = handle(a + p.begin, p.length);
                begin = p.begin;
                length = c;

                Pair p1 = { p.begin + c + 1, p.length - c - 1 };
                s.push(p1);
            }
        }
    } while (!s.empty());
}