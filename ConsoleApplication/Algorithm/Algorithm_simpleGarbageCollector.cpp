#include <vector>
#include <algorithm>
#include <locale>
#include <iostream>
#include <memory>
#include <stack>
#include <list>
#include <vector>
#include <functional> // to use std::greater<>()

class KTest;
typedef std::shared_ptr<KTest>  KTestPtr;
typedef std::weak_ptr<KTest>    KTestWeakPtr;

class KTest
{
private:
    KTest(int iData_){ iData = iData_;  }

public:
    static KTestPtr Create(int iData_)
    {
        KTestPtr    sp;
        sp.reset(new KTest(iData_));
        return sp;
    }

    int iData;
};

typedef std::shared_ptr<KTest>  KTestPtr;
typedef std::weak_ptr<KTest>    KTestWeakPtr;

void main() {
    std::vector<KTestPtr>   manager;

    //KTest* pt;
    //pt = new KTest(1); // need to prevent direct creation --> use factory

    for (int i = 0; i < 5; ++i) {
        manager.push_back( KTest::Create(i));
    }

    KTestWeakPtr    wpTest;
    wpTest = manager[2];
    KTestPtr        spTest;
    spTest = wpTest.lock();

    for (KTestPtr& sp : manager) {
        printf("%i, ", sp.use_count());
    }
}
