//delegating constructors—the ability of one constructor to invoke
//another within the same class;

class class_c {
public:
    int max;
    int min;
    int middle;

    class_c() {}
    class_c(int my_max) {
        max = my_max > 0 ? my_max : 10;
    }
    class_c(int my_max, int my_min) {
        max = my_max > 0 ? my_max : 10;
        min = my_min > 0 && my_min < max ? my_min : 1;
    }
    class_c(int my_max, int my_min, int my_middle) {
        max = my_max > 0 ? my_max : 10;
        min = my_min > 0 && my_min < max ? my_min : 1;
        middle = my_middle < max&& my_middle > min ? my_middle : 5;
    }
};

//You could reduce the repetitive code by adding a 
//function that does all of the validation, but the code for class_c would be easier to understandand maintain if one constructor could delegate some of the work to another one.To add delegating constructors, use the constructor(. . .) : constructor(. . .) syntax :

class class_c {
public:
    int max;
    int min;
    int middle;

    class_c(int my_max) {
        max = my_max > 0 ? my_max : 10;
    }
    class_c(int my_max, int my_min) : class_c(my_max) {
        min = my_min > 0 && my_min < max ? my_min : 1;
    }
    class_c(int my_max, int my_min, int my_middle) : class_c(my_max, my_min) {
        middle = my_middle < max&& my_middle > min ? my_middle : 5;
    }
};
int main() {

    class_c c1{ 1, 3, 2 };
}