#include <fstream>
#include <iostream>

#include "reviews.h"

using namespace std;

int main() {

    // Check if file is properly opened

   ifstream fin("keywordWeights.txt");

        if (!fin.is_open()){
            cout << "Error opening keywordWeights.txt" << endl;
        }
   
    // Declare global variables used for statistics

    int numReviews = 0;
    int numTrue = 0;
    int numFalse = 0;
    int numUndetermined = 0;
    double highestScore = 0;
    double lowestScore = 0; 
    int highestScoreReview;
    int lowestScoreReview;

    // Declare string vectors
    
    vector<double> weights;
    vector<string> keywords;
    
    // Call readKeywordWeights

    readKeywordWeights(fin, keywords, weights);

    string filename_i = makeReviewFilename(0);

    ifstream rawFile_i(filename_i);

    if (!rawFile_i.is_open()){
        cout << "Error opening reviewXX.txt" << endl;
    }

    vector<string> reviewWords_i;

    readReview(rawFile_i, reviewWords_i);
    
    double total = 0;
    
    vector<string> copyReview_i = reviewWords_i;

    preprocessReview(copyReview_i);


    for (int i = 0; i < copyReview_i.size(); ++i){

        string word = copyReview_i[i];
        total = total + wordWeight(word, keywords, weights);

        cout << word << " " <<total << endl;
    }


}

