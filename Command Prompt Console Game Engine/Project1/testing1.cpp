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

	{ //생성자를 호출하지않고 생성자와 똑같은 코드를 적어줌

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

//여기서부터 실험 코드

void print(int* ptr);

int main()

{

	//동적 할당을 받은후 정적배열의 데이터들을 복사

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

	//동적할당을 받은후 std::array의 데이터들을 복사

	std::array<int, 5> stdArr{ 1, 2, 3, 4, 5, };

	int* ptr_stdArr = new int[stdArr.size()];

	i = 0;

	for (const auto& e : stdArr)

	{

		ptr_stdArr[i] = e;

		++i;

	}

	print(ptr_stdArr);



	//동적할당을 받은후 initializer list의 데이터들을 복사

	auto list = { 1,2,3,4,5 };

	int* ptr_list = new int[list.size()];



	i = 0;

	for (const auto& e : list)

	{

		ptr_list[i] = e;

		++i;

	}

	print(ptr_list);

	//동적 할당을 받은후 벡터의 데이터들을 복사

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