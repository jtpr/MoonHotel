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
    int highestScoreReview;
    int lowestScoreReview;

    // Declare string vectors
    
    vector<double> weights;
    vector<string> keywords;
    
    // Call readKeywordWeights

    readKeywordWeights(fin, keywords, weights);

    // Create and open sample_report.txt

    ofstream fout("sample_Report.txt");

    fout << "review score category" << endl;  // print header of file

    // Cycles through each file given and records data
    for(int i = 0; i < 99; ++i) {

        string filename_i = makeReviewFilename(i);

        ifstream rawFile_i(filename_i);

         if (!rawFile_i.is_open()){
            cout << "Error opening reviewXX.txt" << endl;
        }

        // Create string of processed words
        
        vector<string> reviewWords_i;

        readReview(rawFile_i, reviewWords_i);

        // Call review score

        double total_i = reviewScore(reviewWords_i, keywords, weights);
        
        fout << i << " " << total_i << " " << evaluateScore(total_i) << endl;
        
        // Count Reviews (i starts at 0 therefore i + 1 = total number of files)
        numReviews = i + 1;  

        // Check if true false or neither

        if (total_i > 3) {
            
            ++numTrue;
            
        }   
        
        if (total_i < -3) {
            
            ++numFalse;
            
        }

        else {
            
            ++numUndetermined;

        }
        
        // Check highest and lowest score

        if (total_i > highestScore) {

            highestScore = total_i;
            highestScoreReview = i;
        
        }
    
        if (total_i < lowestScore) {

            lowestScore = total_i;
            highestScoreReview = i;
        }
    }
 
    // Display statistics

    fout << endl;
    fout << "Number of reviews: " << numReviews + 1 << endl;
    fout << "Number of truthful reviews: " << numTrue << endl;
    fout << "Number of deceptive reviews: " << numFalse << endl;
    fout << "Number of uncategorized reviews: " << numUndetermined << endl;
    fout << endl;
    fout << "Review with highest score: " << highestScoreReview << endl;
    fout << "Review with lowest score: " << lowestScoreReview << endl;
    
}



