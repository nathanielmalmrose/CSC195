#include <iostream>

template <typename TValue>
class set
{
	struct node_t
	{
		node_t(const TValue& value) : _value{ value } {}

		TValue _value;
		node_t* _left{};
		node_t* _right{};

	};

public:
	void insert(const TValue& value)
	{
		node_t* new_node = new node_t{ value };
		if (_root == nullptr)
		{
			_root = new_node;
		}
		else
		{
			node_t* node = _root;
			while (node)
			{
				if (value < node->_value)
				{
					if (node->_left == nullptr)
					{
						node->_left = new_node;
						break;
					}
					node = node->_left;
				}
				else
				{
					if (node->_right == nullptr)
					{
						node->_right = new_node;
						break;
					}
					node = node->_right;
				}
			}
		}
	}

	bool find(const TValue& value)
	{
		node_t* node = _root;
		while (node && node->_value != value)
		{
			node = (value < node->_value) ? node->_left : node->_right;
		}

		return (node != nullptr);
	}
private:
	node_t* _root{ nullptr };
};

template <typename TKey, typename TValue>
class map
{
	struct node_t
	{
		node_t(const TKey& key, const TValue& value) : _key{ key }, _value{ value } {}

		TKey _key;
		TValue _value;
		node_t* _left{};
		node_t* _right{};

	};

public:
	void insert(const TKey& key, const TValue& value)
	{
		node_t* new_node = new node_t{ key, value };
		if (_root == nullptr)
		{
			_root = new_node;
		}
		else
		{
			node_t* node = _root;
			while (node)
			{
				if (key < node->_key)
				{
					if (node->_left == nullptr)
					{
						node->_left = new_node;
						break;
					}
					node = node->_left;
				}
				else
				{
					if (node->_right == nullptr)
					{
						node->_right = new_node;
						break;
					}
					node = node->_right;
				}
			}
		}
	}

	bool find(const TValue& value)
	{
		node_t* node = _root;
		while (node && node->_value != value)
		{
			node = (value < node->_value) ? node->_left : node->_right;
		}

		return (node != nullptr);
	}
private:
	node_t* _root{ nullptr };
};

typedef int id_t;

int main()
{
	set<id_t> ids;
	ids.insert(15);
	ids.insert(10);
	ids.insert(5);
	ids.insert(20);

	std::cout << "find(5): " << ids.find(5) << std::endl;
	std::cout << "find(20): " << ids.find(20) << std::endl;
	std::cout << "find(12): " << ids.find(12) << std::endl;

	map<id_t, std::string> students;
	students.insert(30, "Philip");
	students.insert(20, "William");
	students.insert(35, "Eric");
	students.insert(10, "Alex");

}