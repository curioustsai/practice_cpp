#include <iostream>
#include <queue>
#include <string>

enum AnimalType { none, dog, cat };
class AnimalShelter {
public:
    int dequeue(AnimalType t) {
        if (t == dog) {
            int order = dogQue.front();
            dogQue.pop();
            return order;
        } else if (t == cat) {
            int order = catQue.front();
            catQue.pop();
            return order;
        } else {
            int order = -1;
            if (dogQue.front() < catQue.front()) {
                order = dogQue.front();
                dogQue.pop();
            } else {
                order = catQue.front();
                catQue.pop();
            }
            return order;
        }
    }
    void enque(int order, AnimalType t) {
        if (t == dog) dogQue.push(order);
        if (t == cat) catQue.push(order);
    }

private:
    std::queue<int> dogQue;
    std::queue<int> catQue;
};

int main(void) {
    AnimalShelter s;
    AnimalType animals[] = {dog, cat, dog, dog, cat};

    for (int i = 0; i < sizeof(animals) / sizeof(animals[0]); i++) {
        // std::cout << animals[i] << std::endl;
        s.enque(i, animals[i]);
    }

    s.dequeue(cat);
    s.dequeue(dog);
    s.dequeue(none);

    return 0;
}
