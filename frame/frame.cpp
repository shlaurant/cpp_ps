#include <string>
#include <vector>

using std::string;
using std::vector;
using std::max;

string::size_type widthOf(const vector<string>& vec){
    string::size_type result = 0;

    for(vector<string>::size_type i = 0; i != vec.size(); ++i){
        result = max(result, vec[i].size());
    }

    return result;
}

vector<string> createFrame(const vector<string>& vec){
    vector<string> result;
    const string border(widthOf(vec), '*');

    result.push_back(border);
    for(std::vector<string>::size_type i = 0; i < vec.size(); ++i){
        result.push_back("* " + vec[i] + string(widthOf(vec) - vec[i].size(), ' ') + " *");
    }

    result.push_back(border);

    return result;
}
