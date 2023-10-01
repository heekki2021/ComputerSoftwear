#include <initializer_list>

#include <vector>

#include <array>

#include <iostream>

class My_array

{

private:

	unsigned m_length = 0;

	int* m_ptr = nullptr;

public:

	My_array()

	{}

	My_array(const unsigned& length)

	{

		m_length = length;

		m_ptr = new int[m_length];

	}

	My_array(const std::initializer_list<int>& list)

		//:My_array(list.size())

	{ //�����ڸ� ȣ�������ʰ� �����ڿ� �Ȱ��� �ڵ带 ������

		m_length = list.size();

		m_ptr = new int[m_length];

		unsigned i = 0;

		for (const auto& e : list)

		{

			m_ptr[i] = e;

			++i;

		}

	}

};

//���⼭���� ���� �ڵ�

void print(int* ptr);

int main()

{

	//���� �Ҵ��� ������ �����迭�� �����͵��� ����

	int arr[]{ 1,2,3,4,5 };

	const int length_arr = sizeof(arr) / sizeof(arr[0]);

	int* ptr_arr = new int[length_arr];

	unsigned i = 0;

	for (const auto& e : arr)

	{

		ptr_arr[i] = e;

		++i;

	}

	print(ptr_arr);

	//�����Ҵ��� ������ std::array�� �����͵��� ����

	std::array<int, 5> stdArr{ 1, 2, 3, 4, 5, };

	int* ptr_stdArr = new int[stdArr.size()];

	i = 0;

	for (const auto& e : stdArr)

	{

		ptr_stdArr[i] = e;

		++i;

	}

	print(ptr_stdArr);



	//�����Ҵ��� ������ initializer list�� �����͵��� ����

	auto list = { 1,2,3,4,5 };

	int* ptr_list = new int[list.size()];



	i = 0;

	for (const auto& e : list)

	{

		ptr_list[i] = e;

		++i;

	}

	print(ptr_list);

	//���� �Ҵ��� ������ ������ �����͵��� ����

	std::vector<int> my_vec{ 1,2,3,4,5 };

	int* ptr_vec = new int[my_vec.size()];



	i = 0;

	for (const auto& e : my_vec)

	{

		ptr_vec[i] = e;

		++i;

	}

	print(ptr_vec);

	return 0;

}

void print(int* ptr)

{

	for (unsigned i = 0; i < 5; ++i)

	{

		std::cout << ptr[i] << "  ";

	}

	std::cout << std::endl;

}