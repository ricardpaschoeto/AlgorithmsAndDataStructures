#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>

using std::vector;

int get_change(int m) {
    int ch = m;
    int count = 0;
    while (ch)
    {
        if (ch >= 10)
        {
            ch -= 10;
            count++;
        }
        else if (ch >= 5)
        {
            ch -= 5;
            count++;
        }
        else
        {
            ch -= 1;
            count++;
        }
    }

  return count;
}

void test_get_change()
{
    assert(get_change(28) == 6);
    assert(get_change(30) == 3);
    assert(get_change(25) == 3);
    assert(get_change(1) == 1);
    assert(get_change(2) == 2);
    assert(get_change(3) == 3);
    assert(get_change(4) == 4);
    assert(get_change(5) == 1);
    assert(get_change(6) == 2);
    assert(get_change(7) == 3);
    assert(get_change(pow(10, 3)) == 100);
}

double get_optimal_value(double capacity, vector<double> weights, vector<double> values) {
    double value = 0.0;
    vector<double> ratio(weights.size());
    std::map<int, double> mapOrder;
    for (size_t i = 0; i < weights.size(); i++)
    {
        mapOrder[i] = (values[i] / weights[i]);
    }
    typedef std::function<bool(std::pair<int, double>, std::pair<int, double>)> Comparator;

    Comparator compFunctor = [](std::pair<int, double> elem1, std::pair<int, double> elem2)
    {
        return elem1.second > elem2.second;
    };

    std::set<std::pair<int, double>, Comparator> setPcks(
        mapOrder.begin(), mapOrder.end(), compFunctor);

    for (std::pair<int, double> element : setPcks)
    {
        if (capacity == 0)
            return value;
        double a = std::min(weights[element.first], capacity);
        value = value + a * (element.second);
        weights[element.first] -= a;
        capacity -= a;
    }
    return value;
}

long long max_dot_product(vector<int> a, vector<int> b) {

    std::sort(a.begin(), a.end(), std::greater<double>());
    std::sort(b.begin(), b.end(), std::greater<double>());
    long long result = 0;
    for (size_t i = 0; i < a.size(); i++) {
        result += ((long long)a[i]) * b[i];
    }
    return result;
}

struct Segment {
    int start, end;
};

bool compareByStart(const Segment& a, const Segment& b)
{
    return a.end < b.end;
}

vector<int> optimal_points(vector<Segment>& segments)
{
    int n = 0;
    vector<int> points;
    std::sort(segments.begin(), segments.end(), compareByStart);

    while (n < segments.size()-1)
    {
        if (segments[n].end >= segments[n + 1].start)
        {
            if (segments[n].end >= segments[n + 1].end)
            {
                points.push_back(segments[n + 1].end);
            }
            else
            {
                points.push_back(segments[n].end);
            }
            while ((points.back() >= segments[n + 1].start) && (points.back() <= segments[n + 1].end))
            {
                n++;
                if (n >= segments.size() - 1)
                    return points;
            }
        }
        else
        {
            points.push_back(segments[n].end);
        }
        n++;
    }

    if (segments[n - 1].end >= segments[n].start)
    {
        if (segments[n - 1].end >= segments[n].end)
        {
            points.push_back(segments[n].end);
        }
        else
        {
            points.push_back(segments[n - 1].end);
        }
    }
    else
    {
        points.push_back(segments[n].end);
    }
    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}




