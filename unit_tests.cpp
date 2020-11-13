#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>

#include "reviews.h"

using namespace std;

int main() {
    
    /*
    // Unit Tests for readKeywordWeights 
    
        // Read in the file

        ifstream fin("keywordWeights.txt");   // Tests if file is open

        if (!fin.is_open()){
            cout << "Error opening keywordWeights.txt" << endl;
        }

        vector<double> weights;
        vector<string> keywords;

        readKeywordWeights(fin, keywords, weights);

        cout << "Expected above. " << "results in: " << keywords[17] <<endl;
        cout << "Expected 0.78. " << "results in: " << weights[17] <<endl;
        cout << "Expected yuck. " << "results in: " << keywords[2338] <<endl;
        cout << "Expected 1.10. " << "results in: " << weights[2338] <<endl;


*/

// Tests for readReview

    // create fstream

    ifstream fin("review00.txt");   // Tests if file is open

        if (!fin.is_open()){
            cout << "Error opening review file" << endl;
        }
    vector<string> output;

    readReview(fin, output);

    for(int i = 0; i < output.size(); ++i){
        cout << output[i] << endl;  
    }
    

    // Some made up keywords/weights for testing purposes
    vector<string> keywords = {"snobby", "friendly", "expensive"};
    vector<double> weights = {-1.10, 0.29, -0.21};

    // A sample unit tests for the wordWeight function
    string testWord = "expensive";
    double correctWeight = -0.21;
    double actualWeight = wordWeight(testWord, keywords, weights);

    // An assertion will pass by with no problem if the given expression is true.
    // If the expression is false, however, the assertion reports a test failure!

    //cout << actualWeight << endl;

    // Here's a more concise way we could write another test for wordWeight

    assert(wordWeight("friendly", keywords, weights) == 0.29);
    assert(wordWeight("snobby", keywords, weights) == -1.10);
    assert(wordWeight("expensive", keywords, weights) == -0.21);
    assert(wordWeight("the", keywords, weights) == 0);
    
    // And here's a test for the reviewScore function.
    // (The review is "They were snobby, yet friendly!" but its split
    //into separate words as a vector for the test.)

    vector<string> testReview = {"They", "were", "snobby,", "yet", "friendly!"};

    assert(reviewScore(testReview, keywords, weights) == -0.81);




    // If we get to the bottom of main, that means no assertions failed and
    // that we passed all the tests. Nice!
    cout << "Tests PASS" << endl;


}



