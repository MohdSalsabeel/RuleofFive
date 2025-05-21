class MyClass {
	int* data;
public:
	MyClass(int value) {
		data = new int(value);
	}

	~MyClass() {
		delete data;
	}

	void show() {
		cout << "Value: " << *data << endl;
	}
};
 
int main() {
	MyClass obj1(10);
	MyClass obj2(obj1); // Default copy constructor (shallow copy)
	obj1.show();
	obj2.show();
}
