/// Custom exception types:

class MyException : public std::exception {
 public:
  const char* what() const noexcept override {
    return "Something went wrong";
  }
};

void foo() {
  throw MyException{};
}

int main() {
  try {
    foo();
  } catch (const MyException& e) {
    std::cerr << e.what() << std::endl;
  }
}

/// Rethrowing exceptions:

void foo() {
  try {
    // throw an exception
  } catch (const std::exception& e) {
    std::cerr << "Caught exception in foo: " << e.what() << std::endl;
    throw;  // rethrow the exception
  }
}

int main() {
  try {
    foo();
  } catch (const std::exception& e) {
    std::cerr << "Caught exception in main: " << e.what() << std::endl;
  }
}

/// Exception specifications:

void foo() throw(std::invalid_argument, std::out_of_range);

int main() {
  try {
    foo();
  } catch (const std::invalid_argument& e) {
    // handle invalid argument exception
  } catch (const std::out_of_range& e) {
    // handle out of range exception
  } catch (...) {
    // handle any other exception
  }
}

/// Nested exceptions (C++11):

void foo() {
  try {
    // throw an exception
  } catch (const std::exception& e) {
    std::throw_with_nested(std::runtime_error("Error in foo"));
  }
}

int main() {
  try {
    foo();
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    try {
      std::rethrow_if_nested(e);
    } catch (const std::exception& e) {
      std::cerr << "Nested exception: " << e.what() << std::endl;
    }
  }
}

