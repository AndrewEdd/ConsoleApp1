#include <iostream>
#include "Array.h"
#include <ctime>
#include <chrono>
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int n;
    long int sec_d = 1000000000;
    Array arr = Array(100);
    arr.setRandom(-100, 100);
    //int index = 0;
   // arr.binarySearch(0);
    do
    {
        //  cout << "\n 1.Create array.";
        cout << "\n 1.Get size of array.";
        cout << "\n 2.Set size of array.";
        cout << "\n 3.Fill array random values.";
        cout << "\n 4.Insertion sort.";
        cout << "\n 5.Shell sort.";
        cout << "\n 6.Merge sort.";
        cout << "\n 7.Counting sort.";
        cout << "\n 8.Natural merge sort.";
        cout << "\n 9.Print.";
        cout << "\n _____________________________";
        cout << "\n 10. Binary search";
        cout << "\n 11. Binary hunt and search";
        cout << "\n\n 0.Exit";
        cout << "\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "\nSize is: " << arr.getSize();
            break;
        }
        case 2:
        {
            int size;
            cout << "\nEnter size of array: ";
            cin >> size;
            arr.setSize(size);
            break;
        }
        case 3:
        {
            int min, max;
            cout << "\nEnter min,max values ";
            cin >> min;
            cin >> max;
            arr.setRandom(min, max);
            break;
        }
        case 4:
        {
            cout << "Time: " << arr.getTime(arr, [](Array& arr) {return arr.insertSort(); }) / sec_d << " sec" << endl;
            break;
        }
        case 5:
        {
            cout << "Time: " << arr.getTime(arr, [](Array& arr) {return arr.shellSort(); }) / sec_d << " sec" << endl;
            break;
        }
        case 6:
        {
            cout << "Time: " << arr.getTime(arr, [](Array& arr) {return arr.merge_sort(); }) / sec_d << " sec" << endl;
            break;
        }
        case 7:
        {
            cout << "Time: " << arr.getTime(arr, [](Array& arr) {return arr.countingSort(); }) / sec_d << " sec" << endl;
            break;
        }
        case 8:
        {
            int i = 0; 
            cout << "      1.Read array from file." << endl;
            cout << "      2.Use current array." << endl;
            cin >> i;
            switch (i)
            {
            case 1:
            {
                arr.readFile();
                cout << "Time: " << arr.getTime(arr, [](Array& arr) { return arr.naturalMergeSort(); }) / sec_d << " sec" << endl;
                arr.readFile();
                break;
            }
            case 2:
            {
                arr.writeFile();
                cout << "Time: " << arr.getTime(arr, [](Array& arr) { return arr.naturalMergeSort(); }) / sec_d << " sec" << endl;
                arr.readFile();
                break;
            }
            }
        break;
        } 
        case 9:
        {
            arr.printArray();
            cout << endl;
            break;
        }
        case 10:
        {
            int i = 0;
            int index;
            cout << "      1.Enter new array." << endl;
            cout << "      2.Use current array." << endl;
            cin >> i;
            switch (i)
            {
            case 1:
            {
                cout << "Enter array : \n";
                string str;
                cin.ignore(); 
                getline(cin, str);
                istringstream istream(str);
                int temp;
                vector<int> vtemp(0);
                while (istream >> temp)
                {
                    vtemp.push_back(temp);
                }
                arr.resize(vtemp.size());
                for (int i = 0; i < arr.getSize(); i++)
                {
                    arr[i] = vtemp[i];
                }
                cout << "The array has been sorted!\n";
                cout << "Enter search number : \n";
                int findNumber;
                cin >> findNumber;
                cout << "Time: " << arr.getTime(arr, [findNumber,&index](Array& arr) { return arr.binarySearch(findNumber,index); }) / sec_d << " sec" << endl;
                if (index == -1)
                {
                    cout << "Number not found!\n";
                }
                else
                {
                    cout << "The number is at " << index << " position.\n";
                }
                index = -1;
                break;
            }
            case 2:
            {
                cout << "The array has been sorted!\n";

                cout << "Enter search number : \n";
                int findNumber;
                cin >> findNumber;
                cout << "Time: " << arr.getTime(arr, [findNumber, &index](Array& arr) { return arr.binarySearch(findNumber, index); }) / sec_d << " sec" << endl;
                if (index == -1)
                {
                    cout << "Number not found!\n";
                }
                else
                {
                    cout << "The number is at " << index << " position.\n";
                }
                index = -1;
                break;
            }
            }
            break;
        }

        case 11:
        {
            int i = 0;
            int indexH = -1; //индекс первого числа
            int indexF = -1; //индекс второго числа
            int huntNumber;
            int findNumber;
            cout << "      1.Enter new array." << endl;
            cout << "      2.Use current array." << endl;
            cin >> i;
            switch (i)
            {
            case 1:
            {
                cout << "Enter array : \n";
                string str;
                cin.ignore();
                getline(cin, str);
                istringstream istream(str);
                int temp;
                vector<int> vtemp(0);
                while (istream >> temp)
                {
                    vtemp.push_back(temp);
                }
                arr.resize(vtemp.size());
                for (int i = 0; i < arr.getSize(); i++)
                {
                    arr[i] = vtemp[i];
                }
                cout << "The array has been sorted!\n";
                cout << "Enter 2 number for search: \n";
                cin >> huntNumber;
                cin >> findNumber;
                cout << "Time: " << arr.getTime(arr, [huntNumber, findNumber, &indexH, &indexF](Array& arr) { return arr.binaryHuntAndSearch(huntNumber, findNumber, indexH, indexF); }) / sec_d << " sec" << endl;
                
                if (indexH == -1)
                {
                    cout << "Number: " << huntNumber << " not found!\n";
                    
                }
                else
                {
                    cout << "The number: "<<huntNumber<<" is at " << indexH << " position.\n";
                }

                if (indexF == -1)
                {
                    cout << "Number: " << findNumber << " not found!\n";

                }
                else
                {
                    cout << "The number: " << findNumber << " is at " << indexF << " position.\n";
                }
                break;
            }
            case 2:
            {
                cout << "The array has been sorted!\n";
                cout << "Enter 2 number for search: \n";
                cin >> huntNumber;
                cin >> findNumber;
                cout << "Time: " << arr.getTime(arr, [huntNumber, findNumber, &indexH, &indexF](Array& arr) { return arr.binaryHuntAndSearch(huntNumber, findNumber, indexH, indexF); }) / sec_d << " sec" << endl;
                
                if (indexH == -1)
                {
                    cout << "Number: " << huntNumber << " not found!\n";

                }
                else
                {
                    cout << "The number: " << huntNumber << " is at " << indexH << " position.\n";
                }

                if (indexF == -1)
                {
                    cout << "Number: " << findNumber << " not found!\n";

                }
                else
                {
                    cout << "The number: " << findNumber << " is at " << indexF << " position.\n";
                }
                break;
            }
            }
            break;
        }
        }

    } while (n != 0);

    system("pause");
}
