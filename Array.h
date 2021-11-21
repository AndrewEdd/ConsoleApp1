#include<chrono>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Array
{
public:
	Array(int size);
	~Array();
	int getSize();
	void setSize(int size);
	int& operator[](int index);
	void setRandom(int min, int max);
	void printArray();
	void insertSort();
	void shellSort();

	void merge_sort(int* arr, int leftB, int rightB);
	void merge_sort();
	void merge(int* arr, int begin, int end);

	int* findMaxNumber();
	int* findMinNumber();
	void countingSort();

	void writeFile();
	void readFile();
	void naturalMergeSort();

    int binarySearch(int findNumber,int &index, int left =-1, int right =-1);
    int binaryHuntAndSearch(int huntNumber, int findNumber, int& indexH, int& indexF);

	void resize(int size);
	int* getArr()
	{
		return arr;
	}
	template<class Method>
	double getTime(Array& a, Method method);
private:
	int* arr;
	int size;
};
Array::Array(int size)
{
	this->size = size;
	arr = new int[size];
}
Array::~Array()
{
	delete[] arr;
	arr = nullptr;
	this->size = 0;
}
int Array::getSize()
{
	return this->size;
}
inline void Array::setSize(int size)
{
	delete[] arr;
	arr = nullptr;
	this->size = size;
	arr = new int[size];
}
inline int& Array::operator[](int index)
{
	return arr[index];
}
void Array::setRandom(int min, int max)
{

	for (int i = 0; i < this->size; i++)
	{
		arr[i] = min + rand() % (max - min);
	}
}
inline void Array::printArray()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
	return;
}

