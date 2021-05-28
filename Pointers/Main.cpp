#include <iostream>
#include <list>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


template<typename T>
class smart_ptr
{
public:
	smart_ptr(T* ptr = nullptr) : _ptr{ ptr } {}
	smart_ptr(const smart_ptr&) = delete;
	smart_ptr& operator = (const smart_ptr&) = delete;



	~smart_ptr() { if (_ptr) delete _ptr; }



	T& operator * () { return *_ptr; }
	T* operator & () { return  _ptr; }
	T* operator -> () { return  _ptr; }
	T* get() { return _ptr; }



private:
	T* _ptr{};
};

class ref_count
{
public:
	ref_count() {}
	ref_count(const ref_count&) = delete;
	ref_count& operator = (const ref_count&) = delete;



	size_t inc() { return ++_count; }
	size_t dec() { return --_count; }
	size_t count() { return _count; }



private:
	size_t _count{};
};

template<typename T>
class ref_smart_ptr
{
public:
	ref_smart_ptr(T* ptr) : _ptr{ ptr }, _ref{ new ref_count() } { _ref->inc(); }
	ref_smart_ptr(const ref_smart_ptr& other)
	{
		_ptr = other._ptr;
		_ref = other._ref;
		_ref->inc();
	}
	ref_smart_ptr& operator = (const ref_smart_ptr& other)
	{
		if (this != &other)
		{
			if (_ref->dec() == 0)
			{
				delete _ptr;
				delete _ref;
			}



			_ptr = other._ptr;
			_ref = other._ref;
			_ref->inc();
		}



		return *this;
	}
	~ref_smart_ptr()
	{
		if (_ref->dec() == 0)
		{
			std::cout << "destroyed: " << *_ptr << std::endl;
			delete _ptr;
			delete _ref;
		}
	}



	T& operator *  () { return *_ptr; }
	T* operator &  () { return  _ptr; }
	T* operator -> () { return  _ptr; }
	T* get() { return _ptr; }



	size_t use_count() { return _ref->count(); }



private:
	T* _ptr{};
	ref_count* _ref{};
};

class Employee
{
public:
	Employee(const std::string& name) : _name{ name } {}

	std::string& GetName() { return _name; }

	friend bool operator == (const std::unique_ptr<Employee>& employee, const std::string& name)
	{
		return employee->_name == name;
	}

private:
	std::string _name;
};



int main()
{
	int* p = new int{ 5 };
	std::cout << *p << std::endl;
	delete p;
	p = nullptr;
	if (p) std::cout << *p << std::endl;
	delete p;

	{
		smart_ptr<int> sp{ new int{ 7 } };
		std::cout << *sp << std::endl;

		std::unique_ptr<int> up{ std::make_unique<int>(5) };
		std::cout << *up << std::endl;

	}

	{
		ref_smart_ptr<int> rp{ new int { 10 } };
		std::cout << rp.use_count() << std::endl;
		{
			ref_smart_ptr<int> crp{ rp };
			std::cout << rp.use_count() << std::endl;
		}

		std::cout << rp.use_count() << std::endl;

	}

	{
		std::shared_ptr<int> sp{ new int{ 15 } };
	}

	{
		std::list<std::unique_ptr<Employee>> employees;
		employees.push_back(std::make_unique<Employee>("Tristyn"));
		employees.push_back(std::make_unique<Employee>("Eric"));
		employees.push_back(std::make_unique<Employee>("Zaden"));
		employees.push_back(std::make_unique<Employee>("Bruce"));

		for (auto& employee : employees)
		{
			std::cout << employee->GetName() << std::endl;
		}

		for (auto iter = employees.begin(); iter != employees.end();)
		{
			iter = std::find(iter, employees.end(), "Bruce");
			if (iter != employees.end())

			std::cout << (*iter)->GetName() << std::endl;
			employees.erase(iter);
			//iter++;
		}



		/*for (Employee* employee : employees)
		{
			delete employee;
		}*/
		employees.clear();
	}

	_CrtDumpMemoryLeaks();
}