#include <fstream>
#include <iostream>

// The #include adds all the function declarations (a.k.a. prototypes) from the
// reviews.h file, which means the compiler knows about them when it is compiling
// the main function below (e.g. it can verify the parameter types and return types
// of the function declarations match the way those functions are used in main() ).
// However, the #include does not add the actual code for the functions, which is
// in reviews.cpp. This means you need to compile with a g++ command including both
// .cpp source files. For this project, we will being using some features from C++11,
// which requires an additional flag. Compile with this command:
//     g++ --std=c++11 evaluateReviews.cpp reviews.cpp -o evaluateReviews
#include "reviews.h"

using namespace std;

int main(){

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
    int highestScoreReview = 0;
    int lowestScoreReview = 0;

    // Declare string vectors
    
    vector<double> weights;
    vector<string> keywords;
    
    // Call readKeywordWeights

    readKeywordWeights(fin, keywords, weights);

    // Create and open sample_report.txt

    ofstream fout("sample_Report_One.txt");

    fout << "review score category" << endl;  // print header of file

    string filename_i = makeReviewFilename(0);

    ifstream rawFile_i(filename_i);
        if (!rawFile_i.is_open()){
        cout << "Error opening reviewXX.txt" << endl;
    }

    // Create string of processed words
    
    vector<string> reviewWords_i;

    readReview(rawFile_i, reviewWords_i);

    // Call review score

    double total_i = 0; 
    
    total_i = reviewScore(reviewWords_i, keywords, weights);
    
    fout << 0 << " " << total_i;
}



