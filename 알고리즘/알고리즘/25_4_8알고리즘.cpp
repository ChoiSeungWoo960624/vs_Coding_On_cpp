/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void vectorShow(vector<int> v) {
    for (int i = 0; i < v.end() - v.begin(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

int main()
{
    // �� ���� ����
    vector<int> v1;
    vector<int> v2(5, 10);
    vector<int> v3 = { 1,2,3,4,5 };

    cout << "v2.at(2) : " << v2.at(2) << endl;
    cout << "v3[2] : " << v3[2] << endl;

    cout << "v3.front() : " << v3.front() << endl;
    cout << "v3.back() : " << v3.back() << endl;

    for (int i = 0; i < v3.end() - v3.begin(); i++) {
        cout << v3[i] << ", ";
    }
    cout << endl;
    cout << "v3.end() - v3.begin() : " << v3.end() - v3.begin() << endl;
    cout << "v3.begin()�� ������ : " << *(v3.begin() + 1) << endl;

    v3.push_back(6);
    cout << "v3.push_back(6) :";
    vectorShow(v3);

    v3.pop_back();
    cout << "v3.pop_back() :";
    vectorShow(v3);

    v3.insert(v3.begin() + 3, 3);
    cout << "v3.insert(v3.begin() + 3, 3) :";
    vectorShow(v3);

    v3.erase(v3.end() - 2 );
    cout << "v3.erase(v3.end() - 2) :";
    vectorShow(v3);

    vector<int> v4 = {3, 3,1,5,2,4 };
    cout << "v4 :";
    vectorShow(v4);

    reverse(v4.begin(), v4.end());
    cout << "reverse(v4.begin(), v4.end()) :";
    vectorShow(v4);

    sort(v4.begin(), v4.end());
    cout << "sort(v4.begin(), v4.end()) :";
    vectorShow(v4);
    reverse(v4.begin(), v4.end());
    cout << "reverse(v4.begin(), v4.end()) :";
    vectorShow(v4);

    auto it = find(v4.begin(), v4.end(), 3);
    cout << "it - v4.begin() :"<<it - v4.begin() << endl;

    auto count1 = count(v4.begin(), v4.end(), 3);
    cout << "count(v4.begin(), v4.end(), 3) :" << count1 << endl;


    vector<vector<int>> matrix(3, vector<int>(3, 0));
    cout <<"matrix[1][1] :" << matrix[1][1] << endl;
    //{
    //    { 0, 0, 0 },
    //    { 0,0,0 },
    //    { 0,0,0 },
    //}








// �ǽ� 1 ������ ũ��, ���� ���, �ִ밪 ã��, ��� ���� �� �� ����, ����, ����
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int input;

int main() 
{
    
    for (int i = 0; i < 5; ++i) 
    {
        cout << i + 1 << "���� �Է� : ";
        cin >> input;
        v.push_back(input); // push_back �ӽ� ��ü�� ����
    }

    cout << "���� ũ��: " << v.size() << endl; //3

    //4
    cout << "���� ����: ";
    for (int i = 0; i < v.size(); ++i) 
    {
        cout << v[i] << " ";
    }
    cout << endl;

    int max_val = v[0];
    for (int i = 1; i < v.size(); ++i) 
    {
        if (v[i] > max_val) max_val = v[i];
    }
    cout << "���� ū �� : " << max_val << endl;

    for (int i = 0; i < v.size(); ++i) 
    {
        v[i] *= 2; //6 �ι�� 
    }
    cout << "��� ���� �� �� ����: ";

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    int index;
    cout << "������ �ε��� �Է�: ";
    cin >> index;
    if (index >= 0 && index < v.size()) 
    {
        v.erase(v.begin() + index);
    }

    cout << "���� �� ����: ";
    for (int i = 0; i < v.size(); ++i) 
    {
        cout << v[i] << " ";
    }
    cout << endl;

    int in_index, new_value;
    cout << "������ �ε��� �Է�: ";
    cin >> in_index;
    cout << "������ �� �Է�: ";
    cin >> new_value;

    if (in_index >= 0 && in_index <= v.size()) 
    {
        v.insert(v.begin() + in_index, new_value);
    }

    cout << "���� �� ����: ";

    for (int i = 0; i < v.size(); ++i) 
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

 
// �ǽ� 2  2���� ��� �����
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int rows, cols;

    cout << "���� ������ �Է��ϼ���: ";
    cin >> rows;
    cout << "���� ������ �Է��ϼ���: ";
    cin >> cols;

    // 2���� ���� ���� �� �ʱ�ȭ
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // �ʱ�ȭ: (i + 1) * (j + 1)
    for (int i = 0; i < rows; ++i) {
        generate(matrix[i].begin(), matrix[i].end(), [i, j = 0]() mutable {
            return (i + 1) * (++j);
            });
    }

    // ���
    cout << "�ʱ�ȭ�� ���:" << endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }

    return 0;
}

// �ǽ� 3 2���� ��� �����
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;

    cout << "���� ������ �Է��ϼ���: ";
    cin >> rows;

    cout << "���� ������ �Է��ϼ���: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    // ��� ���� �Է� �ޱ�
    cout << "����� ���Ҹ� �Է��ϼ��� (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    // ��� ���
    cout << "\n�Էµ� ���:\n";
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << "\t";
        }
        cout << endl;
    }

    // �� ���� ��
    cout << "\n�� ���� ��:\n";
    for (int i = 0; i < rows; ++i) {
        int row_sum = 0;
        for (int j = 0; j < cols; ++j) {
            row_sum += matrix[i][j];
        }
        cout << i << "��° �� ��: " << row_sum << endl;
    }

    // �� ���� ��
    cout << "\n�� ���� ��:\n";
    for (int j = 0; j < cols; ++j) {
        int col_sum = 0;
        for (int i = 0; i < rows; ++i) {
            col_sum += matrix[i][j];
        }
        cout << j << "��° �� ��: " << col_sum << endl;
    }

    return 0;
}
*/