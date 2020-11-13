#include <fstream>
#include <iostream>

#include "reviews.h"

using namespace std;

int main() {

    string filename_i = makeReviewFilename(0);

    ifstream rawFile_i(filename_i);

    if (!rawFile_i.is_open()){
        cout << "Error opening reviewXX.txt" << endl;
    }

    vector<string> reviewWords_i;

    readReview(rawFile_i, reviewWords_i);

    for(int i = 0; i<reviewWords_i.size(); ++i){

        cout << reviewWords_i[i] << endl;
    }
    

}

