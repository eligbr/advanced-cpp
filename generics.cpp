/// Function templates:

template <typename T>
T add(T a, T b) {
  return a + b;
}

int main() {
  int x = 1, y = 2;
  double a = 1.5, b = 2.5;
  cout << add(x, y) << endl;  // 3
  cout << add(a, b) << endl;  // 4.0
}

/// Class templates:

template <typename T>
class MyStack {
 public:
  void push(T x) {
    data_.push_back(x);
  }
  T pop() {
    T x = data_.back();
    data_.pop_back();
    return x;
  }
 private:
  vector<T> data_;
};

int main() {
  MyStack<int> int_stack;
  int_stack.push(1);
  int_stack.push(2);
  cout << int_stack.pop() << endl;  // 2
  cout << int_stack.pop() << endl;  // 1
}


/// Template specialization:

template <typename T>
class MyClass {
 public:
  void doSomething() {
    // default implementation
  }
};

template <>
class MyClass<int> {
 public:
  void doSomething() {
    // specialized implementation for int
  }
};

int main() {
  MyClass<double> c1;
  c1.doSomething();  // calls the default implementation
  MyClass<int> c2;
  c2.doSomething();  // calls the specialized implementation
}

/// Variadic templates:

template <typename T, typename... Ts>
void print(T x, Ts... xs) {
  cout << x << " ";
  print(xs...);
}

int main() {
  print(1, 2, 3, 4, 5);  // prints "1 2 3 4 5 "
}
