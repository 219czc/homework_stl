#include <iostream>
#include <set>
using namespace std;

class stu {
public:
    stu()
    {
        this->name = "\0";
        this->score = 0.0f;
    }
    stu(string name, float score = 0.0f)
    {
        this->name = name;
        this->score = score;
    }
    string name;
    float score;
};
struct MYSORT {
    bool operator()(const stu& a, const stu& b) const
    {
        return a.score > b.score;
    }
};

int main()
{
    set<stu, MYSORT> stuset;
    //    stuset.insert(stu("张三"));
    //    stuset.insert(stu("李四"));
    //    stuset.insert(stu("王五"));
    //    stuset.insert(stu("肖六"));
    //    stuset.insert(stu("赵琦"));
    //    stu st[] = { stu("张三"),stu("李四"), stu("王五"),
    //        stu("肖六"), stu("赵琦") };
    for (int i = 0; i < 5; i++) {
        cout << "第" << i +1<< "位选手上场，他的名字是：";
        string name;
        cin >> name;
        float score;
        set<float> scoreSet;

        cout << "现在请评委打分：" << endl;
        for (int j = 0; j < 5; j++) {
            cin >> score;
            scoreSet.insert(score);
        }
        score = 0.0f;
        scoreSet.erase(scoreSet.begin());
        scoreSet.erase(--scoreSet.end());
        for (auto it : scoreSet) {
            score += it;
        }
        score = score / scoreSet.size();
        stuset.insert(stu(name, score));
    }
    for (auto it : stuset) {
        cout << it.name << "  " << it.score << endl;
    }

    return 0;
}
