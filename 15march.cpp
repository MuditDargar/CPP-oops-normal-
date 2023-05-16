#include <iostream>
#include <set>

using namespace std;

class SetOperation {
private:
    set<int> s1, s2;

public:
    SetOperation(set<int> set1, set<int> set2) {
        s1 = set1;
        s2 = set2;
    }

    set<int> Union() {
        set<int> result = s1;

        for (int i : s2) {
            result.insert(i);
        }

        return result;
    }

    set<int> Intersection() {
        set<int> result;

        for (int i : s1) {
            if (s2.count(i) > 0) {
                result.insert(i);
            }
        }

        return result;
    }
};

int main() {
    set<int> set1 {1, 2, 3, 4};
    set<int> set2 {3, 4, 5, 6};

    SetOperation op(set1, set2);

    cout << "Union: ";
    for (int i : op.Union()) {
        cout << i << " ";
    }

    cout << endl;

    cout << "Intersection: ";
    for (int i : op.Intersection()) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}
