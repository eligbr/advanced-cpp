/// Using the std::sort algorithm with a custom comparator function:

vector<int> v = {5, 4, 3, 2, 1};

// sort in ascending order
sort(v.begin(), v.end(), [](int x, int y) { return x < y; });

// sort in descending order
sort(v.begin(), v.end(), [](int x, int y) { return x > y; });


/// Using the std::transform algorithm to apply a function to every element in a container:

vector<int> v = {1, 2, 3, 4, 5};

// multiply every element by 2
transform(v.begin(), v.end(), v.begin(), [](int x) { return 2 * x; });

/// Using the std::unique algorithm to remove consecutive duplicates from a container:

vector<int> v = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

// remove consecutive duplicates
auto last = unique(v.begin(), v.end());

// erase the remaining elements
v.erase(last, v.end());


/// Using the std::set_intersection algorithm to compute the intersection of two sorted ranges:

vector<int> v1 = {1, 3, 5, 7, 9};
vector<int> v2 = {2, 3, 5, 7};
vector<int> v3;

// compute the intersection and store it in v3
set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
// v3 is now {3, 5, 7}


/// Using the std::lower_bound algorithm to perform a binary search on a sorted range:

vector<int> v = {1, 2, 3, 4, 5};

auto it = lower_bound(v.begin(), v.end(), 3);
// it points to the element 3

auto it = lower_bound(v.begin(), v.end(), 0);
// it points to the element 1



/////////// Containers examples ////////////

/// Using std::map to create a dictionary with string keys:

map<string, int> m;
m["apple"] = 1;
m["banana"] = 2;
m["cherry"] = 3;

cout << m["apple"] << endl;  // 1
cout << m["orange"] << endl;  // 0 (default value for int)


/// Using std::unordered_map for faster lookup with string keys:

unordered_map<string, int> m;
m["apple"] = 1;
m["banana"] = 2;
m["cherry"] = 3;

cout << m["apple"] << endl;  // 1
cout << m["orange"] << endl;  // 0 (default value for int)


/// Using std::set to store a sorted collection of unique elements:
set<int> s = {3, 2, 1, 3, 4, 4, 5, 5, 5};

// prints "1 2 3 4 5"
for (int x : s) cout << x << " ";


/// Using std::unordered_set for faster insertion and removal:
unordered_set<int> s = {3, 2, 1, 3, 4, 4, 5, 5, 5};

/// Using std::stack to implement a last-in-first-out (LIFO) data structure:

// prints "5 4 3 2 1" (the order may vary)
for (int x : s) cout << x << " ";

stack<int> s;
s.push(1);
s.push(2);
s.push(3);

cout << s.top() << endl;  // 3
s.pop();
cout << s.top() << endl;  // 2
s.pop();
cout << s.top() << endl;  // 1


/// Using std::queue to implement a first-in-first-out (FIFO) data structure:

queue<int> q;
q.push(1);
q.push(2);
q.push(3);

cout << q.front() << endl;  // 1
q.pop();
cout << q.front() << endl;  // 2
q.pop();
cout << q.front() << endl;  // 3