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
    // 빈 벡터 선언
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
    cout << "v3.begin()의 역참조 : " << *(v3.begin() + 1) << endl;

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








// 실습 1 벡터의 크기, 원소 출력, 최대값 찾기, 모든 원소 두 배 적용, 삭제, 삽입
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
        cout << i + 1 << "정수 입력 : ";
        cin >> input;
        v.push_back(input); // push_back 임시 객체를 생성
    }

    cout << "벡터 크기: " << v.size() << endl; //3

    //4
    cout << "벡터 원소: ";
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
    cout << "가장 큰 값 : " << max_val << endl;

    for (int i = 0; i < v.size(); ++i) 
    {
        v[i] *= 2; //6 두배로 
    }
    cout << "모든 원소 두 배 적용: ";

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    int index;
    cout << "삭제할 인덱스 입력: ";
    cin >> index;
    if (index >= 0 && index < v.size()) 
    {
        v.erase(v.begin() + index);
    }

    cout << "삭제 후 벡터: ";
    for (int i = 0; i < v.size(); ++i) 
    {
        cout << v[i] << " ";
    }
    cout << endl;

    int in_index, new_value;
    cout << "삽입할 인덱스 입력: ";
    cin >> in_index;
    cout << "삽입할 값 입력: ";
    cin >> new_value;

    if (in_index >= 0 && in_index <= v.size()) 
    {
        v.insert(v.begin() + in_index, new_value);
    }

    cout << "삽입 후 벡터: ";

    for (int i = 0; i < v.size(); ++i) 
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

 
// 실습 2  2차원 행렬 만들기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int rows, cols;

    cout << "행의 개수를 입력하세요: ";
    cin >> rows;
    cout << "열의 개수를 입력하세요: ";
    cin >> cols;

    // 2차원 벡터 선언 및 초기화
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // 초기화: (i + 1) * (j + 1)
    for (int i = 0; i < rows; ++i) {
        generate(matrix[i].begin(), matrix[i].end(), [i, j = 0]() mutable {
            return (i + 1) * (++j);
            });
    }

    // 출력
    cout << "초기화된 행렬:" << endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }

    return 0;
}

// 실습 3 2차원 행렬 만들기
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;

    cout << "행의 개수를 입력하세요: ";
    cin >> rows;

    cout << "열의 개수를 입력하세요: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    // 행렬 원소 입력 받기
    cout << "행렬의 원소를 입력하세요 (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    // 행렬 출력
    cout << "\n입력된 행렬:\n";
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << "\t";
        }
        cout << endl;
    }

    // 각 행의 합
    cout << "\n각 행의 합:\n";
    for (int i = 0; i < rows; ++i) {
        int row_sum = 0;
        for (int j = 0; j < cols; ++j) {
            row_sum += matrix[i][j];
        }
        cout << i << "번째 행 합: " << row_sum << endl;
    }

    // 각 열의 합
    cout << "\n각 열의 합:\n";
    for (int j = 0; j < cols; ++j) {
        int col_sum = 0;
        for (int i = 0; i < rows; ++i) {
            col_sum += matrix[i][j];
        }
        cout << j << "번째 열 합: " << col_sum << endl;
    }

    return 0;
}
*/