#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Pet {
  private:
    string name;
    int weight, lifespan;
  public:
    Pet() {
        lifespan = 12;
        name = "";
        weight = 0;
    }

    Pet(string nm, int w) {
        name = nm, lifespan = 12, weight = w;
    }

    void adjust_life (int w, string type) {
        if (type == "husky") {
            lifespan += (w > 50 ? -2 : 3);
        }
        else if (type == "corgi") {
            lifespan += (w > 30 ? -1 : 1);
        }
        else if (type == "cat") {
            lifespan += (w > 20 ? -2 : 3);
        }
    }       

    string get_name() {
        return name;
    }
    int get_weight() {
        return weight;
    }
    int get_life() {
        return lifespan;
    }
};

class Dog : public Pet {
  private:
    string breed;
  public:
    Dog() : Pet() {
        breed = "";
    }

    Dog (string nm, int w, string b): Pet (nm, w) {
        breed = b;
        adjust_life (w, b);
    }

    friend ostream& operator<<(ostream& output, Dog data);
};

class Cat : public Pet {
  private:
    string color;
    int cuteness;
  public:
    Cat() : Pet() {
        color = "";
        cuteness = 0;
    }

    Cat (string nm, int w, string c): Pet (nm, w) {
        color = c;
        adjust_life (w, "cat");
        if (c == "orange") cuteness = 100-w;
        else if (c == "tabby") cuteness = 90-w;
        else cuteness = 70-w;
    }

    friend ostream& operator<<(ostream& output, Cat data);
};

ostream& operator<<(ostream& output, Dog data) {
    output << data.get_name() << ' ' << data.breed << ' ' << data.get_life();
    return output;
}

ostream& operator<<(ostream& output, Cat data) {
    output << data.get_name() << ' ' << data.color << ' '
           << data.get_life() << ' ' << data.cuteness;
    return output;
}

int main(int argc, char *argv[]) {
    ifstream input;
    input.open(argv[1]);

    int num;
    input >> num;

    Dog *temp_dog;
    Cat *temp_cat;
    vector<Dog> dog;
    vector<Cat> cat;

    string name, det;
    int weight;
    for (int i = 0; i < num; i++) {
        input >> name >> weight >> det;
        if (det == "husky") {
            temp_dog = new Dog (name, weight, det);
            dog.push_back (*temp_dog);
        }
        else if (det == "corgi") {
            temp_dog = new Dog (name, weight, det);
            dog.push_back (*temp_dog);
        }
        else if (det == "orange") {
            temp_cat = new Cat (name, weight, det);
            cat.push_back (*temp_cat);
        }
        else if (det == "tabby") {
            temp_cat = new Cat (name, weight, det);
            cat.push_back (*temp_cat);
        }
        else {
            temp_cat = new Cat (name, weight, det);
            cat.push_back (*temp_cat);
        }
    }

    for (size_t i = 0; i < dog.size(); i++) {
        cout << dog[i] << '\n';
    }
    cout << '\n';

    for (size_t i = 0; i < cat.size(); i++) {
        cout << cat[i] << '\n';
    }

    return 0;
}
