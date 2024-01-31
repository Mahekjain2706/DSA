#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'minimumCost' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY red
 *  2. INTEGER_ARRAY blue
 *  3. INTEGER blueCost
 */
void minimum(int start,vector<int> &red,vector<int> &blue,int blueCost,vector<long> &ans,bool line){
    // base case
    if(start==red.size()) return;
    // recursive
    if(red[start]<=blue[start]){
        long val =ans[start-1]+red[start];
        ans.push_back(val);
        line = 0;
    }
    else{
        if(line==0){ ans.push_back(ans[start-1]+blue[start]+blueCost);
        line = 1;}
        else{
            ans.push_back(ans[start-1]+blue[start]);
        }
        
    }
    minimum(start+1,red,blue,blueCost,ans,line);
}
vector<long> minimumCost(vector<int> red, vector<int> blue, int blueCost) {
    vector<long> ans;
    if(red.size()!=blue.size()) return ans;
    ans.push_back(0);
    bool line = 0;
    minimum(0,red,blue,blueCost,ans,line);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string red_count_temp;
    getline(cin, red_count_temp);

    int red_count = stoi(ltrim(rtrim(red_count_temp)));

    vector<int> red(red_count);

    for (int i = 0; i < red_count; i++) {
        string red_item_temp;
        getline(cin, red_item_temp);

        int red_item = stoi(ltrim(rtrim(red_item_temp)));

        red[i] = red_item;
    }

    string blue_count_temp;
    getline(cin, blue_count_temp);

    int blue_count = stoi(ltrim(rtrim(blue_count_temp)));

    vector<int> blue(blue_count);

    for (int i = 0; i < blue_count; i++) {
        string blue_item_temp;
        getline(cin, blue_item_temp);

        int blue_item = stoi(ltrim(rtrim(blue_item_temp)));

        blue[i] = blue_item;
    }

    string blueCost_temp;
    getline(cin, blueCost_temp);

    int blueCost = stoi(ltrim(rtrim(blueCost_temp)));

    vector<long> result = minimumCost(red, blue, blueCost);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
