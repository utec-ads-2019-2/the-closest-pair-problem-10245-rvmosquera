#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef double numType;

numType distancebtw2points(pair<numType, numType> pointA, pair<numType, numType> pointB) {

    return sqrtl( pow(pointB.second - pointA.second, 2) + pow(pointB.first - pointA.first, 2) );
}

int main() {

    int n;
    numType x=0, y=0;
    numType minor=0.f;
    vector<pair<numType, numType>> nums;
    string input_line;

    while( scanf("%d", &n) == 1 ){
        if ( n == 0 )
            break;

        nums.clear();
        for(int i=0; i < n ; i++) {
            cin>>x; cin>>y;
            nums.push_back(make_pair(x, y));
        }

        if ( n == 1 )
            minor = distancebtw2points(nums.at(0), make_pair(0, 0) );
        else
            minor = distancebtw2points(nums.at(0), nums.at(1) );

        for( int k=0; k < nums.size() - 1 ; k++)
            for(int j=k ; j < nums.size() - 1 ; j++) {
                auto distance = distancebtw2points(nums.at(k), nums.at(j+1) );
                if ( distance < minor)
                    minor = distance;
            }

        if ( minor >= 10000 )
            printf(" \nINFINITY");
        else
            printf(" \n%4.4f", minor);
    }

    return 0;
}