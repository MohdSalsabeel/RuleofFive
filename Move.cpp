class MyClass {
	int* data;
public:
	MyClass(int value) {
		data = new int(value);
	}

	// Deep copy
	MyClass(const MyClass& obj) {
		data = new int(*obj.data);
	}

	// Move copy constructor
	MyClass(MyClass&& obj) noexcept {
		data = obj.data;
		obj.data = nullptr;
		cout << "Move constructor " << endl;
		
	}

	// Move assignment operator
	MyClass& operator=(MyClass&& other) noexcept{
		cout << "Move assignment operator " << endl;
		if (this != &other) {
			delete data;
			data = other.data;
			other.data = nullptr;
		}
		return *this;
	}

	// Copy Assignment Operator (Deep Copy)
	MyClass& operator=(const MyClass& other) {
		if (this != &other) {
			delete data;
			data = new int(*other.data);
		}
		return *this;
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
	MyClass obj2(move(obj1)); //  copy constructor 
	//obj1.show();
	obj2.show();

	obj1 = move(obj2);
	obj1.show();
	obj2.show();
	return 0;
}
