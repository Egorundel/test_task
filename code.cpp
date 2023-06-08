#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Здесь Types — идентификатор класса:
enum class Types {
    car, 
    pedestrian, 
    sign, 
    trafficlight
};


//Имеется база прямоугольников, представленная вектором структур boundingBox:
struct BoundingBox {
    map <Types, double> classConf;
    pair <int, int> point1;
    pair <int, int> point2;
};

bool operator<(const BoundingBox &lhs, const BoundingBox &rhs) {
    return tie(lhs.classConf, lhs.point1, lhs.point2) < tie(rhs.classConf, rhs.point1, rhs.point2);
}
/*
Напишите функцию FindMaxRepetitionCount, принимающую базу прямоугольников и определяющую, 
какое максимальное количество повторов (число вхождений одного и того же элемента) она содержит. 
Используйте самый быстрый по-времени работы алгоритм. 
Две записи (объекты типа BoundingBox) считаются различными, если они отличаются хотя бы одним полем.
*/
int FindMaxRepetitionCount(const vector<BoundingBox> &boundingBoxes) {
    int res = 0;

    map <BoundingBox, int> number_of_repeat;

    for (int i = 0; i < boundingBoxes.size(); i++) {
        res = max(res, ++number_of_repeat[boundingBoxes[i]]);
    }
    return res;
}
/*
Если все записи уникальны, считайте максимальное количество повторов равным 1.
Если записи отсутствуют, верните 0. Гарантируется, что типа int достаточно для хранения ответа.
*/

int main() {
    cout << FindMaxRepetitionCount({
        {
            {
                {Types::car, 0.97}, 
                {Types::pedestrian, 0.86},
                {Types::sign, 0.52},
                {Types::trafficlight, 0.16}
            },
            {13,42}, 
            {16,88}
        }, {
            {
                {Types::car, 0.93}, 
                {Types::pedestrian, 0.54},
                {Types::sign, 0.1},
                {Types::trafficlight, 0.06}
            },
            {12,32},
            {14,48}
        }, {
            {
                {Types::car, 0.93},
                {Types::pedestrian, 0.54},
                {Types::sign, 0.1}, 
                {Types::trafficlight, 0.06}
            },
            {12,32},
            {14,48}
        }
        }) << endl;
    return 0;
}