inline void Array::insertSort()
{
	if (this->size == 0 || this->size == 1)
	{
		return;
	}
	else
	{
		for (int i = 1; i < this->size; i++)
		{
			for (int j = i; j > 0 && (arr[j - 1] > arr[j]); j--)
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

inline void Array::shellSort()
{
	int n = this->size;
	int i, j, step;
	int temp;
	for (step = n / 2; step > 0; step /= 2)
	{
		for (i = step; i < n; i++)
		{
			temp = arr[i];
			for (j = i; j >= step; j -= step)
			{
				if (temp < arr[j - step])
					arr[j] = arr[j - step];
				else
					break;
			}
			arr[j] = temp;
		}
	}
}

inline void Array::merge_sort(int* arr, int leftB, int rightB)
{
	if (leftB < rightB)

		if (rightB - leftB == 1)
		{
			if (arr[leftB] > arr[rightB])
			{
				swap(arr[leftB], arr[rightB]);
			}
		}

		else
		{
			merge_sort(arr, leftB, leftB + (rightB - leftB) / 2);
			merge_sort(arr, leftB + (rightB - leftB) / 2 + 1, rightB);
			merge(arr, leftB, rightB);
		}


}

inline void Array::merge_sort()
{
	if (this->size > 1)                      //входная точка для метода merge_sort с параметрами
	{
		merge_sort(arr, 0, this->size - 1);
	}
}

inline void Array::merge(int* arr, int begin, int end)
{
	int i = begin, mid = begin + (end - begin) / 2,
		j = mid + 1, k = 0;
	int* d = new int[this->size];

	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
		{
			d[k] = arr[i];
			i++;
		}
		else
		{
			d[k] = arr[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		d[k] = arr[i];
		i++;
		k++;
	}
	while (j <= end)
	{
		d[k] = arr[j];
		j++;
		k++;
	}
	for (i = 0; i < k; i++)
	{
		this->arr[begin + i] = d[i];
	}
	delete[] d;
}

inline int* Array::findMaxNumber()
{
	if (this->size == 0)
	{
		return nullptr;
	}
	if (this->size == 1)
	{
		return this->arr;
	}
	int max = this->arr[0];
	int index = 0;
	for (int i = 1; i < this->size; i++)
	{
		if (this->arr[i] > max)
		{
			max = this->arr[i];
			index = i;
		}
	}
	int* ptrMax = &(this->arr[index]);
	return ptrMax;
}

inline int* Array::findMinNumber()
{
	if (this->size == 0)
	{
		return nullptr;
	}
	if (this->size == 1)
	{
		return this->arr;
	}
	int min = this->arr[0];
	int index = 0;
	for (int i = 1; i < this->size; i++)
	{
		if (this->arr[i] < min)
		{
			min = this->arr[i];
			index = i;
		}
	}
	int* ptrMin = &(this->arr[index]);
	return ptrMin;
}

inline void Array::countingSort()
{
	if (this->size == 0)
	{
		return;
	}
	int size = this->size;
	int maxNumber = *findMaxNumber();
	int minNumber = *findMinNumber();
	int sizeC = 0;
	if (minNumber < 0)
	{
		sizeC = abs(maxNumber - minNumber) + 1;
		int* count = new int[sizeC];
		int* f_count = &count[abs(minNumber)];
		int* temp = new int[this->size];
		for (int i = minNumber; i <= maxNumber; i++)
		{
			f_count[i] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			f_count[this->arr[i]] += 1;
		}
		int idx = 0;
		for (int i = minNumber; i <= maxNumber; i++)
		{
			for (int j = 0; j < f_count[i]; j++)
			{
				temp[idx] = i;
				idx++;
			}
		}
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = temp[i];
		}

	}
	else
	{
		sizeC = maxNumber;
		int* count = new int[maxNumber];
		int* temp = new int[this->size];
		for (int i = 0; i <= maxNumber; i++)
		{
			count[i] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			count[this->arr[i]] += 1;
		}
		int idx = 0;
		for (int i = minNumber; i <= maxNumber; i++)
		{
			for (int j = 0; j < count[i]; j++)
			{
				temp[idx] = i;
				idx++;
			}
		}
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = temp[i];
		}

	}

	//delete[] temp;
}

inline void Array::writeFile()
{
	ofstream outFile("sourceArray.txt");
	if (!outFile)
	{
		cout << "\n sourceArray.txt could not be opened for writing!" << endl;
	}
	for (int i = 0; i < this->size; i++)
	{
		outFile << this->arr[i] << " ";
	}
}

inline void Array::readFile()
{
	ifstream inFile("sourceArray.txt");
	if (!inFile)
	{
		cout << "\n sourceArray.txt could not be opened for writing!" << endl;
	}
	vector<int> read;
	int t;
	while (inFile >> t)
	{
		read.push_back(t);
	}

	this->size = read.size();
	this->arr = new int[this->size];
	for (int i = 0; i < read.size(); i++)
	{
		this->arr[i] = read[i];
	}

}

inline void Array::naturalMergeSort()
{
	//int dataF, dataF1; //два значения для сравнения из sourceArray.txt
	int s1, s2;
	bool flagOfSeries = false; // флаг серии (0 или 1)
	bool sorted = false;
	fstream f, f1, f2;

	string _f_path = "sourceArray.txt";
	string _f1_path = "f1.txt";
	string _f2_path = "f2.txt";

	while (!sorted)
	{
		flagOfSeries = false;
		f.open(_f_path, ifstream::in);
		f1.open(_f1_path, std::ofstream::out | std::ofstream::trunc);
		f2.open(_f2_path, std::ofstream::out | std::ofstream::trunc);



		if (f.peek() != -1)
		{
			f >> s1;
			f1 << s1 << " ";
		}
		while (f >> s2) //чтение поочередно каждого значения из файла sourceArray.txt и формирование серий в f1 и  f2
		{
			//0 = write to f1, 1 = write to f2
			switch (flagOfSeries)
			{
			case false:
			{
				if (s1 <= s2) //пишем серию в f1
				{
					f1 << s2 << " ";
				}
				else if (s1 > s2)
				{
					f1 << "\n";

					f2 << s2 << " ";
					flagOfSeries = true;
				}
				break;
			}
			case true:
			{
				if (s1 <= s2)
				{
					f2 << s2 << " ";
				}
				else if (s1 > s2) {
					f2 << "\n";

					f1 << s2 << " ";
					flagOfSeries = false;
				}
				break;
			}
			}
			s1 = s2;

		}

		f.close();
		f1.close();
		f2.close();



		int b1, b2;
		bool file1 = false, file2 = false;
		string str1, str2;

		f.open(_f_path, std::ofstream::out | std::ofstream::trunc);
		f1.open(_f1_path, ifstream::in);
		f2.open(_f2_path, ifstream::in);

		//если второй файл пуст, то sorted = true;
		if (f2.peek() == -1)
		{
			sorted = true;
			while (f1 >> b1)
			{
				f << b1 << " ";
			}
			break;
		}

		istringstream istream1;
		istringstream istream2;
		while (true)
		{
			string str1, str2;
			getline(f1, str1);
			getline(f2, str2);
			istringstream istream1(str1);
			istringstream istream2(str2);
			// если обе серии имеются
			if (!str1.empty() && !str2.empty())
			{
				istream1 >> b1;
				istream2 >> b2;
				while (true)
				{

					if (b1 <= b2)
					{
						f << b1 << " ";
						istream1 >> b1;
					}
					else
					{
						f << b2 << " ";
						istream2 >> b2;
					}

					if (istream1.eof())
					{
						f << b2 << " ";
						while (istream2 >> b2)
						{
							f << b2 << " ";
						}
						break;
					}
					else if (istream2.eof())
					{
						f << b1 << " ";
						while (istream1 >> b1)
						{
							f << b1 << " ";
						}
						break;
					}

				}
			}
			// остальные случаи
			else if ((!str1.empty() && str2.empty()) || (str1.empty() && !str2.empty()) || (str1.empty() && str2.empty()))
			{
				// если осталась только серия в 1 файле
				if (!str1.empty() && str2.empty())
				{
					while (istream1 >> b1)
					{
						f << b1 << " ";

					}
					break;
				}
				// если осталась только серия в 2 файле
				if ((str1.empty() && !str2.empty()))
				{
					while (istream2 >> b2)
					{
						f << b2 << " ";

					}
					break;
				}
				//если серий не осталось
				if ((str1.empty() && str2.empty()))
				{
					break;
				}
			}

		}

		f1.close();
		f2.close();
		f.close();
	}
	/*
	remove(_f1_path.c_str());
	remove(_f2_path.c_str());
	*/

}

inline int Array::binarySearch(int findNumber,int &index,int left, int right)
{
	this->insertSort();
  if(left == -1 && right == -1)
  {
	left = 0;
	right = this->size-1;
  }
	int middle = (left + right) / 2;
	int search_indx = -1;
	while (left<=right)
	{
		if (this->arr[middle] == findNumber)
		{
			search_indx = middle;
			break;
		}
		if (this->arr[middle] > findNumber)
		{
			right = middle-1;
			middle = (left + right) / 2;
		}
		else
		{
			left = middle+1;
			middle = (left + right) / 2;
		}
	}
	index = search_indx;
	return search_indx;
}

inline int Array::binaryHuntAndSearch(int huntNumber, int findNumber, int& indexH, int& indexF)
{
	indexH = -1;
	int left;
	int right;
	indexH = this->binarySearch(huntNumber,indexH);
	if (indexH == -1)
	{
		left = 0;
		right = this->size;
	}
	else
	{
        left = indexH;
        right = indexH;
	}

	if (this->arr[indexH] < findNumber)
	{
    int i = 1;
		while(this->arr[right] < findNumber)
      {
        i *=2;
        right = right + i;
        if(right > this->size-1)
        {
          right = this->size-1;
          break;
        }
      }
	}
  else
  {
    int i = 1;
		while(this->arr[left] > findNumber)
      {
        i *=2;
        left = left - i;
        if(left <= 0 )
        {
          left = 0;
          break;
        }
      }
  }
 
  this->binarySearch(findNumber,indexF,left,right);
  return indexF;
  
}

inline void Array::resize(int size)
{
	delete[] arr;
	this->size = size;
}

template<class Method>
inline double Array::getTime(Array& a, Method method)
{
	auto time_1 = chrono::high_resolution_clock::now();
	method(a);
	auto time_2 = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(time_2 - time_1).count();

}
